#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <cmath>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2021/3/11
 * @description: 62.不同路径
 */
int uniquePaths(int m, int n) {
    vector<int> dp(m);
    for (int i = 0; i < m; i++) dp[i] = 1;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 1; j < m; j++) {
            dp[j] = dp[j - 1] + dp[j];
        }
    }
    return dp[m - 1];
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}