#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2020/12/12
 * @description: 1.two_sum
 */
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> s;
    for (int i = 0; i < nums.size(); i++) {
        int temp = s[target - nums[i]];
        if (temp > 0) {
            int t[] = {temp - 1, i};
            return vector<int>(t, t + 2);
        }
        s[nums[i]] = i + 1;
    }
    return vector<int>();
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}