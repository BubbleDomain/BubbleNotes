#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <cmath>
#include <unordered_map>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2020/12/26
 * @description: 169.majority-element
 */
int majorityElement(vector<int>& nums) {
    int center = nums.size() / 2;
    unordered_map<int, int> M;
    for (auto i : nums) {
        if (M.find(i) == M.end()) M[i] = 1;
        else M[i]++;
        if (M[i] > center) return i;
    }
    return 0;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}