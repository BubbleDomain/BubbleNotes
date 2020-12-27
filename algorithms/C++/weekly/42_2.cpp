#include <iostream>
#include <vector>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2020/12/26
 * @description: 
 */
double averageWaitingTime(vector<vector<int>>& customers) {
    int willDone = customers[0][0], total = 0, length = customers.size(), ans = 0;
    for (auto item : customers) {
        if (willDone < item[0]) willDone = item[0];
        willDone += item[1];
        total += (willDone - item[0]);
        ans += total / length;
        total %= length;
    }
    return (double)total / length + ans;
}

int main() {
    vector<vector<int>> a{{1,2}, {2,5}, {4,3}};
    auto ans = averageWaitingTime(a);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}