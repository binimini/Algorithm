import java.util.PriorityQueue;

import static java.lang.Math.min;

class Tuple {
    int x;
    int y;
    int d;
    int c;
    public Tuple(int x, int y, int d, int c) {
        this.x = x;
        this.y = y;
        this.d = d;
        this.c = c;
    }
}

class Solution {
    static int[][] arr, dir = {{1,0},{0,1},{-1,0},{0,-1}, {0,0}};
    static int[][][] visited;
    static int N, INF = 987654321;
    static PriorityQueue<Tuple> pq = new PriorityQueue<Tuple>((Tuple a, Tuple b)-> a.c >= b.c ? 1 : -1);
    static int dist(int fd) {
        visited = new int [N][N][4]; // 방향에 따라 다른 방향의 값보다 커도 후에 작아질 수 있음
        visited[0][0][fd] = 1;
        while(!pq.isEmpty()) {
            Tuple cur = pq.peek();
            pq.poll();

            if (cur.c > visited[cur.x][cur.y][cur.d]) continue;
            for (int i=0; i<4; i++) {
                int nx = cur.x + dir[i][0];
                int ny = cur.y + dir[i][1];
                int nc = cur.d==i ? cur.c+100 : cur.c+600;
                if (nx<0||nx>N-1||ny<0||ny>N-1) continue;
                if (arr[nx][ny]==1) continue;
                if (visited[nx][ny][i]==0 || (visited[nx][ny][i]!=0 && visited[nx][ny][i] > nc)) {
                    visited[nx][ny][i] = nc;
                    pq.add(new Tuple(nx, ny, i, nc));
                }

            }
        }

        int result = INF;
        for (int i = 0; i<4; i++){
            if (visited[N-1][N-1][i]==0) continue;
            result = min(visited[N-1][N-1][i], result);
        }
        return result-1;
    }

    public int solution(int[][] board) {
        N = board.length;
        arr = board;

        int RES = INF;
        for (int i = 0; i<4; i++) {
            pq.add(new Tuple(0, 0, i, 1));
            RES = min(RES, dist(i));
        }
        return RES;
    }
}