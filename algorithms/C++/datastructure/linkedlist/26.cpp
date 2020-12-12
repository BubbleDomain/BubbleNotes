#include <iostream>
#include <vector>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2020/12/11 3:42 下午
 * @description: 26.remove-duplicates-from-sorted-array
 */
// 简单erase
int removeDuplicates1(vector<int> &nums) {
    if (nums.size() == 0)
        return 0;
    int result = 1, last = nums[0];
    auto i = nums.begin();
    i++;
    while (i != nums.end()) {
        if (*i == last) {
            i = nums.erase(i);
        } else {
            last = *i;
            result++;
            i++;
        }
    }
    return result;
}

// 更慢
int removeDuplicates2(vector<int> &nums) {
    if (nums.size() == 0)
        return 0;
    int result = 1, current = nums[0], length = 0;
    auto i = nums.begin(), start = ++i;
    while (i != nums.end()) {
        if (*i != current) {
            current = *i;
            if (length > 0) {
                i = nums.erase(start, start + length) + 1;
                length = 0;
            } else i++;
            result++;
            start = i;
        } else {
            length++;
            i++;
        }
    }
    if (length > 0) {
        nums.erase(start, start + length);
    }
    return result;
}

int removeDuplicates(vector<int> &nums) {
    int size = nums.size();
    if (size == 0) return 0;
    int left = 1, current = nums[0];
    for (int i = 1; i < size; i++) {
        if (current != nums[i]) {
            nums[left++] = nums[i];
            current = nums[i];
        }
    }
    return left;
}

int main() {
    int a[] = {0, 0,1,1,3};
    vector<int> c(a, a + 5);
    int b = removeDuplicates(c);

    std::cout << "Hello, World!" << std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
