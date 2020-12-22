#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2020/12/22
 * @description: 46.permutations
 */
vector<vector<int>> ans;
unordered_set<int> S;

// 不用hashset 使用个数组维护状态速度更快
void recurse(vector<int>& nums, int i, int length, vector<int> t) {
    if (i == length) {
        ans.push_back(t);
        return;
    }
    for (int j = 0; j < length; j++) {
        auto pair = S.insert(nums[j]);
        if (!pair.second) continue;
        t = vector<int>(t);
        t.push_back(nums[j]);
        recurse(nums, i + 1, length, t);
        t.pop_back();
        S.erase(nums[j]);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    recurse(nums, 0, nums.size(), {});
    return ans;
}

int main() {
    int a[] = {1,2,3};
    vector<int> aa(a, a + 3);
    auto c = permute(aa);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}