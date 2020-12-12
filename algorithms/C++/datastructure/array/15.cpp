#include <iostream>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2020/12/12
 * @description: 15.3sum
 */
// 哈希法超时
vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int size = nums.size();
    vector<vector<int>> result;
    int ii = INT32_MIN;
    for (int i = 0; i < size - 2; i++) {
        if (ii == nums[i]) continue;
        ii = nums[i];
        unordered_set<int> m;
        int target = 0 - nums[i];
        int jj = INT32_MIN;
        for (int j = i + 1; j < size; j++) {
            auto temp = m.find(target - nums[j]);
            if (temp != m.end()) {
                if (jj == *temp) continue;
                jj = *temp;
                int a[] = {*temp, nums[j], nums[i]};
                result.emplace_back(a, a + 3);
            }
            m.insert(nums[j]);
        }
    }
    return result;
}

// 双指针
vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int size = nums.size();
    vector<vector<int>> result;
    int ii = INT32_MIN;
    for (int i = 0; i < size - 2; i++) {
        if (ii == nums[i]) continue;
        ii = nums[i];
        int left = i + 1, right = size - 1, target = 0 - nums[i];
        int jj = INT32_MIN;
        while(left < right) {
            if (nums[left] + nums[right] > target) {
                right--;
            } else if (nums[left] + nums[right] == target) {
                if (jj != nums[right]) {
                    jj = nums[right];
                    int a[] = {nums[i], nums[left], nums[right]};
                    result.emplace_back(vector<int>(a, a + 3));
                }
                right--;
                left++;
            } else {
                left++;
            }
        }
    }
    return result;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}