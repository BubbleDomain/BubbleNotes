package datastructure.array;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2021/3/11
 * @description: 1143.最长公共子序列
 */
class Solution {
    // 二维矩阵的前三个状态来推理后一个状态
    public int longestCommonSubsequence(String text1, String text2) {
        int l1 = text1.length(), l2 = text2.length();
        int[][] dp = new int[l1][l2];
        boolean f = false;
        for (int i = 0; i < l1; i++) {
            if (f || text1.charAt(i) == text2.charAt(0)) {
                dp[i][0] = 1;
                f = true;
            }
        }
        f = false;
        for (int i = 0; i < l2; i++) {
            if (f || text1.charAt(0) == text2.charAt(i)) {
                dp[0][i] = 1;
                f = true;
            }
        }
        for (int i = 1; i < l1; i++) {
            for (int j = 1; j < l2; j++) {
                int m = Math.max(dp[i - 1][j], dp[i - 1][j - 1] + (text1.charAt(i) == text2.charAt(j) ? 1 : 0));
                m = Math.max(m, dp[i][j - 1]);
                dp[i][j] = m;
            }
        }
        return dp[l1 - 1][l2 - 1];
    }

    public static void main(String[] args) {

    }
}
