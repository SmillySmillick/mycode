/*
LeetCode 146. LRU 缓存（Medium）
手撕思路：哈希表负责 O(1) 找节点，双向链表负责 O(1) 调整最近使用顺序。头部最新，尾部最旧。
复杂度：get/put 都是 O(1)。
*/
#include <unordered_map>
using namespace std;
class LRUCache {
    struct Node {
        int key, val;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };
public:
    LRUCache(int capacity) : cap(capacity) {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    int get(int key) {
        if (!mp.count(key)) return -1;
        Node* node = mp[key];
        moveToHead(node);
        return node->val;
    }
    void put(int key, int value) {
        if (mp.count(key)) {
            Node* node = mp[key];
            node->val = value;
            moveToHead(node);
            return;
        }
        Node* node = new Node(key, value);
        mp[key] = node;
        addAfterHead(node);
        if (mp.size() > cap) {
            Node* old = tail->prev;
            remove(old);
            mp.erase(old->key);
            delete old;
        }
    }
private:
    int cap;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> mp;
    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void addAfterHead(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
    void moveToHead(Node* node) {
        remove(node);
        addAfterHead(node);
    }
};
