#include <iostream>  
#include <vector>    
#include <algorithm> 
#include <utility>   

struct City {
    int importance;
    int original_index;
};


bool compareCities(const City& a, const City& b) {
    return a.importance > b.importance; // 降序排序
}

int main() {
    
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n; // 读取城市个数

    std::vector<City> cities(n); 
    for (int i = 0; i < n; ++i) {
        std::cin >> cities[i].importance; 
        cities[i].original_index = i;     
    }

 
    std::sort(cities.begin(), cities.end(), compareCities);

 
    std::vector<int> results(n);

   
    int current_bombing_rank = 1;
    int num_cities_with_current_importance = 0;

   
    for (int i = 0; i < n; ++i) {
        int importance_i = cities[i].importance;
        int original_index_i = cities[i].original_index;

        if (i == 0) {
            
            results[original_index_i] = 1;
            num_cities_with_current_importance = 1;
        } else {
            int importance_prev = cities[i-1].importance;
            if (importance_i == importance_prev) {
                
                results[original_index_i] = current_bombing_rank;
                num_cities_with_current_importance++;
            } else {
                
                current_bombing_rank += num_cities_with_current_importance;
                results[original_index_i] = current_bombing_rank;
                
                num_cities_with_current_importance = 1;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        std::cout << results[i] << (i == n - 1 ? "" : " "); 
    }
    std::cout << std::endl;

    return 0;
}

