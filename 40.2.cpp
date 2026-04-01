#include <cstdio>
#include <cstring>

int f_table[8][8];
int perm[512];
int tmp[512];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    int keys[1000];
    for (int i = 0; i < m; i++) {
        scanf("%d", &keys[i]);
    }

    // 预计算 f(x, k) = ((x^2 + k^2) mod 8) ^ k
    for (int x = 0; x < 8; x++)
        for (int k = 0; k < 8; k++)
            f_table[x][k] = ((x * x + k * k) % 8) ^ k;

    // 初始为恒等映射
    for (int i = 0; i < 512; i++) perm[i] = i;

    // 从 k_m 到 k_1 依次应用 g 的逆变换
    for (int i = m - 1; i >= 0; i--) {
        int k = keys[i];
        for (int v = 0; v < 512; v++) {
            int val = perm[v];
            int p = (val >> 6) & 7; // 高3位
            int q = (val >> 3) & 7; // 中3位
            int r = val & 7;        // 低3位

            // g 的逆：(p, q, r) -> (a, b, c)
            int b = p;
            int c = q ^ f_table[p][k];
            int a = r ^ f_table[c][k];

            tmp[v] = (a << 6) | (b << 3) | c;
        }
        memcpy(perm, tmp, sizeof(perm));
    }

    // 查表输出
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        if (i) putchar(' ');
        printf("%d", perm[a]);
    }
    putchar('\n');

    return 0;
}
