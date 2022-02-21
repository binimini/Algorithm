
class Solution {
    static boolean[][] w, h;
    static int N;
    static boolean checkW(int r, int c){
        if (c==0) return true;
        if (c-1>=0 && w[r][c-1]) return true;
        if ((r-1>=0 && h[r-1][c])||h[r][c]) return true;
        return false;
    }

    static boolean checkH(int r, int c){
        if (c-1>=0 && (w[r][c-1]|| (r+1<=N && w[r+1][c-1]))) return true;
        if ((r-1>=0 && h[r-1][c])&&(r+1<=N && h[r+1][c])) return true;
        return false;
    }

    public int[][] solution(int n, int[][] build_frame) {
        w = new boolean[n+1][n+1];
        h = new boolean[n+1][n+1];
        N = n;
        for (int i = 0; i<build_frame.length; i++){
            int x = build_frame[i][0];
            int y = build_frame[i][1];
            int a = build_frame[i][2];
            int b = build_frame[i][3];
            if (b==0) {
                if (a==0) {
                    w[x][y] = false;
                    if (y+1<=n && w[x][y+1] && !checkW(x, y+1)) {
                        w[x][y] = true;
                        continue;
                    }
                    if (x-1>=0 && y+1<=n && h[x-1][y+1]&&!checkH(x-1, y+1)) {
                        w[x][y] = true;
                        continue;
                    }
                    if (y+1<=n && h[x][y+1]&&!checkH(x,y+1)) {
                        w[x][y] = true;
                        continue;
                    }

                }
                else if (a==1) {
                    h[x][y] = false;
                    if (w[x][y] && !checkW(x,y)) {
                        h[x][y] = true;
                        continue;
                    }
                    if (x+1<=n && w[x+1][y] && !checkW(x+1,y)) {
                        h[x][y] = true;
                        continue;
                    }
                    if (x-1>=0 && h[x-1][y] && !checkH(x-1, y)) {
                        h[x][y] = true;
                        continue;
                    }
                    if (x+1<=n && h[x+1][y] && !checkH(x+1, y)) {
                        h[x][y] = true;
                        continue;
                    }

                }
            }
            else if (b==1) {
                boolean res = a==0 ? checkW(x,y) : checkH(x, y);
                if (res) {
                    if (a==0) {
                        w[x][y] = true;
                    }
                    else {
                        h[x][y] = true;
                    }
                }
            }
        }

        int len = 0;
        for (int i = 0; i<=n; i++){
            for (int j = 0; j<=n; j++){
                if (w[i][j]) len++;
                if (h[i][j]) len++;
            }
        }
        int[][] ans = new int[len][3];
        System.out.println(len);
        int idx = 0;
        for (int i = 0; i<=n; i++) {
            for (int j = 0; j<=n; j++){
                if (w[i][j]) ans[idx++] = new int[]{i,j,0};
                if (h[i][j]) ans[idx++] = new int[]{i,j,1};
            }
        }
        return ans;
    }
}
