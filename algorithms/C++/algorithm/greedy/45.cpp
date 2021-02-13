#include <iostream>
#include <vector>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2021/2/12
 * @description: 45.jump-game-ii
 */
int jump(vector<int> &nums) {
    int ans = 0;
    for (int i = 0; i < nums.size() - 1;) {
        int m = 0, t = 1;
        for (int j = 1; j <= nums[i]; j++) {
            if (i + j >= nums.size() - 1) {
                return ans + 1;
            }
            if (nums[i + j] + j > m) {
                m = nums[i + j] + j;
                t = j;
            }
        }
        i += t;
        ans++;
    }
    return ans;
}

int main() {
    vector<int> a {2, 1, 1, 1, 1};
    int b = jump(a);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}