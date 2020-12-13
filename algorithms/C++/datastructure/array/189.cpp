#include <iostream>
#include <vector>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2020/12/13
 * @description: 189.rotate-array
 */
// 环状替换，没有看到实际证明，猜出来的解法
// 结论记录（待严谨证明）：
// 当 size 和 k 的最大公约数等于1(互素)的时候：1 次遍历就可以完成交换
// 当 size 和 k 的最大公约数不等于1的时候：1 次遍历是无法完成的所有元素归位，需要 (最大公约数) 次
void rotate1(vector<int>& nums, int k) {
    int size = nums.size();
    k %= size;
    if (k == 0 || size <= 1) return;
    int sNo = 0, start = nums[sNo], last = start, count = 0, i = 0;
    while (true) {
        int next = (i + k) % size;
        int temp = nums[next];
        nums[next] = last;
        last = temp;
        i = next;
        count++;
        if (i == sNo) {
            if (count == size) return;
            else {
                start = nums[++sNo];
                i = sNo;
                last = start;
            }
        }
    }
}

// 旋转数组法
void rotate(vector<int>& nums, int k) {
    int size = nums.size();
    k %= size;
    if (k == 0 || size <= 1) return;
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}

int main() {
    int a[] = {-1,-100,3,99};
    vector<int> aa(a, a + 4);
    rotate(aa, 2);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}