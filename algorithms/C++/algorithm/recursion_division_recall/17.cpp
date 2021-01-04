#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <cmath>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2020/12/26
 * @description: 17.letter-combinations-of-a-phone-number
 */
vector<vector<char>> a{{'a', 'b', 'c'},
                       {'d', 'e', 'f'},
                       {'g', 'h', 'i'},
                       {'j', 'k', 'l'},
                       {'m', 'n', 'o'},
                       {'p', 'q', 'r', 's'},
                       {'t', 'u', 'v'},
                       {'w', 'x', 'y', 'z'}};
vector<string> ans;

void recurse(string digits, string &temp, int level, int limit) {
    if (level == limit) {
        ans.push_back(temp);
        return;
    }
    auto v = a[digits[level] - '2'];
    for (auto i : v) {
        temp += i;
        recurse(digits, temp, level + 1, limit);
        temp.erase(temp.end() - 1);
    }
}

vector<string> letterCombinations(string digits) {
    int size = digits.size();
    if (size == 0)
        return ans;
    string t = "";
    recurse(digits, t, 0, size);
    return ans;
}

int main() {
    auto a = letterCombinations("23");
    std::cout << "Hello, World!" << std::endl;
    return 0;
}