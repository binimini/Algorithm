import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

import static java.lang.Math.min;

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
public class Main {
    static int[][][] visited;
    static boolean[][] arr;
    static Queue<Tuple> q = new LinkedList<>();
    static int N,M,K;
    static int[][] d = {{1,0},{-1,0},{0,1},{0,-1}};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        visited = new int[N][M][K+1];
        arr = new boolean[N][M];
        for (int i = 0; i<N; i++){
            st = new StringTokenizer(br.readLine());
            String temp = st.nextToken();
            for (int j = 0; j<M; j++){
                if (temp.charAt(j)=='1') arr[i][j] = true;
                else arr[i][j] = false;
            }
        }
        bfs();
        int INF = 987654321;
        int ANS = INF;
        for (int i = 0; i<=K; i++){
            if (visited[N-1][M-1][i]!=0) {
                ANS = min(ANS, visited[N - 1][M - 1][i]);
            }
        }
        if (ANS==INF) System.out.print(-1);
        else System.out.print(ANS);
    }

    static void bfs(){
        q.add(new Tuple(0,0, K));
        visited[0][0][K] = 1;
        while(!q.isEmpty()){
            int x = q.peek().x;
            int y = q.peek().y;
            int z = q.peek().z;
            q.poll();

            for (int i = 0; i<4; i++){
                int nx = x+d[i][0];
                int ny = y+d[i][1];
                int nz = z;
                if (nx<0||nx>N-1||ny<0||ny>M-1) continue;
                if (arr[nx][ny]==false && visited[nx][ny][nz]==0){
                    visited[nx][ny][nz] = visited[x][y][z]+1;
                    q.add(new Tuple(nx,ny,nz));
                }
                if (arr[nx][ny]==true && z!=0){
                    nz = z-1;
                    if (visited[nx][ny][nz]==0){
                        visited[nx][ny][nz] = visited[x][y][z]+1;
                        q.add(new Tuple(nx,ny,nz));
                    }
                }
            }
        }
    }
}
