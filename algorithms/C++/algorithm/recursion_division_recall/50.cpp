#include <iostream>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2020/12/24
 * @description: 50.powx-n
 */
// 二分优化
double myPow(double x, int n) {
    if (n == 0) return 1;
    double ans;
    int t = abs(n);
    if (t == 1) ans = x;
    else {
        double temp = myPow(x, t / 2);
        ans = temp * temp;
        if (t % 2 == 1) ans *= x;
    }
    if (n < 0) ans = 1 / ans;
    return ans;
}

int main() {
    std::cout << myPow(0.1, 4) << std::endl;
    std::cout << myPow(2.0, -1) << std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}