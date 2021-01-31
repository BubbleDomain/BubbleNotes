#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <cmath>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2021/1/31
 * @description: 455.assign-cookies
 */
int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int i = 0, j = 0, ans = 0;
    while(i < g.size() && j < s.size()) {
        if (g[i] <= s[j]) {
            i++;
            j++;
            ans++;
        } else {
            j++;
        }
    }
    return ans;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}