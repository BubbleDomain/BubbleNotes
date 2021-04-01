package algorithm.search;

import java.util.ArrayList;
import java.util.List;

class Solution {
    List<String> ans = new ArrayList<>();
    int nn;
    void f(int left, int useL, int level, String s) {
        if (level == nn * 2) {
            ans.add(s);
            return;
        }
        if (useL < nn) {
            f(left + 1, useL + 1, level + 1, s + '(');
        }
        if (left > 0) {
            f(left - 1, useL, level + 1, s + ')');
        }
    }

    public List<String> generateParenthesis(int n) {
        nn = n;
        f(0, 0, 0, "");
        return ans;
    }
}