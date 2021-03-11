#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <cmath>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2021/3/11
 * @description: 74.search-a-2d-matrix
 */
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int l = 0, r = matrix.size() - 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (matrix[mid][0] == target) {
            return true;
        } else if (matrix[mid][0] > target) {
            r = mid - 1;
        } else {
            if (matrix[mid + 1][0] > target) {
                l = mid;
                break;
            }
            l = mid + 1;
        }
    }
    auto list = matrix[l];
    int left = 0, right = list.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (target == list[mid])
            return true;
        else if (target > list[mid]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return list[left] == target;
}

int main() {
    vector<vector<int>> matrix{{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    bool a = searchMatrix(matrix, 3);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}