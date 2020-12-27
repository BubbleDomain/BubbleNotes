#include <iostream>
#include <vector>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2020/12/27
 * @description: 
 */
vector<char> meta {'a','e','i','o','u','A','E','I','O','U'};

bool halvesAreAlike(string s) {
    int l = s.length();
    int a = 0, b = 0;
    for (int i = 0; i < l / 2; i++) if (find(meta.begin(), meta.end(), s[i]) != meta.end()) a++;
    for (int i = l / 2; i < l; i++) if (find(meta.begin(), meta.end(), s[i]) != meta.end()) b++;
    return a == b;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}