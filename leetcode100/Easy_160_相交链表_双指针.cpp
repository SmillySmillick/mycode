/*
LeetCode 160. 相交链表（Easy）

手撕思路：
1. 两条链表如果相交，从交点到尾部是同一段节点。
2. 难点是两条链表交点前长度可能不同。
3. 用两个指针 pA、pB 同速走，走到尾部后切到另一条链表头。
4. 这样两个指针都走了 a+b+c 的距离；若相交，会在交点相遇；若不相交，会同时到 nullptr。

复杂度：时间 O(m+n)，空间 O(1)。
*/
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* pA = headA;
        ListNode* pB = headB;
        while (pA != pB) {
            pA = pA ? pA->next : headB;
            pB = pB ? pB->next : headA;
        }
        return pA;
    }
};
