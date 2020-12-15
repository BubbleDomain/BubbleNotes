#include <iostream>
#include <deque>
#include <vector>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2020/12/15
 * @description: 42.trapping-rain-water
 */
int trap(vector<int>& height) {
    deque<int> d;
    int size = height.size(), sum = 0;
    for (int i = 0; i < size; i++) {
        if (height[i] == 0) continue;
        if (!d.empty()) {
            // 计算雨
            while(!d.empty()) {
                int temp = min(height[d.back()], height[i]);
                sum += (temp * (i - d.back() - 1));
                for (int j = d.back() + 1; j < i; j++) {
                    sum -= height[j];
                    height[j] = temp;
                }
                d.pop_back();
            }
        }
        d.push_back(i);
    }
    return sum;
}

int main() {
    int a[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> aa(a, a + 12);
    int c = trap(aa);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}