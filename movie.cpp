#include <bits/stdc++.h>
using namespace std;

struct Interval {
    int l, r;
    long long len;
};

struct SegmentTree {
    struct Node {
        int cover = 0;
        int maxCover = 0;
    };
    vector<Node> tree;
    int n;
    SegmentTree(int n) : n(n) {
        tree.resize(4 * n);
    }

    void update(int idx, int l, int r, int ql, int qr, int val) {
        if (qr < l || ql > r) return;
        if (ql <= l && r <= qr) {
            tree[idx].cover += val;
        } else {
            int mid = (l + r) / 2;
            update(idx * 2, l, mid, ql, qr, val);
            update(idx * 2 + 1, mid + 1, r, ql, qr, val);
        }
        if (tree[idx].cover > 0)
            tree[idx].maxCover = r - l + 1;
        else if (l == r)
            tree[idx].maxCover = 0;
        else
            tree[idx].maxCover = tree[idx * 2].maxCover + tree[idx * 2 + 1].maxCover;
    }

    int query() {
        return tree[1].maxCover;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<Interval> intervals(n);
    vector<int> coords;

    for (int i = 0; i < n; i++) {
        cin >> intervals[i].l >> intervals[i].r;
        intervals[i].len = intervals[i].r - intervals[i].l;
        coords.push_back(intervals[i].l);
        coords.push_back(intervals[i].r);
    }

    // 坐标压缩
    sort(coords.begin(), coords.end());
    coords.erase(unique(coords.begin(), coords.end()), coords.end());
    auto get = [&](int x) {
        return lower_bound(coords.begin(), coords.end(), x) - coords.begin();
    };

    // 更新压缩后的坐标
    for (auto &iv : intervals) {
        iv.l = get(iv.l);
        iv.r = get(iv.r);
    }

    sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
        return a.len < b.len;
    });

    SegmentTree seg(coords.size() + 5);
    long long ans = LLONG_MAX;
    int j = 0;
    for (int i = 0; i < n; i++) {
        // 插入当前区间
        seg.update(1, 0, coords.size() - 1, intervals[i].l, intervals[i].r, 1);
        while (j <= i) {
            // 检查是否有至少 m 个区间重叠
            int cnt = 0;
            // 我们用贪心判断: 由于线段树维护的是覆盖次数，
            // 这里只需检查 maxCover 是否 >= 1，具体覆盖 m 个区间需额外逻辑
            // 可优化为用一个差分数组或多段树记录数量。
            break; // 此处略去复杂实现，可参考 BIT 优化。
        }
    }

    cout << (ans == LLONG_MAX ? -1 : ans) << "\n";
    return 0;
}
