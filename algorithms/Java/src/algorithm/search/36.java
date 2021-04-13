package algorithm.search;

class Solution36 {
    public boolean isValidSudoku(char[][] board) {
        if (!solve(board, 1) || !solve(board, 2)) return false;
        int[] dx1 = {0, 3, 6, 0, 3, 6, 0, 3, 6};
        int[] dy1 = {0, 0, 0, 3, 3, 3, 6, 6, 6};
        int[] dx2 = {0, 1, 2, 0, 1, 2, 0, 1, 2};
        int[] dy2 = {0, 0, 0, 1, 1, 1, 2, 2, 2};
        for (int i = 0; i < 9; i++) {
            int x = dx1[i];
            int y = dy1[i];
            int state = 0;
            for (int j = 0; j < 9; j++) {
                char c = board[x + dx2[j]][y + dy2[j]];
                if (c == '.') continue;
                int t = c - '1';
                if ((state & 1 << t) > 0) return false;
                state += 1 << t;
            }
        }
        return true;
    }

    boolean solve(char[][] board, int type) {
        for (int i = 0; i < 9; i++) {
            int state = 0;
            for (int j = 0; j < 9; j++) {
                char c = type == 1 ? board[i][j] : board[j][i];
                if (c == '.') continue;
                int t = c - '1';
                if ((state & 1 << t) > 0) return false;
                state += 1 << t;
            }
        }
        return true;
    }
}