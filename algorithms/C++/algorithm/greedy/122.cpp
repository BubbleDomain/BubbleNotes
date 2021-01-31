#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <cmath>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2021/1/26
 * @description: 122.best-time-to-buy-and-sell-stock-ii
 */
int maxProfit(vector<int>& prices) {
    int ans = 0;
    int buy = -1;
    int sale = -1;
    for (int i = 0; i < prices.size(); i++) {
        if (buy == -1) {
            buy = prices[i];
            continue;
        }
        if (prices[i - 1] < prices[i]) {
            sale = prices[i];
        } else if (prices[i - 1] > prices[i]) {
            if (sale == -1) {
                buy = prices[i];
                continue;
            }
            ans += (sale - buy);
            buy = prices[i];
            sale = -1;
        }
    }
    if (sale != -1) ans += (sale - buy);
    return ans;
}

int main() {
    vector<int> a {7,1,5,3,6,4};
    int b = maxProfit(a);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}