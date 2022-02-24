import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

import static java.lang.Math.min;

class Solution {
    class Tuple {
        int x;
        int y;
        int z;
        public Tuple (int x, int y, int z){
            this.x = x;
            this.y = y;
            this.z = z;
        }
    }

    class Pair {
        int x;
        int y;
        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
    static List<Pair>[] check;
    static Tuple[] after;
    static Queue<Tuple> q = new LinkedList<>();
    static int[][][] visited;
    static int[][] arr;
    static int N;

    static boolean checkEnd(int status, int x, int y) {
        if (x==N-1 && y ==N-1) return true;
        if (status==0 && x==N-1 && y+1==N-1) return true;
        else if (status==1 && x+1==N-1 && y== N-1) return true;
        return false;
    }

    static boolean canGo(int idx, int x, int y) {
        for (int i = 0; i<check[idx].size(); i++){
            int nx = x + check[idx].get(i).x;
            int ny = y + check[idx].get(i).y;
            if (nx<0 || nx>N-1 || ny<0 || ny>N-1) return false;
            if (arr[nx][ny]==1) return false;
        }
        return true;
    }

    int bfs() {
        while (!q.isEmpty()) {
            int x = q.peek().x;
            int y = q.peek().y;
            int z = q.peek().z;
            System.out.println(x+" "+y+" "+z);
            q.poll();
            if (checkEnd(z, x, y)) return visited[x][y][z]-1;
            if (z==0) {
                for (int i = 0; i<8; i++) {
                    if (!canGo(i, x, y)) continue;
                    int nx = x+after[i].x;
                    int ny = y+after[i].y;
                    int nz = after[i].z;
                    if (visited[nx][ny][nz]!=0) continue;
                    visited[nx][ny][nz] = visited[x][y][z]+1;
                    q.add(new Tuple(nx, ny, nz));
                }
            }
            else if (z==1) {
                for (int i = 8; i<16; i++) {
                    if (!canGo(i, x, y)) continue;
                    int nx = x+after[i].x;
                    int ny = y+after[i].y;
                    int nz = after[i].z;
                    if (visited[nx][ny][nz]!=0) continue;
                    visited[nx][ny][nz] = visited[x][y][z]+1;
                    q.add(new Tuple(nx, ny, nz));
                }
            }
        }
        return -1;
    }

    void setting() {
        // 가로 이동
        check[0] = List.of(new Pair(-1,0), new Pair(-1, 1));
        after[0] = new Tuple(-1, 0, 0);
        check[1] = List.of(new Pair(0, -1), new Pair(0,0));
        after[1] = new Tuple(0, -1, 0);
        check[2] = List.of(new Pair(0, 1), new Pair(0,2));
        after[2] = new Tuple(0, 1, 0);
        check[3] = List.of(new Pair(1, 0), new Pair(1,1));
        after[3] = new Tuple(1, 0, 0);
        // 가로 회전
        check[4] = List.of(new Pair(-1, 0), new Pair(-1, 1), new Pair(0,0), new Pair(0, 1));
        after[4] = new Tuple(-1, 0, 1);
        check[5] = List.of(new Pair(-1, 0), new Pair(-1, 1), new Pair(0,0), new Pair(0, 1));
        after[5] = new Tuple(-1, 1, 1);
        check[6] = List.of(new Pair(0, 0), new Pair(0, 1), new Pair(1,0), new Pair(1, 1));
        after[6] = new Tuple(0, 0, 1);
        check[7] = List.of(new Pair(0, 0), new Pair(0, 1), new Pair(1,0), new Pair(1, 1));
        after[7] = new Tuple(0, 1, 1);
        // 세로 이동
        check[8] = List.of(new Pair(-1,0), new Pair(0, 0));
        after[8] = new Tuple(-1, 0, 1);
        check[9] = List.of(new Pair(0, -1), new Pair(1,-1));
        after[9] = new Tuple(0, -1, 1);
        check[10] = List.of(new Pair(0, 1), new Pair(1,1));
        after[10] = new Tuple(0, 1, 1);
        check[11] = List.of(new Pair(1, 0), new Pair(2,0));
        after[11] = new Tuple(1, 0, 1);
        // 세로 회전
        check[12] = List.of(new Pair(0, -1), new Pair(0, 0), new Pair(1,-1), new Pair(1, 0));
        after[12] = new Tuple(1, -1, 0);
        check[13] = List.of(new Pair(0, -1), new Pair(0, 0), new Pair(1,-1), new Pair(1, 0));
        after[13] = new Tuple(0, -1, 0);
        check[14] = List.of(new Pair(0, 0), new Pair(0, 1), new Pair(1,0), new Pair(1, 1));
        after[14] = new Tuple(1, 0, 0);
        check[15] = List.of(new Pair(0, 0), new Pair(0, 1), new Pair(1,0), new Pair(1, 1));
        after[15] = new Tuple(0, 0, 0);
    }

    public int solution(int[][] board) {
        N = board.length;
        arr = board;
        visited = new int[N][N][2];
        check = new List[16];
        after = new Tuple[16];
        setting();

        q.add(new Tuple(0,0, 0));
        visited[0][0][0] = 1;
        return bfs();
    }
}