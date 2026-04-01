#include <iostream>
#include <vector>
#include <algorithm>
#include <queue> 

struct Interval {
    long long a, b; 
    int original_index; // 输入顺序
};

bool compareIntervals(const Interval& i1, const Interval& i2) {
    if (i1.a != i2.a) {
        return i1.a < i2.a;
    }
    // 先到先得
    return i1.original_index < i2.original_index;
}

// 只关心a和b
std::vector<int> calculate_max_ideas_for_all_k(int max_total_slots_n, const std::vector<Interval>& ideas) {
    std::vector<int> f(max_total_slots_n + 1, 0);

    if (ideas.empty()) {
        return f;
    }

    std::vector<Interval> sorted_ideas = ideas;
    std::sort(sorted_ideas.begin(), sorted_ideas.end(), compareIntervals); 

    std::priority_queue<long long, std::vector<long long>, std::greater<long long>> pq_finish_times;

    int current_ideas_count = 0;

    for (const auto& idea : sorted_ideas) {
        while (!pq_finish_times.empty() && pq_finish_times.top() <= idea.a) {
            pq_finish_times.pop();
            current_ideas_count--;
        }
        pq_finish_times.push(idea.b);
        current_ideas_count++;

        int k_actual_machines_used = pq_finish_times.size();
        if (k_actual_machines_used <= max_total_slots_n) {
            f[k_actual_machines_used] = std::max(f[k_actual_machines_used], current_ideas_count);
        }
    }

    for (int k = 1; k <= max_total_slots_n; ++k) {
        f[k] = std::max(f[k], f[k-1]);
    }
    return f;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m1, m2;
    std::cin >> n >> m1 >> m2;

    std::vector<Interval> ideas1(m1);
    for (int i = 0; i < m1; ++i) {
        std::cin >> ideas1[i].a >> ideas1[i].b;
        ideas1[i].original_index = i; // 记录原始输入
    }

    std::vector<Interval> ideas2(m2);
    for (int i = 0; i < m2; ++i) {
        std::cin >> ideas2[i].a >> ideas2[i].b;
        ideas2[i].original_index = i; // 记录原始输入
    }

    std::vector<int> f_excellent = calculate_max_ideas_for_all_k(n, ideas1);
    std::vector<int> f_normal = calculate_max_ideas_for_all_k(n, ideas2);

    long long max_total_ideas = 0;

    for (int x = 0; x <= n; ++x) {
        long long current_total_ideas = (long long)f_excellent[x] + f_normal[n - x];
        max_total_ideas = std::max(max_total_ideas, current_total_ideas);
    }

    std::cout << max_total_ideas << std::endl;

    return 0;
}