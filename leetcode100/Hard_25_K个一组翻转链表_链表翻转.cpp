/*
LeetCode 25. K 个一组翻转链表（Hard）

手撕思路：
1. 链表翻转题最怕头节点变化，先加 dummy。
2. 每次从 groupPrev 后面找够 k 个节点：
   - 找不到 k 个，剩下的保持原样。
   - 找到 k 个，就把这一段 [groupPrev->next, kth] 原地翻转。
3. 翻转时要提前记住 groupNext，也就是下一组的头。
4. 翻转完后，原来的组头变成组尾，作为下一轮的 groupPrev。

复杂度：时间 O(n)，空间 O(1)。
*/
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0, head);
        ListNode* groupPrev = &dummy;

        while (true) {
            ListNode* kth = getKth(groupPrev, k);
            if (kth == nullptr) break;

            ListNode* groupNext = kth->next;
            ListNode* prev = groupNext;
            ListNode* cur = groupPrev->next;

            // 把当前这一组翻转，直到 cur 走到下一组开头。
            while (cur != groupNext) {
                ListNode* nextNode = cur->next;
                cur->next = prev;
                prev = cur;
                cur = nextNode;
            }

            // 翻转前的组头，现在变成组尾。
            ListNode* oldHead = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = oldHead;
        }

        return dummy.next;
    }

private:
    ListNode* getKth(ListNode* cur, int k) {
        while (cur != nullptr && k > 0) {
            cur = cur->next;
            k--;
        }
        return cur;
    }
};
