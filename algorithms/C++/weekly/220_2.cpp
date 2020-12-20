#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2020/12/20
 * @description: 
 */
int maximumUniqueSubarray(vector<int> &nums) {
    unordered_map<int, int> UM;

    int l = 0, r = 0, size = nums.size(), result = 0, temp = 0;
    while (r < size) {
        auto t = UM[nums[r]];
        if (t > 0) {
            // result add
            result = max(result, temp);

            // reset **该处剪枝是关键**
            if (r - t + 1 > t - l) {
                for (int i = l; i < t; i++) {
                    temp -= nums[i];
                    UM[nums[i]] = 0;
                }
                l = t;
                UM[nums[r]] = r + 1;
                temp += nums[r++];
            }else {
                temp = 0;
                r = t;
                l = r;
                UM.clear();
            }
            continue;
        }
        // add temp
        UM[nums[r]] = r + 1;
        temp += nums[r++];
    }
    result = max(result, temp);
    return result;
}

// 动态规划少进行加法运算
int maximumUniqueSubarray1(vector<int> &nums) {
    unordered_map<int, int> UM;
    int l = 0, r = 0, size = nums.size(), result = 0;
    vector<vector<int>> dp(size, vector<int>(size, 0));
    for (int i = 0; i < size; i++) dp[i][i] = nums[i];
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            dp[i][j] = dp[i][j - 1] + dp[j][j];
        }
    }

    while (r < size) {
        auto t = UM[nums[r]];
        if (t > 0) {
            // result add
            result = max(result, dp[l][r - 1]);
            // solve same
            r = t;
            l = r;
            UM.clear();
            continue;
        }
        // add temp
        UM[nums[r]] = r + 1;
        r++;
    }
    if (l < size) result = max(result, dp[l][r - 1]);
    return result;
}

int main() {

//    int a[] = {4,2,4,5,6};
//    vector<int> b(a, a + 5);
//    std::cout << maximumUniqueSubarray(b) << std::endl;
//    int a[] = {5, 2, 1, 2, 5, 2, 1, 2, 5};
//    vector<int> b(a, a + 9);
//    std::cout << maximumUniqueSubarray(b) << std::endl;


//    int a[] = {1,3,4,5,6,3,5};
//    vector<int> b(a, a + 7);
//    std::cout << maximumUniqueSubarray(b) << std::endl;

    int a[] = {10000,1,10000,1,1,1,1,1,1};
    vector<int> b(a, a + 9);
    std::cout << maximumUniqueSubarray(b) << std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}