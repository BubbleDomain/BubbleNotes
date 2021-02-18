#include <iostream>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2021/2/14
 * @description: 69.sqrtx
 *
 * 主要是边界容易出现问题
 * 取右中位数也是一种方式
 */
int mySqrt1(int x) {
    int l = 0, r = x, ans = 0;
    while (l <= r) {
        long mid = l + (r - l) / 2;
        if (mid * mid == x) {
            return mid;
        } else if (mid * mid > x) {
            r = mid - 1;
        } else {
            ans = mid;
            l = mid + 1;
        }
    }
    return ans;
}

int mySqrt(int x) {
    int l = 1, r = x;
    while (l <= r) {
        // 防止越界 不使用(l + r) / 2
        long mid = l + (r - l) / 2;
        if (mid * mid == x) {
            return mid;
        } else if (mid * mid > x) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return r;
}

int main() {
    std::cout << mySqrt(1) << std::endl;
    std::cout << mySqrt(2) << std::endl;
    std::cout << mySqrt(3) << std::endl;
    std::cout << mySqrt(4) << std::endl;
    std::cout << mySqrt(2147395599) << std::endl;
    return 0;
}