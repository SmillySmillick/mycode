from pathlib import Path
import textwrap
import fitz


ROOT = Path(r"D:\mycode")
OUT_DIR = ROOT / "output" / "pdf"
OUT_DIR.mkdir(parents=True, exist_ok=True)
PDF_PATH = OUT_DIR / "华为_PDD_面试手撕算法与数据结构模板.pdf"

FONT_CN = r"C:\Windows\Fonts\simsun.ttc"
FONT_BOLD = r"C:\Windows\Fonts\simhei.ttf"
FONT_CODE = r"C:\Windows\Fonts\consola.ttf"


def read_text(path: str) -> str:
    p = Path(path)
    if not p.exists():
        return ""
    return p.read_text(encoding="utf-8", errors="ignore").strip()


HUAWEI_REQ = read_text(r"D:\job\华为.txt")
PDD_REQ = read_text(r"D:\job\拼多多.txt")


sections = [
    ("title", "华为 / PDD 实习面试手撕算法与数据结构模板"),
    ("p", "定位：针对 D:/job 中华为“通用软件开发工程师”和拼多多研发岗位要求整理。目标不是泛泛刷题，而是在面试中能快速讲清思路、写出可运行代码、说明复杂度和工程边界。"),
    ("h1", "一、企业需求拆解"),
    ("h2", "1. 华为：通用软件开发工程师"),
    ("p", "岗位关键词：需求分析、方案设计、代码开发、静态检查、单元测试、本地构建、测试环境、集成测试、问题定位、组件重构、代码质量、AI 应用。"),
    ("ul", [
        "算法侧重点：基础数据结构必须稳，链表、栈队列、树、堆、哈希、二分、DFS/BFS、DP 都应能手写。",
        "工程侧重点：代码边界清晰、命名稳定、复杂度可解释、能主动补充测试用例。",
        "回答风格：先说方案，再说边界，再写代码，最后说明如何测试和如何扩展。"
    ]),
    ("h2", "2. PDD：研发 / 后端方向"),
    ("p", "岗位关键词：基础和业务架构、高并发、高流量、分布式、高可用、高可靠、高扩展、数据库、强算法能力。"),
    ("ul", [
        "算法侧重点：数组/哈希/堆/排序/二分/贪心/DP/图算法要快，复杂度要敏感。",
        "系统侧重点：高并发下的数据结构选择、缓存淘汰、TopK、限流、去重、任务调度、数据库索引意识。",
        "回答风格：优先给出最优或接近最优复杂度，并主动讲内存、极端输入、并发场景下的扩展。"
    ]),
    ("h2", "3. 两家公司共同高频能力"),
    ("ul", [
        "手撕代码：C++ STL 熟练，但核心逻辑不能只依赖库函数。",
        "复杂度：每题都要能给出时间和空间复杂度。",
        "鲁棒性：空输入、越界、重复元素、负数、大数、链表头变化都要提前处理。",
        "项目结合：可以把 RAG、联邦学习/CSD、NoneBot 项目和算法结构联系起来，如 TopK、缓存、检索排序、图搜索、并发队列。"
    ]),
    ("h1", "二、面试手撕通用流程"),
    ("ol", [
        "复述题意：确认输入输出、数据范围、是否有重复、是否有序、能否修改原数组。",
        "选模型：数组用双指针/二分/前缀和；动态区间用线段树/树状数组；最短依赖用 BFS/拓扑；最优子结构用 DP。",
        "写核心不变量：例如窗口内满足什么，栈中元素为何单调，dp[i] 表示什么。",
        "写代码：先处理边界，再写主逻辑，避免边写边改状态定义。",
        "自测：空、单个、全相同、有重复、极大值、反例。"
    ]),
    ("h1", "三、必须熟练的基础模板"),
    ("h2", "1. 二分查找：有序数组 / 答案空间"),
    ("p", "适用：搜索插入位置、旋转数组、查找左右边界、最小可行答案。PDD 面试常追问为什么不会死循环。"),
    ("code", r'''// lower_bound: first index i with a[i] >= target
int lowerBound(vector<int>& a, int target) {
    int l = 0, r = (int)a.size();
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (a[mid] >= target) r = mid;
        else l = mid + 1;
    }
    return l;
}

// binary answer: find minimum x satisfying check(x)
int minAnswer(int l, int r) {
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    return l;
}'''),
    ("h2", "2. 双指针：原地处理 / 有序数组 / 链表"),
    ("code", r'''// LeetCode 283. Move Zeroes
void moveZeroes(vector<int>& nums) {
    int slow = 0;
    for (int fast = 0; fast < (int)nums.size(); fast++) {
        if (nums[fast] != 0) swap(nums[slow++], nums[fast]);
    }
}

// LeetCode 15. 3Sum
vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (i && nums[i] == nums[i - 1]) continue;
        int l = i + 1, r = n - 1;
        while (l < r) {
            long long s = 1LL * nums[i] + nums[l] + nums[r];
            if (s == 0) {
                ans.push_back({nums[i], nums[l], nums[r]});
                while (l < r && nums[l] == nums[l + 1]) l++;
                while (l < r && nums[r] == nums[r - 1]) r--;
                l++; r--;
            } else if (s < 0) l++;
            else r--;
        }
    }
    return ans;
}'''),
    ("h2", "3. 滑动窗口：最长 / 最短连续子串"),
    ("p", "不变量：窗口 [l, r] 内维护当前合法性。最长题通常不合法时收缩；最短题通常合法时收缩并更新答案。"),
    ("code", r'''// LeetCode 3. Longest Substring Without Repeating Characters
int lengthOfLongestSubstring(string s) {
    vector<int> cnt(256, 0);
    int ans = 0, l = 0;
    for (int r = 0; r < (int)s.size(); r++) {
        cnt[(unsigned char)s[r]]++;
        while (cnt[(unsigned char)s[r]] > 1) {
            cnt[(unsigned char)s[l++]]--;
        }
        ans = max(ans, r - l + 1);
    }
    return ans;
}'''),
    ("h2", "4. 前缀和 + 哈希：子数组计数"),
    ("code", r'''// LeetCode 560. Subarray Sum Equals K
int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    freq[0] = 1;
    int pre = 0, ans = 0;
    for (int x : nums) {
        pre += x;
        if (freq.count(pre - k)) ans += freq[pre - k];
        freq[pre]++;
    }
    return ans;
}'''),
    ("h2", "5. 单调栈：下一个更大 / 柱状图面积"),
    ("code", r'''// LeetCode 739. Daily Temperatures
vector<int> dailyTemperatures(vector<int>& t) {
    int n = t.size();
    vector<int> ans(n);
    stack<int> st; // decreasing temperature indices
    for (int i = 0; i < n; i++) {
        while (!st.empty() && t[i] > t[st.top()]) {
            int j = st.top(); st.pop();
            ans[j] = i - j;
        }
        st.push(i);
    }
    return ans;
}

// LeetCode 84. Largest Rectangle in Histogram
int largestRectangleArea(vector<int>& h) {
    h.push_back(0);
    stack<int> st;
    int ans = 0;
    for (int i = 0; i < (int)h.size(); i++) {
        while (!st.empty() && h[st.top()] >= h[i]) {
            int height = h[st.top()]; st.pop();
            int left = st.empty() ? -1 : st.top();
            ans = max(ans, height * (i - left - 1));
        }
        st.push(i);
    }
    h.pop_back();
    return ans;
}'''),
    ("h2", "6. 单调队列：滑动窗口最大值"),
    ("code", r'''// LeetCode 239. Sliding Window Maximum
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> q; // indices, values decreasing
    vector<int> ans;
    for (int i = 0; i < (int)nums.size(); i++) {
        while (!q.empty() && q.front() <= i - k) q.pop_front();
        while (!q.empty() && nums[q.back()] <= nums[i]) q.pop_back();
        q.push_back(i);
        if (i >= k - 1) ans.push_back(nums[q.front()]);
    }
    return ans;
}'''),
    ("h2", "7. 堆：TopK / 数据流中位数"),
    ("code", r'''// LeetCode 215. Kth Largest
int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int x : nums) {
        pq.push(x);
        if ((int)pq.size() > k) pq.pop();
    }
    return pq.top();
}

class MedianFinder {
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> large;
public:
    void addNum(int num) {
        small.push(num);
        large.push(small.top()); small.pop();
        if (large.size() > small.size()) {
            small.push(large.top()); large.pop();
        }
    }
    double findMedian() {
        if (small.size() > large.size()) return small.top();
        return ((long long)small.top() + large.top()) / 2.0;
    }
};'''),
    ("h2", "8. 链表：反转、找中点、合并"),
    ("code", r'''struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x = 0) : val(x), next(nullptr) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode *pre = nullptr, *cur = head;
    while (cur) {
        ListNode* nxt = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;
    }
    return pre;
}

ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
    ListNode dummy(0), *tail = &dummy;
    while (a && b) {
        if (a->val <= b->val) tail->next = a, a = a->next;
        else tail->next = b, b = b->next;
        tail = tail->next;
    }
    tail->next = a ? a : b;
    return dummy.next;
}'''),
    ("h2", "9. 二叉树递归：返回值和全局答案分离"),
    ("code", r'''struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x = 0) : val(x), left(nullptr), right(nullptr) {}
};

// LeetCode 543. Diameter of Binary Tree
class Solution {
    int ans = 0;
    int depth(TreeNode* root) {
        if (!root) return 0;
        int l = depth(root->left);
        int r = depth(root->right);
        ans = max(ans, l + r);
        return max(l, r) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return ans;
    }
};'''),
    ("h1", "四、DP 重点模板"),
    ("h2", "1. 线性 DP"),
    ("p", "面试表达：dp[i] 的含义必须能一句话说清楚；转移必须只依赖已经计算出的状态。"),
    ("code", r'''// LeetCode 198. House Robber
int rob(vector<int>& nums) {
    int pre2 = 0, pre1 = 0;
    for (int x : nums) {
        int cur = max(pre1, pre2 + x);
        pre2 = pre1;
        pre1 = cur;
    }
    return pre1;
}

// LeetCode 53. Maximum Subarray
int maxSubArray(vector<int>& nums) {
    int cur = nums[0], ans = nums[0];
    for (int i = 1; i < (int)nums.size(); i++) {
        cur = max(nums[i], cur + nums[i]);
        ans = max(ans, cur);
    }
    return ans;
}'''),
    ("h2", "2. 二维 DP：LCS / 编辑距离"),
    ("code", r'''int longestCommonSubsequence(string a, string b) {
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}

int minDistance(string a, string b) {
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 0; i <= n; i++) dp[i][0] = i;
    for (int j = 0; j <= m; j++) dp[0][j] = j;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
        }
    }
    return dp[n][m];
}'''),
    ("h2", "3. 01 背包 / 完全背包"),
    ("code", r'''// 01 knapsack feasibility
bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum & 1) return false;
    int target = sum / 2;
    vector<char> dp(target + 1, false);
    dp[0] = true;
    for (int x : nums) {
        for (int j = target; j >= x; j--) {
            dp[j] = dp[j] || dp[j - x];
        }
    }
    return dp[target];
}

// Complete knapsack: LeetCode 322. Coin Change
int coinChange(vector<int>& coins, int amount) {
    const int INF = 1e9;
    vector<int> dp(amount + 1, INF);
    dp[0] = 0;
    for (int c : coins) {
        for (int j = c; j <= amount; j++) {
            dp[j] = min(dp[j], dp[j - c] + 1);
        }
    }
    return dp[amount] == INF ? -1 : dp[amount];
}'''),
    ("h2", "4. 树形 DP"),
    ("code", r'''// LeetCode 337. House Robber III
pair<int, int> dfs(TreeNode* root) {
    if (!root) return {0, 0}; // {not rob, rob}
    auto l = dfs(root->left);
    auto r = dfs(root->right);
    int rob = root->val + l.first + r.first;
    int notRob = max(l.first, l.second) + max(r.first, r.second);
    return {notRob, rob};
}

int rob(TreeNode* root) {
    auto res = dfs(root);
    return max(res.first, res.second);
}'''),
    ("h1", "五、贪心重点模板"),
    ("p", "贪心必须讲证明。常用证明：交换论证、覆盖范围、排序后局部最优。"),
    ("code", r'''// LeetCode 55. Jump Game
bool canJump(vector<int>& nums) {
    int farthest = 0;
    for (int i = 0; i < (int)nums.size(); i++) {
        if (i > farthest) return false;
        farthest = max(farthest, i + nums[i]);
    }
    return true;
}

// LeetCode 45. Jump Game II
int jump(vector<int>& nums) {
    int steps = 0, end = 0, farthest = 0;
    for (int i = 0; i + 1 < (int)nums.size(); i++) {
        farthest = max(farthest, i + nums[i]);
        if (i == end) {
            steps++;
            end = farthest;
        }
    }
    return steps;
}

// LeetCode 763. Partition Labels
vector<int> partitionLabels(string s) {
    vector<int> last(26);
    for (int i = 0; i < (int)s.size(); i++) last[s[i] - 'a'] = i;
    vector<int> ans;
    int start = 0, end = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        end = max(end, last[s[i] - 'a']);
        if (i == end) {
            ans.push_back(end - start + 1);
            start = i + 1;
        }
    }
    return ans;
}'''),
    ("h1", "六、PDD 加分：高并发/业务常见数据结构"),
    ("h2", "1. LRU 缓存"),
    ("p", "业务含义：缓存淘汰、热点数据、数据库读压力降低。PDD 常关注 O(1) get/put。"),
    ("code", r'''class LRUCache {
    struct Node {
        int key, val;
        Node *prev, *next;
        Node(int k = 0, int v = 0) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };
    int cap;
    unordered_map<int, Node*> mp;
    Node *head, *tail;

    void remove(Node* x) {
        x->prev->next = x->next;
        x->next->prev = x->prev;
    }
    void addFront(Node* x) {
        x->next = head->next;
        x->prev = head;
        head->next->prev = x;
        head->next = x;
    }
public:
    LRUCache(int capacity) : cap(capacity) {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }
    int get(int key) {
        if (!mp.count(key)) return -1;
        Node* x = mp[key];
        remove(x); addFront(x);
        return x->val;
    }
    void put(int key, int value) {
        if (mp.count(key)) {
            Node* x = mp[key];
            x->val = value;
            remove(x); addFront(x);
            return;
        }
        if ((int)mp.size() == cap) {
            Node* old = tail->prev;
            remove(old);
            mp.erase(old->key);
            delete old;
        }
        Node* x = new Node(key, value);
        mp[key] = x;
        addFront(x);
    }
};'''),
    ("h2", "2. 并查集：连通性和分组"),
    ("code", r'''class DSU {
    vector<int> parent, sz;
public:
    DSU(int n) : parent(n), sz(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    bool unite(int a, int b) {
        int ra = find(a), rb = find(b);
        if (ra == rb) return false;
        if (sz[ra] < sz[rb]) swap(ra, rb);
        parent[rb] = ra;
        sz[ra] += sz[rb];
        return true;
    }
};'''),
    ("h2", "3. 拓扑排序：依赖调度"),
    ("code", r'''// LeetCode 207. Course Schedule
bool canFinish(int n, vector<vector<int>>& prerequisites) {
    vector<vector<int>> g(n);
    vector<int> indeg(n);
    for (auto& e : prerequisites) {
        g[e[1]].push_back(e[0]);
        indeg[e[0]]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++) if (indeg[i] == 0) q.push(i);
    int cnt = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        cnt++;
        for (int v : g[u]) {
            if (--indeg[v] == 0) q.push(v);
        }
    }
    return cnt == n;
}'''),
    ("h2", "4. Dijkstra：非负权最短路"),
    ("code", r'''vector<long long> dijkstra(int n, vector<vector<pair<int,int>>>& g, int s) {
    const long long INF = 4e18;
    vector<long long> dist(n, INF);
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
    dist[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d != dist[u]) continue;
        for (auto [v, w] : g[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}'''),
    ("h1", "七、华为 / ACM 加分：线段树与树状数组"),
    ("h2", "1. 树状数组：动态前缀和"),
    ("code", r'''class Fenwick {
    int n;
    vector<long long> bit;
public:
    Fenwick(int n) : n(n), bit(n + 1, 0) {}
    void add(int idx, long long delta) {
        for (; idx <= n; idx += idx & -idx) bit[idx] += delta;
    }
    long long sumPrefix(int idx) {
        long long res = 0;
        for (; idx > 0; idx -= idx & -idx) res += bit[idx];
        return res;
    }
    long long rangeSum(int l, int r) {
        return sumPrefix(r) - sumPrefix(l - 1);
    }
};'''),
    ("h2", "2. 懒标记线段树：区间加 + 区间和"),
    ("code", r'''class SegTree {
    int n;
    vector<long long> sum, lazy;

    void apply(int p, int l, int r, long long v) {
        sum[p] += (r - l + 1) * v;
        lazy[p] += v;
    }
    void pushDown(int p, int l, int r) {
        if (!lazy[p] || l == r) return;
        int m = (l + r) / 2;
        apply(p * 2, l, m, lazy[p]);
        apply(p * 2 + 1, m + 1, r, lazy[p]);
        lazy[p] = 0;
    }
    void pushUp(int p) {
        sum[p] = sum[p * 2] + sum[p * 2 + 1];
    }
    void build(int p, int l, int r, vector<int>& a) {
        if (l == r) {
            sum[p] = a[l - 1];
            return;
        }
        int m = (l + r) / 2;
        build(p * 2, l, m, a);
        build(p * 2 + 1, m + 1, r, a);
        pushUp(p);
    }
    void add(int p, int l, int r, int ql, int qr, long long v) {
        if (ql <= l && r <= qr) {
            apply(p, l, r, v);
            return;
        }
        pushDown(p, l, r);
        int m = (l + r) / 2;
        if (ql <= m) add(p * 2, l, m, ql, qr, v);
        if (qr > m) add(p * 2 + 1, m + 1, r, ql, qr, v);
        pushUp(p);
    }
    long long query(int p, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return sum[p];
        pushDown(p, l, r);
        int m = (l + r) / 2;
        long long res = 0;
        if (ql <= m) res += query(p * 2, l, m, ql, qr);
        if (qr > m) res += query(p * 2 + 1, m + 1, r, ql, qr);
        return res;
    }
public:
    SegTree(vector<int>& a) {
        n = a.size();
        sum.assign(4 * n + 5, 0);
        lazy.assign(4 * n + 5, 0);
        build(1, 1, n, a);
    }
    void rangeAdd(int l, int r, long long v) { add(1, 1, n, l, r, v); }
    long long rangeQuery(int l, int r) { return query(1, 1, n, l, r); }
};'''),
    ("h1", "八、面试最后 10 分钟自查清单"),
    ("ul", [
        "代码能否处理空数组、单元素、重复元素、负数、极大值。",
        "复杂度是否达到岗位预期：PDD 尽量 O(n log n) 或 O(n)，华为要强调可维护和可测试。",
        "是否解释了核心不变量：窗口、单调栈、堆大小、dp 状态、线段树 lazy。",
        "是否能从项目迁移：RAG 中 TopK/检索排序，联邦学习中数据筛选，后端中 LRU/限流/队列。",
        "是否能说测试用例：正常样例、边界样例、反例、压力数据。"
    ]),
]


class PdfWriter:
    def __init__(self, path: Path):
        self.doc = fitz.open()
        self.path = path
        self.margin = 50
        self.width = 595
        self.height = 842
        self.y = self.margin
        self.page_no = 0
        self.page = None
        self.new_page()

    def new_page(self):
        if self.page:
            self.footer()
        self.page = self.doc.new_page(width=self.width, height=self.height)
        self.page.insert_font(fontname="CN", fontfile=FONT_CN)
        self.page.insert_font(fontname="BOLD", fontfile=FONT_BOLD)
        self.page.insert_font(fontname="CODE", fontfile=FONT_CODE)
        self.page_no += 1
        self.y = self.margin

    def footer(self):
        self.page.insert_text((self.width - self.margin - 40, self.height - 28), str(self.page_no),
                              fontname="CN", fontsize=9, color=(0.35, 0.35, 0.35))

    def ensure(self, h):
        if self.y + h > self.height - self.margin:
            self.new_page()

    def text(self, s, size=10.5, font="CN", leading=15, color=(0, 0, 0), indent=0):
        width_factor = 0.62 if font == "CODE" else 0.98
        max_chars = max(18, int((self.width - 2 * self.margin - indent) / (size * width_factor)))
        lines = []
        for part in str(s).splitlines() or [""]:
            if not part:
                lines.append("")
            elif font == "CODE":
                lines.extend(textwrap.wrap(part, width=max_chars, replace_whitespace=False,
                                           drop_whitespace=False) or [""])
            else:
                lines.extend(textwrap.wrap(part, width=max_chars, break_long_words=True,
                                           replace_whitespace=False) or [""])
        for line in lines:
            self.ensure(leading + 2)
            self.page.insert_text((self.margin + indent, self.y), line, fontname=font,
                                  fontsize=size, color=color)
            self.y += leading

    def heading(self, s, level):
        sizes = {1: 16, 2: 13, 3: 11.5}
        gaps = {1: 16, 2: 12, 3: 8}
        self.y += 4
        self.ensure(30)
        self.text(s, size=sizes[level], font="BOLD", leading=sizes[level] + 6)
        self.y += gaps[level] / 2

    def code(self, s):
        self.ensure(20)
        self.y += 3
        for line in s.splitlines():
            if self.y + 14 > self.height - self.margin:
                self.new_page()
            # light gray background for each code line
            self.page.draw_rect(fitz.Rect(self.margin - 4, self.y - 10, self.width - self.margin + 4, self.y + 4),
                                color=None, fill=(0.96, 0.96, 0.96))
            self.text(line, size=8.2, font="CODE", leading=11, indent=4)
        self.y += 8

    def save(self):
        self.footer()
        self.doc.save(self.path)
        self.doc.close()


def build_pdf():
    pdf = PdfWriter(PDF_PATH)
    for kind, content in sections:
        if kind == "title":
            pdf.text(content, size=21, font="BOLD", leading=28)
            pdf.y += 8
        elif kind == "h1":
            pdf.heading(content, 1)
        elif kind == "h2":
            pdf.heading(content, 2)
        elif kind == "p":
            pdf.text(content)
            pdf.y += 4
        elif kind == "ul":
            for item in content:
                pdf.text("- " + item, indent=8)
            pdf.y += 4
        elif kind == "ol":
            for i, item in enumerate(content, 1):
                pdf.text(f"{i}. {item}", indent=8)
            pdf.y += 4
        elif kind == "code":
            pdf.code(content)
    pdf.save()
    return PDF_PATH


if __name__ == "__main__":
    path = build_pdf()
    doc = fitz.open(path)
    print(path)
    print("pages", doc.page_count)
    print("size", path.stat().st_size)
    doc.close()
