#include <iostream>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2021/3/7
 * @description: 
 */
bool checkOnesSegment(string s) {
    int state = 0;
    for (auto c : s) {
        if (c == '1') {
            if (state == 0) {
                state = 1;
            } else if (state == 2) {
                return false;
            }
        } else {
            if (state == 1) {
                state = 2;
            }
        }
    }
    return true;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}