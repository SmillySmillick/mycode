#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    long long x, y;
} Point;

Point* points;
Point* strip_points;

int compareX(const void* a, const void* b) {
    Point* p1 = (Point*)a;
    Point* p2 = (Point*)b;
    if (p1->x != p2->x) {
        return (p1->x < p2->x) ? -1 : 1;
    }
    return (p1->y < p2->y) ? -1 : 1;
}

int compareY(const void* a, const void* b) {
    Point* p1 = (Point*)a;
    Point* p2 = (Point*)b;
    if (p1->y != p2->y) {
        return (p1->y < p2->y) ? -1 : 1;
    }
    return (p1->x < p2->x) ? -1 : 1;
}

long long distSq(Point p1, Point p2) {
    long long dx = p1.x - p2.x;
    long long dy = p1.y - p2.y;
    return dx * dx + dy * dy;
}

long long min(long long a, long long b) {
    return (a < b) ? a : b;
}

long long bruteForce(Point P[], int n) {
    long long min_d_sq = LLONG_MAX;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            min_d_sq = min(min_d_sq, distSq(P[i], P[j]));
        }
    }
    return min_d_sq;
}

long long closestPairDC(int start, int end) {
    int n = end - start + 1;

    if (n <= 3) {
        return bruteForce(&points[start], n);
    }

    int mid = start + (end - start) / 2;
    long long mid_x = points[mid].x;

    long long d_L_sq = closestPairDC(start, mid);
    long long d_R_sq = closestPairDC(mid + 1, end);

    long long min_d_sq = min(d_L_sq, d_R_sq);

    int strip_count = 0;
    for (int i = start; i <= end; ++i) {
        long long dx = points[i].x - mid_x;
        if (dx * dx < min_d_sq) {
            strip_points[strip_count++] = points[i];
        }
    }

    qsort(strip_points, strip_count, sizeof(Point), compareY);

    for (int i = 0; i < strip_count; ++i) {
        for (int j = i + 1; j < strip_count; ++j) {
            long long dy = strip_points[j].y - strip_points[i].y;
            if (dy * dy >= min_d_sq) {
                break;
            }
            min_d_sq = min(min_d_sq, distSq(strip_points[i], strip_points[j]));
        }
    }

    return min_d_sq;
}

int main() {
    int n;
    scanf("%d", &n);

    points = (Point*)malloc(n * sizeof(Point));
    if (points == NULL) {
        perror("Failed to allocate memory for points");
        return 1;
    }
    strip_points = (Point*)malloc(n * sizeof(Point));
    if (strip_points == NULL) {
        perror("Failed to allocate memory for strip_points");
        free(points);
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        scanf("%lld %lld", &points[i].x, &points[i].y);
    }

    qsort(points, n, sizeof(Point), compareX);

    long long result = closestPairDC(0, n - 1);

    printf("%lld\n", result);

    free(points);
    free(strip_points);

    return 0;
}
