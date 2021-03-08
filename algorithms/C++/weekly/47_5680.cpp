#include <iostream>
#include <vector>
#include "math.h"

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2021/3/6
 * @description: 
 */
int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
    int ans = INT32_MAX;
    int n = -1;

    for (int j = 0; j < points.size(); j++) {
        vector<int> i = points[j];
        if (i[0] == x) {
            int t = (int) pow(y - i[1], 2);
            if (t < ans) {
                ans = t;
                n = j;
            }
        }
        else if (i[1] == y) {
            int t = (int) pow(x - i[0], 2);
            if (t < ans) {
                ans = t;
                n = j;
            }
        }
    }
    return n;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}