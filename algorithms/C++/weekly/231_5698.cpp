#include <iostream>
#include <vector>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2021/3/7
 * @description: 
 */

int minElements(vector<int>& nums, int limit, int goal) {
    int a = goal / limit, b = goal % limit;

    for (auto num : nums) {
        a -= (num / limit);
        b -= (num % limit);
        if (b >= limit) {
            b -= limit;
            a++;
        } else if (b <= -limit) {
            b += limit;
            a--;
        }
    }
    if (a <= 0 && b < 0) {
        b = abs(b);
    }
    a = abs(a);
    return a + ((b > 0) ? 1 : 0);
}

int main() {
    vector<int> a{1,-10,9,1};
    int b = minElements(a, 100, 0);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}