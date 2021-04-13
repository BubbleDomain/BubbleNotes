package algorithm.dynamic_programming;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2021/3/12
 * @description: 70.爬楼梯
 */
class Solution70 {
    public int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        int a = 1, b = 2;
        for (int i = 0; i < n - 2; i++) {
            int t = b;
            b = a + b;
            a = t;
        }
        return b;
    }

    public static void main(String[] args) {

    }
}
