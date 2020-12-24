#include <iostream>
#include <vector>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2020/12/24
 * @description: 78.subsets
 */
vector<vector<int>> ans;

void recurse(vector<int>& nums, vector<int> &current, vector<int> &state, int num, int size) {
    if (num >= size) return;

    for (int i = 0; i < size; i++) {
        if (state[i] == true) return;
        current.push_back(nums[i]);
        state[i] = true;
        ans.emplace_back(current);
        recurse(nums, current, state, num + 1, size);
        current.pop_back();
        state[i] = false;
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    int size = nums.size();
    vector<int> state(size, false);
    vector<int> c{};
    ans.emplace_back(c);
    recurse(nums, c, state, 0, size);
    return ans;
}

int main() {
    vector<int> aa{1,2,3};
    auto ans = subsets(aa);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}