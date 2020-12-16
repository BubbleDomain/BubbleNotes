#include <iostream>
#include <unordered_map>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2020/12/16 3:51 下午
 * @description: 242.valid-anagram
 */
bool isAnagram(string s, string t) {
    if (s.length() != t.length()) return false;
    unordered_map<int, int> M;
    for (auto c : s) M[c]++;
    for (auto c : t) {
        if (!M[c]) return false;
        M[c]--;
    }
    return true;
}

int main() {
    bool b = isAnagram("abac", "bcaa");
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
