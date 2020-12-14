#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2020/12/14 5:29 下午
 * @description: 20.valid-parentheses
 */
unordered_map<int, int> map = {{'(', ')'},
                               {'[', ']'},
                               {'{', '}'}};

bool match(int a, int b) {
    return map[a] == b;
}

bool isValid(string s) {
    stack<int> S;
    for (auto c : s) {
        if (!S.empty() && match(S.top(), c)) S.pop(); else S.push(c);
    }
    return S.empty();
}

int main() {
    bool a = isValid("[][][]");
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
