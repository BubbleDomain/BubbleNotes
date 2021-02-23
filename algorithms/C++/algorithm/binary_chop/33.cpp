#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <cmath>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2021/2/22
 * @description: 33.search-in-rotated-sorted-array
 */
int s(vector<int>& nums, int target, int left, int right) {
    while(left < right) {
        int mid = left + (right - left) / 2;
        if (target == nums[mid]) {
            return mid;
        } else if (target > nums[mid]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return target == nums[left] ? left : -1;
}

int search(vector<int>& nums, int target) {
    if (nums.size() == 1) return nums[0] == target ? 0 : -1;
    int f = 0;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i - 1] > nums[i]) f = i;
    }
    if (f == 0) return s(nums, target, 0, nums.size() - 1);
    if (target == nums[0]) {
        return 0;
    } else if (target > nums[0]) {
        return s(nums, target, 1, f - 1);
    } else {
        return s(nums, target, f, nums.size() - 1);
    }
}

int main() {
    vector<int> a = {3, 1};
    int b = search(a, 2);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}