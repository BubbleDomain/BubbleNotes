#include <iostream>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2020/12/12
 * @description: 11.container-with-most-water
 */

int maxArea(vector<int>& height) {
    int m = 0;
    int size = height.size(), left = 0, right = size - 1;
    while(left < right) {
        int l = right - left;
        int t;
        if (height[left] > height[right]) {
            t = height[right] * l;
            right--;
        } else {
            t = height[left] * l;
            left++;
        }
        m = max(t, m);
    }
    return m;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}