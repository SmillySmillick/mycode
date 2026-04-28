/*
LeetCode 19. 删除链表的倒数第 N 个结点（Medium）
手撕思路：快慢指针。快指针先走 n 步，然后快慢一起走；快到末尾时，慢就在待删节点前一个位置。dummy 处理删除头节点。
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0, head);
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;
        while (n--) fast = fast->next;
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dummy.next;
    }
};
