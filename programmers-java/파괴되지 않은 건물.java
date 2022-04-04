class Solution {
    static int[][] arr, change, sum;
    static int N,M;
    public int solution(int[][] board, int[][] skill) {
        N = board.length;
        M = board[0].length;
        arr = board;
        change = new int[N][M];
        sum = new int[N][M];

        for (int i = 0; i<skill.length; i++) {
            int deg, r1,c1,r2,c2;
            if (skill[i][0]==1) {
                deg = -1*skill[i][5];
            }
            else {
                deg = skill[i][5];
            }
            r1 = skill[i][1]; c1 = skill[i][2]; r2 = skill[i][3]; c2 = skill[i][4];

            change[r2][c1] += deg;
            if (r1-1>=0) change[r1-1][c1] -= deg;
            if (c2+1<M) change[r2][c2+1] -= deg;
            if (r1-1>=0 && c2+1<M) change[r1-1][c2+1] += deg;
        }
        for (int j = 0; j<M; j++) {
            for (int i = N - 2; i >= 0; i--) {
                change[i][j] = change[i+1][j] + change[i][j];
            }
        }
        for (int i = 0; i<N; i++) {
            for (int j = 1; j<M; j++) {
                change[i][j] = change[i][j-1] + change[i][j];
            }
        }
        int answer = 0;
        for (int i = 0; i<N; i++) {
            for (int j=0; j<M; j++) {
                arr[i][j] += change[i][j];
                if (arr[i][j]>0) answer++;
            }
        }
        return answer;
    }
}