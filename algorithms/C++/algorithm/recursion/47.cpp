#include <iostream>
#include <vector>
#include <stack>
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
 * 2、使用老方法尝试，速度没上面快
 *
 */
vector<vector<int>> ans1;
// 利用之前学习到的去重技巧
unordered_set<string> HS1;

string convert1(vector<int> &nums) {
    string t;
    for (int i : nums) t += i;
    return t;
}

void recurse1(vector<int> &nums, int i, int l) {
    if (i == nums.size()) {
        string t = convert1(nums);
        if (HS1.find(t) == HS1.end()) {
            ans1.emplace_back(nums);
            HS1.insert(t);
        }
        return;
    }

    for (int j = i; j < l; j++) {
        // 减枝优化
        if (i != j && nums[i] == nums[j]) continue;
        swap(nums[i], nums[j]);
        recurse1(nums, i + 1, l);
        swap(nums[i], nums[j]);
    }
}

vector<vector<int>> permuteUnique1(vector<int> &nums) {
    recurse1(nums, 0, nums.size());
    return ans1;
}

vector<vector<int>> ans;

void recurse(vector<int> &nums, vector<int> &state, int i, int l, vector<int> t) {
    if (i >= l) {
        ans.push_back(t);
        return;
    }
    unordered_set<int> S;
    for (int j = 0; j < l; j++) {
        if (state[j] || S.find(nums[j]) != S.end()) continue;
        S.insert(nums[j]);
        t.push_back(nums[j]);
        state[j] = true;
        recurse(nums, state, i + 1, l, t);
        t.pop_back();
        state[j] = false;
    }
}

vector<vector<int>> permuteUnique(vector<int> &nums) {
    int size = nums.size();
    vector<int> t(size, false);
    recurse(nums, t, 0, size, {});
    return ans;
}

int main() {
    int a[] = {1, 1, 3, 3};
    vector<int> aa(a, a + 4);
    auto c = permuteUnique(aa);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}