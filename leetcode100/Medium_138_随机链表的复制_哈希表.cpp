/*
LeetCode 138. 随机链表的复制（Medium）
手撕思路：哈希表记录 old -> new。第一遍复制所有节点，第二遍补 next 和 random 指针。
复杂度：时间 O(n)，空间 O(n)。
*/
#include <unordered_map>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int _val) : val(_val), next(nullptr), random(nullptr) {}
};
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        unordered_map<Node*, Node*> mp;
        for (Node* cur = head; cur; cur = cur->next) {
            mp[cur] = new Node(cur->val);
        }
        for (Node* cur = head; cur; cur = cur->next) {
            mp[cur]->next = mp[cur->next];
            mp[cur]->random = mp[cur->random];
        }
        return mp[head];
    }
};
