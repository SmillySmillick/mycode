#include <map>
#include <vector>
#include <iostream>
void quickSort(std::vector<int>& nums) {
    if (nums.size() <= 1) {
        return;
    }

    std::map<int, int> freq;
    for (int num : nums) {
        freq[num]++;
    }

    int index = 0;
    for (const auto& pair : freq) {
        for (int i = 0; i < pair.second; i++) {
            nums[index++] = pair.first;
        }
    }
}
int main(){
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    quickSort(nums);
    for (int num : nums) {
        std::cout << num << " ";
    }
    return 0;
}
