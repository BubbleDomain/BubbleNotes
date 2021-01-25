#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <cmath>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2021/1/22
 * @description: 529.minesweeper
 */
int mineNum(vector<vector<char>>& board, vector<int> click) {
    int ans = 0;
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if (i == 0 && j == 0) continue;
            if (click[0] + i < 0 || click[0] + i >= board.size()
                || click[1] + j < 0 || click[1] + j >= board[0].size()) continue;
            if (board[click[0] + i][click[1] + j] == 'M') ans++;
        }
    }
    return ans;
}

void update(vector<vector<char>>& board, vector<int> click) {
    if (click[0] < 0 || click[0] >= board.size()
        || click[1] < 0 || click[1] >= board[0].size()) return;
    char c = board[click[0]][click[1]];
    if (c != 'E') return;
    int mNum = mineNum(board, click);
    if (mNum == 0) {
        board[click[0]][click[1]] = 'B';
        for (int i = -1; i < 2; i++) {
            for (int j = -1; j < 2; j++) {
                if (i == 0 && j == 0) continue;
                update(board, {click[0] + i, click[1] + j});
            }
        }
    } else {
        board[click[0]][click[1]] = '0' + mNum;
    }
}

vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
    char c = board[click[0]][click[1]];
    switch(c) {
        case 'M':
            board[click[0]][click[1]] = 'X';
            break;
        default:
            update(board, click);
    }
    return board;
}

int main() {
    vector<vector<char>> board{{'E','E','E','E','E'},{'E','E','M','E','E'},{'E','E','E','E','E'},{'E','E','E','E','E'}};
    vector<int> click{3, 1};
    auto ans = updateBoard(board, click);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}