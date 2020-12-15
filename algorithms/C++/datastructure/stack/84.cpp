#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2020/12/15 10:15 上午
 * @description: 84.largest-rectangle-in-histogram
 */
// 目标: 计算出以某个柱子为基准的最大长方形
// 仅遍历数组一遍，记录下未求出最大长方形柱子的index
// 考虑到栈底的元素很小会有前驱的长方形尺寸，改动初始数组方便解决
int largestRectangleArea(vector<int>& heights) {
    int r = 0;
    stack<int> indexes;
    int size = heights.size();
    for (int i = 0; i < size; i++) {
        if (indexes.empty() || heights[indexes.top()] < heights[i]) {
            indexes.push(i);
            continue;
        }
        int last = indexes.top();
        while (!indexes.empty() && heights[indexes.top()] > heights[i]) {
            last = indexes.top();
            indexes.pop();
            r = max(r, (i - last) * heights[last]);
        }
        // 处理前驱
        indexes.push(last);
        heights[last] = heights[i];
    }
    while (!indexes.empty()) {
        int peak = indexes.top();
        indexes.pop();
        r = max(r, (size - peak) * heights[peak]);
    }
    return r;
}

int main() {
    int a[] = {2,1,2};
    vector<int> aa(a, a+3);
    int c = largestRectangleArea(aa);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
