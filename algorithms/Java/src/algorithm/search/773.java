package algorithm.search;

import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;

class Solution773 {
    String end = "123450";
    int[][] table = {{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
    public int slidingPuzzle(int[][] board) {
        // init
        char[] originState = new char[6];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                originState[i * 3 + j] = (char) ('0' + board[i][j]);
            }
        }
        String temp = String.valueOf(originState);
        Queue<String> q = new LinkedList<>();
        q.add(temp);
        HashSet<String> used = new HashSet<>();
        ////
        used.add(temp);
        ////
        int step = 0;
        String last = temp;
        while(!q.isEmpty()) {
            String current = q.poll();
            if (current.equals(end)) return step;
            boolean isLast = false;
            if (current.equals(last)) {
                step++;
                isLast = true;
            }
            char[] c = current.toCharArray();
            for (int i = 0; i < 6; i++) {
                if (c[i] == '0') {
                    for (int j = 0; j < table[i].length; j++) {
                        c[i] = c[table[i][j]];
                        c[table[i][j]] = '0';
                        String t = String.valueOf(c);
                        c[table[i][j]] = c[i];
                        c[i] = '0';
                        if (isLast) last = t;
                        if (used.contains(t)) continue;
                        q.add(t);
                        used.add(t);
                    }
                    break;
                }
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        Queue<String> q = new LinkedList<>();
        q.add("123");
        q.add("2222");
        q.add("3");
        String t = q.poll();
    }
}