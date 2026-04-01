#include <stdio.h>
#include <string.h>

// 构造 next 数组
void getNext(char *pattern, int next[]) {
    int i = 0, j = -1;
    int len = strlen(pattern);
    next[0] = -1;
    while (i < len - 1) {
        if (j == -1 || pattern[i] == pattern[j]) {
            i++;
            j++;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
}

// 判断 pattern 是否为 text 的子串（KMP算法）
int KMP_Search(char *text, char *pattern, int next[]) {
    int i = 0, j = 0;
    int n = strlen(text);
    int m = strlen(pattern);

    while (i < n && j < m) {
        if (j == -1 || text[i] == pattern[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
    }

    // 若 j == m，说明模式串完全匹配
    if (j == m)
        return i - j; // 返回匹配起始下标
    else
        return -1;    // 未匹配
}

int main() {
    char a[100], b[100];
    int next[100];

    printf("print a and b:\n");
    scanf("%s %s", a, b);

    getNext(a, next);

    printf("a: %s\n", a);
    printf("next*: ");
    for (int i = 0; i < strlen(a); i++) {
        printf("%d ", next[i]);
    }
    printf("\n");

    int pos = KMP_Search(b, a, next);

    if (pos != -1)
        printf("? \"%s\" is \"%s\"  %d start\n", a, b, pos);
    else
        printf("? \"%s\" not \"%s\" \n", a, b);

    return 0;
}
