package algorithm.dynamic_programming;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2021/3/12
 * @description: 200.
 */
class Solution {
    void flood(char[][] grid, int i, int j) {
        if (grid[i][j] == '0') return;
        grid[i][j] = '0';
        if (i > 0) flood(grid, i - 1, j);
        if (j > 0) flood(grid, i, j - 1);
        if (i < grid.length - 1) flood(grid, i + 1, j);
        if (j < grid[0].length - 1) flood(grid, i, j + 1);
    }

    public int numIslands(char[][] grid) {
        int m = grid.length, n = grid[0].length, ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    ans++;
                    flood(grid, i, j);
                }
            }
        }
        return ans;
    }

    public static void main(String[] args) {

    }
}
