#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2020/12/22
 * @description: 47.permutations-ii
 *
 * 回溯搜索
 * 1、下面使用交换的思路解答，减枝不够彻底，最后还是要hash去重
 * 2、todo: 还能更快，使用老方法尝试
 *
 */
vector<vector<int>> ans;
// 利用之前学习到的去重技巧
unordered_set<string> HS;

string convert(vector<int> &nums) {
    string t;
    for (int i : nums) t += i;
    return t;
}

void recurse(vector<int> &nums, int i, int l) {
    if (i == nums.size()) {
        string t = convert(nums);
        if (HS.find(t) == HS.end()) {
            ans.emplace_back(nums);
            HS.insert(t);
        }
        return;
    }

    for (int j = i; j < l; j++) {
        // 减枝优化
        if (i != j && nums[i] == nums[j]) continue;
        swap(nums[i], nums[j]);
        recurse(nums, i + 1, l);
        swap(nums[i], nums[j]);
    }
}

vector<vector<int>> permuteUnique(vector<int> &nums) {
    recurse(nums, 0, nums.size());
    return ans;
}

int main() {
    int a[] = {1, 1, 3, 3};
    vector<int> aa(a, a + 4);
    auto c = permuteUnique(aa);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}