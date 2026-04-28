/*
LeetCode 2. 两数相加（Medium）
手撕思路：两个链表从低位到高位存数字，边走边加，维护进位 carry。谁没走完就继续取，最后 carry 不为 0 再补一个节点。
复杂度：时间 O(max(m,n))，空间 O(max(m,n))。
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        int carry = 0;
        while (l1 || l2 || carry) {
            int sum = carry;
            if (l1) { sum += l1->val; l1 = l1->next; }
            if (l2) { sum += l2->val; l2 = l2->next; }
            tail->next = new ListNode(sum % 10);
            tail = tail->next;
            carry = sum / 10;
        }
        return dummy.next;
    }
};
