/*
如果两个链表有交点,则两个链表的最后一个节点是相同的,则两个链表的最后一个节点到交点的距离是相同的
则两个链表的第一个节点到交点的距离是相同的
则两个链表的第一个节点到交点的距离是相同的
*/
#include <iostream>
using namespace std;
 struct ListNode {
         int val;
         ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
     };
class Solution {
    public:
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            if (!headA || !headB) return nullptr;
    
            ListNode *pA = headA;
            ListNode *pB = headB;
    
            // 两指针同速前进，到末尾后切换到对方链表头
            // 若有交点：走 a+c+b 步后相遇
            // 若无交点：走 a+b 步后同时为 nullptr
            while (pA != pB) {
                pA = (pA == nullptr) ? headB : pA->next;
                pB = (pB == nullptr) ? headA : pB->next;
            }
    
            return pA; // 有交点返回交点，无交点返回 nullptr
        }
    };