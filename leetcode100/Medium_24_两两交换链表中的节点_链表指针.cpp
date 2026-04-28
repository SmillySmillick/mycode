/*
LeetCode 24. 两两交换链表中的节点（Medium）
手撕思路：dummy 后每次取两个节点 a、b，把 prev->a->b->next 改成 prev->b->a->next，然后 prev 移到 a。
复杂度：时间 O(n)，空间 O(1)。
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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0, head);
        ListNode* prev = &dummy;
        while (prev->next && prev->next->next) {
            ListNode* a = prev->next;
            ListNode* b = a->next;
            a->next = b->next;
            b->next = a;
            prev->next = b;
            prev = a;
        }
        return dummy.next;
    }
};
