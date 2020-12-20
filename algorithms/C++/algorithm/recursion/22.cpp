#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2020/12/20
 * @description: 22.generate-parentheses
 */
void recurse(int l, int r, string s, vector<string> &result,int Stack) {
    if (l == 0 && r == 0) {
        result.push_back(s);
        return;
    }
    if (Stack == 0 && l > 0) {
        recurse(--l, r, s + '(', result, ++Stack);
    } else {
        if (l > 0) recurse(l - 1, r, s + '(', result, Stack + 1);
        if (r > 0) recurse(l, r - 1, s + ')', result, Stack - 1);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> r;
    recurse(n, n, "", r, 0);
    return r;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}