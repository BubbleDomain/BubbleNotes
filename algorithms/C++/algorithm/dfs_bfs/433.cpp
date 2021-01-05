#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <cmath>
#include <unordered_set>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2021/1/4
 * @description: 433.minimum-genetic-mutation
 */
bool isValid(string a, string b) {
    int diff = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) diff++;
    }
    return diff == 1;
}

int ans = INT_MAX;

void dfs(vector<int> &states, vector<string> &bank, string current, string end, int size, int level) {
    if (current == end) ans = min(ans, level);
    for (int i = 0; i < size; i++) {
        if (states[i] == -1) continue;
        bool valid = isValid(bank[i], current);
        if (!valid) continue;
        states[i] = -1;
        dfs(states, bank, bank[i], end, size, level + 1);
        states[i] = 0;
    }
}

int minMutation(string start, string end, vector<string> &bank) {
    int size = bank.size();
    if (size == 0) return -1;
    vector<int> states(size);
    dfs(states, bank, start, end, size, 0);
    return ans == INT_MAX ? -1 : ans;
}

int main() {
    vector<string> bank{"AACCGGTA","AACCGCTA","AAACGGTA"};
    int ans = minMutation("AACCGGTT", "AAACGGTA", bank);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}