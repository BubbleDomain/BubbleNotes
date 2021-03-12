package algorithm.dynamic_programming;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2021/3/11
 * @description: 63.不同路径2
 */
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m = obstacleGrid.length, n = obstacleGrid[0].length;
        int[] dp = new int[n];
        boolean hasObstacle = false;
        for (int i = 0; i < n; i++) {
            if (obstacleGrid[0][i] == 1) hasObstacle = true;
            dp[i] = hasObstacle ? 0 : 1;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0;
                    continue;
                }
                dp[j] = (j == 0 ? 0 : dp[j - 1]) + dp[j];
            }
        }
        return dp[n - 1];
    }

    public static void main(String[] args) {

    }
}
