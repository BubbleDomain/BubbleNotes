#include <iostream>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2020/12/20
 * @description: 
 */
string reformatNumber(string number) {
    string result = "";
    int t = 0;
    for (auto c : number) {
        if (c == ' ' || c == '-') continue;
        result += c;
        ++t;
        if (t == 3) {
            result += '-';
            t = 0;
        }
    }
    int length = result.length();
    if (length >= 5 && result[length - 2] == '-') swap(result[length - 2], result[length - 3]);
    if (result[length - 1] == '-') result.erase(length - 1);
    return result;
}

int main() {
    std::cout << reformatNumber("1-23-45 6") << std::endl;
    std::cout << reformatNumber("123 4-567") << std::endl;
    std::cout << reformatNumber("123 4-5678") << std::endl;
    std::cout << reformatNumber("12") << std::endl;
    std::cout << reformatNumber("--17-5 229 35-39475 ") << std::endl;
    std::cout << reformatNumber("123214124 - 234 ") << std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}