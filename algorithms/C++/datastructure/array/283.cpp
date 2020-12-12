#include <iostream>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2020/12/12
 * @description: 283.move-zeroes
 */
void moveZeroes(vector<int>& nums) {
    int n = nums.size(), left = 0, right = 0;
    while (right < n) {
        if (nums[right]) {
            if (nums[left] != nums[right]) {
                nums[left] = nums[right];
                nums[right] = 0;
            }

            left++;
        }
        right++;
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}