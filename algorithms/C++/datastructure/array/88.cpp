#include <iostream>
#include <vector>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2020/12/14 11:44 上午
 * @description: 88.merge-sorted-array
 */
// 为了降低空间复杂度将nums1先移动到最后，再双指针处理，时间复杂度不是最优
void merge1(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    for (int i = m - 1; i >= 0; i--) nums1[n + i] = nums1[i];
    for (int i = 0, j = 0, k = 0; k < m + n; k++) {
        if (i >= m || (j < n && nums1[n + i] > nums2[j])) {
            nums1[k] = nums2[j++];
        } else {
            nums1[k] = nums1[n + i];
            i++;
        }
    }
}

// 其实直接双指针从后往前遍历即可
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    for (int i = m - 1, j = n - 1, k = m + n - 1; k >= 0; k--) {
        if (i < 0 || (j >= 0 && nums2[j] >= nums1[i])) {
            nums1[k] = nums2[j--];
        } else {
            nums1[k] = nums1[i--];
        }
    }
}

int main() {
    int a[] = {1, 2, 4, 5, 6, 0};
    vector<int> aa(a, a + 6);
    int b[] = {3};
    vector<int> bb(b, b + 1);
    merge(aa, 5, bb, 1);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
