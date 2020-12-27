#include <iostream>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2020/12/26
 * @description: 
 */
string maximumBinaryString(string binary) {
    int length = binary.length();
    if (length == 1) return binary;
    int left = 0, right = 1;
    while (right < length) {
        if (binary[left] == '1') {
            left++;
            right++;
            continue;
        }
        if (binary[right] == '0') {
            if (left == right - 1) {
                binary[left] = '1';
            } else {
                binary[left] = '1';
                binary[left + 1] = '0';
                binary[right] = '1';
            }
            left++;
        }
        right++;
    }
    return binary;
}

int main() {
    auto c = maximumBinaryString("000110");
    std::cout << "Hello, World!" << std::endl;
    return 0;
}