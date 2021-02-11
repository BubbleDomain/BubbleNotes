#include <iostream>
#include <vector>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2021/2/11
 * @description: 55.jump-game
 */
bool canJump(vector<int>& nums) {
    int m = 0, size = nums.size();
    for (int i = 0; i < size; i++) {
        if (nums[i] == 0) continue;
        if (i > m) break;
        m = max(m, nums[i] + i);
    }
    return m >= size - 1;
}

int main() {
    vector<int> a{3,0,8,2,0,0,1};
    bool b = canJump(a);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}