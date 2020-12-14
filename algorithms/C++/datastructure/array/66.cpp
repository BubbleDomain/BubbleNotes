#include <iostream>
#include <vector>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2020/12/14 1:39 下午
 * @description: 66.plus-one
 */
vector<int> plusOne(vector<int> &digits) {
    int i = digits.size() - 1;
    bool flag = true;
    while (flag && i >= 0) {
        if (digits[i] != 9) flag = false;
        digits[i] = (digits[i] + 1) % 10;
        i--;
    }
    if (i < 0 && digits[0] == 0) digits.insert(digits.begin(), 1);
    return digits;
}

int main() {
    std::cout << 10 % 10 << std::endl;
    return 0;
}
