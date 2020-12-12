#include <iostream>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2020/12/12
 * @description: 70.climbing-stairs
 */
int climbStairs(int n) {
    if (n <= 2) return n;
    int a = 1, b = 2;
    for (int i = 0; i< n - 2; i++) {
        int t = b;
        b = a + b;
        a = t;
    }
    return b;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}