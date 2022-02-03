import java.util.LinkedList;
import java.util.Queue;

import static java.lang.Math.max;

class Pair {
    int x;
    int y;
    public Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

class Solution {

    static int [][] d = {{1,0},{0,1},{-1,0},{0,-1}};
    static int bfs(int sx, int sy, boolean[][] visited, int m, int n, int[][] picture) {
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(sx, sy));
        visited[sx][sy] = true;
        int ans = 1;
        while(!q.isEmpty()) {
            int x = q.peek().x;
            int y = q.peek().y;
            q.poll();
            for (int i = 0; i<4; i++){
                int nx = x + d[i][0];
                int ny = y + d[i][1];
                if (nx<0||nx>m-1||ny<0||ny>n-1) continue;
                if (visited[nx][ny]) continue;
                if (picture[nx][ny] != picture[x][y]) continue;
                visited[nx][ny] = true;
                ans++;
                q.add(new Pair(nx, ny));
            }
        }
        return ans;
    }
    public int[] solution(int m, int n, int[][] picture) {
        int numberOfArea = 0;
        int maxSizeOfOneArea = 0;

        boolean[][] visited = new boolean[m][n];
        for (int i = 0; i<m; i++){
            for (int j = 0; j<n; j++){
                if (visited[i][j]) continue;
                if (picture[i][j]==0) continue;
                numberOfArea++;
                maxSizeOfOneArea = max(maxSizeOfOneArea, bfs(i,j, visited, m,n, picture));
            }
        }

        int[] answer = new int[2];
        answer[0] = numberOfArea;
        answer[1] = maxSizeOfOneArea;
        return answer;
    }
}