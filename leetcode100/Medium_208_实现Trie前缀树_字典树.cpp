/*
LeetCode 208. 实现 Trie（前缀树）（Medium）
手撕思路：每个节点有 26 个儿子和一个 isEnd 标记。insert 沿字符建节点；search 要求最后 isEnd；startsWith 只要求路径存在。
复杂度：每个操作 O(L)。
*/
#include <vector>
#include <string>
using namespace std;
class Trie {
    struct Node {
        vector<Node*> child;
        bool isEnd;
        Node() : child(26, nullptr), isEnd(false) {}
    };
public:
    Trie() { root = new Node(); }
    void insert(string word) {
        Node* cur = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!cur->child[idx]) cur->child[idx] = new Node();
            cur = cur->child[idx];
        }
        cur->isEnd = true;
    }
    bool search(string word) {
        Node* node = find(word);
        return node && node->isEnd;
    }
    bool startsWith(string prefix) {
        return find(prefix) != nullptr;
    }
private:
    Node* root;
    Node* find(string& s) {
        Node* cur = root;
        for (char c : s) {
            int idx = c - 'a';
            if (!cur->child[idx]) return nullptr;
            cur = cur->child[idx];
        }
        return cur;
    }
};
