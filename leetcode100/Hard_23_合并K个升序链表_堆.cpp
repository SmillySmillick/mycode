/*
LeetCode 23. 合并 K 个升序链表（Hard）

手撕思路：
1. K 个链表都已经有序，最自然的做法是每次取所有链表头中最小的节点。
2. 用小根堆保存当前每条链表的头节点。
3. 每弹出一个最小节点，就把它接到答案链表后面；如果它还有 next，把 next 入堆。
4. 直到堆空，所有节点都接完。

复杂度：N 是总节点数，K 是链表条数。
时间 O(N log K)，空间 O(K)。
*/
#include <vector>
#include <queue>
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val; // priority_queue 默认大根堆，这里反过来变小根堆。
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> heap(cmp);

        for (ListNode* head : lists) {
            if (head != nullptr) heap.push(head);
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!heap.empty()) {
            ListNode* cur = heap.top();
            heap.pop();

            tail->next = cur;
            tail = tail->next;

            if (cur->next != nullptr) {
                heap.push(cur->next);
            }
        }

        return dummy.next;
    }
};
