#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <cmath>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2020/12/22
 * @description: 77.combinations
 */
vector<vector<int>> ans;

void recurse(int i, int j, int n, int k, vector<int> t) {
    if (i > k) {
        ans.push_back(t);
        return;
    }
    for (; j <= n; j++) {
        vector<int> temp(t);
        temp.push_back(j);
        recurse(i + 1, j + 1, n, k, temp);
    }
}

vector<vector<int>> combine(int n, int k) {
    recurse(1, 1, n, k, vector<int>());
    return ans;
}

int main() {
    auto ans = combine(4, 2);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}