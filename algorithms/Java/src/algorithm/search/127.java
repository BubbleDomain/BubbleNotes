package algorithm.search;


import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

class Solution127 {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        Set<String> lS = new HashSet<>();
        Set<String> rS = new HashSet<>();
        lS.add(beginWord);
        rS.add(endWord);
        Set<String> used = new HashSet<>();
        Set<String> wordSet = new HashSet<>(wordList);
        int ans = 1;
        while(!lS.isEmpty() && !rS.isEmpty()) {
            if (lS.size() > rS.size()) {
                Set<String> t = lS;
                lS = rS;
                rS = t;
            }
            Set<String> temp = new HashSet<>();
            for (String li : lS) {
                char[] cs = li.toCharArray();
                for (int j = 0; j < cs.length; j++) {
                    for (char i = 'a'; i < 'z'; i++) {
                        char tC = cs[j];
                        cs[j] = i;
                        String tS = String.valueOf(cs);
                        if (rS.contains(tS)) return ans + 1;
                        if (!used.contains(tS) && wordSet.contains(tS)) {
                            temp.add(tS);
                            used.add(tS);
                        }
                        cs[j] = tC;
                    }
                }
            }
            lS = temp;
            ans++;
        }
        return ans;
    }
}