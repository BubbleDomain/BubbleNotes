#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <unordered_set>
#include <cmath>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2021/1/4
 * @description: 51.n-queens
 */
// 方法一：递归回溯
vector<vector<string>> ans;

void recurse(vector<int> &states, int level, int n) {
    if (level == n) {
        vector<string> temp;
        for (int i = 0; i < n; i++) {
            string s;
            for (int j = 0; j < n; j++) {
                s += (j == states[i] ? 'Q' : '.');
            }
            temp.push_back(s);
        }
        ans.push_back(temp);
        return;
    }

    // 判断当前行有那些位置可以落子
    unordered_set<int> inValid;
    for (int i = 0; i < states.size(); i++) {
        int state = states[i];
        inValid.insert(state);
        int temp = state + (level - i);
        if (temp < n) inValid.insert(temp);
        temp = state - (level - i);
        if (temp >= 0) inValid.insert(temp);
    }

    for (int i = 0; i < n; i++) {
        if (inValid.find(i) != inValid.end()) continue;
        states.push_back(i);
        recurse(states, level + 1, n);
        states.pop_back();
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<int> state;
    recurse(state, 0, n);
    return ans;
}

int main() {
    auto a = solveNQueens(4);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}