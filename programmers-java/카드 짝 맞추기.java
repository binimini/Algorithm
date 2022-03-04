import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

import static java.lang.Math.min;

class Pair {
    int x;
    int y;
    public Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

class Tuple {
    int x;
    int y;
    int z;
    public Tuple(int x, int y, int z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }
}

class Solution {
    static void decideOrder(int cnt) {
        if (cnt==N) {
            for (int i = 0; i<4; i++){
                for (int j= 0; j<4; j++){
                    arr[i][j] = originalArr[i][j];
                }
            }
            Queue<Tuple> q = new LinkedList<>();
            q.add(new Tuple(R, C, 0));
            q.add(new Tuple(-1, -1, -1));
            for (int i= 0; i<N; i++){
                while(q.peek().x != -1) {
                    int lx = q.peek().x;
                    int ly = q.peek().y;
                    int lz = q.peek().z;
                    q.poll();

                    int to1 = dist(info[order[i]].get(0), info[order[i]].get(1));
                    int to0 = dist(info[order[i]].get(1), info[order[i]].get(0));
                    int sto0 = dist(new Pair(lx, ly), info[order[i]].get(0));
                    int sto1 = dist(new Pair(lx, ly), info[order[i]].get(1));
                    q.add(new Tuple(info[order[i]].get(0).x, info[order[i]].get(0).y, lz + sto1 + to0));
                    q.add(new Tuple(info[order[i]].get(1).x, info[order[i]].get(1).y, lz + sto0 + to1));
                }
                q.poll();
                q.add(new Tuple(-1, -1, -1));
                arr[info[order[i]].get(0).x][info[order[i]].get(0).y] = 0;
                arr[info[order[i]].get(1).x][info[order[i]].get(1).y] = 0;
            }
            while(q.size()!=1) {
                RES = min(RES, q.peek().z + N * 2);
                q.poll();
            }
            return;
        }

        for (int i = 1; i<=6; i++) {
            if (info[i].size()==0) continue;
            if (visited[i]) continue;
            order[cnt] = i;
            visited[i] = true;
            decideOrder(cnt+1);
            visited[i] = false;
        }
    }

    static int dist(Pair s, Pair d) {
        if (s.x == d.x && s.y == d.y) return 0;
        Queue<Tuple> q = new LinkedList<>();
        q.add(new Tuple(s.x, s.y, 0));
        while(!q.isEmpty()) {
            Tuple cur = q.peek();
            q.poll();
            for (int i = 0; i<4; i++) {
                int nx = cur.x + dir[i][0];
                int ny = cur.y + dir[i][1];
                if (nx<0 || nx>3 || ny<0 || ny>3) continue;
                if (nx==d.x && ny==d.y) return cur.z+1;
                q.add(new Tuple(nx, ny, cur.z+1));
            }

            for (int i = 0; i<4; i++) {
                int nx = cur.x;
                int ny = cur.y;
                while(!(nx<0 || nx>3 || ny<0 || ny>3)) {
                    nx = nx+dir[i][0];
                    ny = ny+dir[i][1];
                    if (nx<0 || nx>3 || ny<0 || ny>3) break;
                    if (arr[nx][ny]!=0) break;
                }
                if (nx<0 || nx>3 || ny<0 || ny>3) {
                    nx = nx-dir[i][0];
                    ny = ny-dir[i][1];
                }
                if (nx==d.x && ny==d.y) return cur.z+1;
                q.add(new Tuple(nx, ny, cur.z+1));
            }
        }
        return INF;
    }

    static int[][] dir = {{1,0}, {0,1}, {-1,0}, {0,-1}}, arr, originalArr;
    static int N, INF = 987654321, RES = INF, R, C;
    static int[] order = new int[7];
    static List<Pair>[] info = new List[7];
    static boolean[] visited = new boolean[7];

    public int solution(int[][] board, int r, int c) {
        originalArr = new int[4][4];
        for (int i = 0; i<4; i++){
            for (int j = 0; j<4; j++){
                originalArr[i][j] = board[i][j];
            }
        }
        arr = board;
        R = r;
        C = c;

        for (int i = 1; i<=6; i++) {
            info[i] = new ArrayList<>();
        }

        for (int i = 0; i<4; i++){
            for (int j = 0; j<4; j++){
                if (arr[i][j]==0) continue;
                N++;
                info[arr[i][j]].add(new Pair(i, j));
            }
        }
        N /= 2;
        decideOrder(0);
        return RES;
    }
}