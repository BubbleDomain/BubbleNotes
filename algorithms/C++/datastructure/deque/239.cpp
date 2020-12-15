#include <iostream>
#include <vector>
#include <deque>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2020/12/15 4:12 下午
 * @description: 239.sliding-window-maximum
 */
// deque解法
// 每次推入一个数，队伍长度大于k则先将队首推出 ERROR -> 应该是队首到当前遍历点距离大于k则推出
// 如果小于等于队尾就排到队尾
// 如果推入的数大于队尾，则将队尾小于该数的推出，最后插入该数
vector<int> maxSlidingWindow1(vector<int> &nums, int k) {
    vector<int> result;
    deque<int> d;
    int size = nums.size();
    for (int i = 0; i < size; i++) {

        while (!d.empty()) {
            if (nums[d.back()] < nums[i]) d.pop_back();
            else {
                d.push_back(i);
                break;
            }
        }
        if (d.empty()) d.push_back(i);
        if (i < k - 1) continue;
        if (i - d.front() >= k) d.pop_front();
        result.push_back(nums[d.front()]);
    }
    return result;
}

// 动态规划
vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    vector<int> result;
    int size = nums.size();
    int dp[size][size];
    for (int i = 0; i < size; i++) {

    }
}

int main() {
    int a[] = {1,3,1,2,0,5};
    vector<int> aa(a, a+6);
    auto c = maxSlidingWindow(aa, 3);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
