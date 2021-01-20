#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <cmath>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2021/1/20
 * @description: 200.number-of-islands
 */
int numIslands(vector<vector<char>>& grid) {
    int size = grid.size();
    char ans = 'a';
    for (int i = 0; i <= size + grid[0].size() - 1; i++) {
        int k = i, start = 0;
        if (i >= size) {
            k = size - 1;
            start = i - size + 1;
        }

        for (int j = start, l = 0; j <= i && j < grid[0].size() && k - l >= 0; j++, l++) {
            if (grid[k - l][j] == '0') continue;
            char left = '0', top = '0';
            if (j - 1 >= 0) left = grid[k - l][j - 1];
            if (k - l - 1 >= 0) top = grid[k - l - 1][j];
            if (top != '0') grid[k - l][j] = top;
            if (left != '0') {
                grid[k - l][j] = left;
                if (top != '0') {
                    grid[k - l - 1][j] = left;
                    ans = left + 1;
                }
            }
            if (grid[k - l][j] == '1') {
                grid[k - l][j] = ans++;
            }
        }
    }
    return ans - 'a';
}

int main() {
//    vector<vector<char>> grid{{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};
//    int a = numIslands(grid);
//    vector<vector<char>> grid1{{'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'}};
//    int a1 = numIslands(grid1);
//    vector<vector<char>> grid2{{'1','0','1','1','0','1','1'}};
//    int a2 = numIslands(grid2);
//    vector<vector<char>> grid3{{'1','0','1','1','1'}, {'1','0','1','0','1'}, {'1','1','1','0','1'}};
//    int a3 = numIslands(grid3);
    vector<vector<char>> grid3{{'1','1','1'}, {'0','1','0'}, {'1','1','1'}};
    int a3 = numIslands(grid3);
    return 0;
}