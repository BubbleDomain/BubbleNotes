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

void recurse1(vector<int> &states, int level, int n) {
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
        recurse1(states, level + 1, n);
        states.pop_back();
    }
}

// 优化思路，转化结构
void recurse(vector<int> &states, vector<int> &last, int level, int n) {
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

    for (int i = 0; i < n; i++) {
        if (last[i]) continue;
        states.push_back(i);
        // 判断当前行有那些位置可以落子
        unordered_set<int> inValid;
        auto temp = last;
        last[i] = 1;
        if (i + 1 < n) last[i + 1] = 1;
        if (i - 1 >= 0) last[i - 1] = 1;
        recurse(states, last, level + 1, n);
        last = temp;
        states.pop_back();
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<int> state;
    vector<int> last(n, 0);
    recurse(state, last, 0, n);
    return ans;
}

int main() {
    auto a = solveNQueens(4);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}