#include <stdio.h>
#define MAXN 10001
#define MAXM 101
#define MAXS 1001

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    long long a[MAXN];
    int s[MAXM][MAXS], t[MAXM][MAXS];

    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    for (int i = 0; i < m; i++) {
        scanf("%d", &s[i][0]);
        for (int j = 1; j <= s[i][0]; j++)
            scanf("%d", &s[i][j]);
    }

    for (int i = 0; i < m; i++) {
        scanf("%d", &t[i][0]);
        for (int j = 1; j <= t[i][0]; j++)
            scanf("%d", &t[i][j]);
    }

    for (int i = 0; i < m; i++) {
        // 判断集合是否真正相等（直接比较元素，已严格递增）
        int equal = 1;
        if (s[i][0] != t[i][0]) {
            equal = 0;
        } else {
            for (int j = 1; j <= s[i][0]; j++) {
                if (s[i][j] != t[i][j]) { equal = 0; break; }
            }
        }

        // 计算 f(S) 和 f(T)
        long long fs = 0, ft = 0;
        for (int j = 1; j <= s[i][0]; j++) fs ^= a[s[i][j] - 1];
        for (int j = 1; j <= t[i][0]; j++) ft ^= a[t[i][j] - 1];

        int xor_equal = (fs == ft);

        // 两种判断结果一致 → correct，否则 → wrong
        if (equal == xor_equal)
            printf("correct\n");
        else
            printf("wrong\n");
    }

    return 0;
}
