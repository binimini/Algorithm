import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Pair {
    int x;
    int y;
    Pair(int x, int y){
        this.x = x;
        this.y = y;
    }
}
public class Main {
    static int N, M, F, X, Y, ANS, INF = 987654321;
    static boolean FLAG = true;
    static boolean[][] arr;
    static int[][] d = {{1,0},{0,1},{-1,0},{0,-1}};
    static Pair[][] info;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        F = Integer.parseInt(st.nextToken());

        arr = new boolean[N+1][N+1];
        for (int i = 1; i<=N; i++){
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j<=N; j++){
                arr[i][j] = Integer.parseInt(st.nextToken())==1 ? true: false;
            }
        }

        st = new StringTokenizer(br.readLine());
        X = Integer.parseInt(st.nextToken());
        Y = Integer.parseInt(st.nextToken());

        info = new Pair[M][2];
        for (int i = 0; i<M; i++){
            st = new StringTokenizer(br.readLine());
            info[i][0] = new Pair(Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken()));
            info[i][1] = new Pair(Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken()));
        }

        while(FLAG){
            solve();
        }
        System.out.println(ANS);
    }

    static void solve(){
        Pair customer = bfs();
        int remain = 0;
        for (int i= 0; i<M; i++){
            if (info[i][0].x!=0) remain++;
        }

        if (customer.x==-1 || F<customer.y){
            FLAG = false;
            if (remain==0) ANS = F;
            else ANS = -1;
        }
        else {
            int distToDest = bfs(info[customer.x][0].x, info[customer.x][0].y, info[customer.x][1].x, info[customer.x][1].y);
            info[customer.x][0].x = 0;
            F-= customer.y;
            if (F<distToDest|| distToDest<0){
                FLAG = false;
                ANS = -1;
            }
            else{
                F += distToDest;
                X = info[customer.x][1].x;
                Y = info[customer.x][1].y;
            }
        }
    }

    static Pair bfs(){
        int[][] visited = new int[N+1][N+1];
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(X,Y));
        visited[X][Y] = 1;
        while(!q.isEmpty()){
            Pair cur = q.poll();
            for (int i = 0; i<4; i++){
                int nx = cur.x+d[i][0];
                int ny = cur.y+d[i][1];
                if (nx<1||nx>N||ny<1||ny>N) continue;
                if (arr[nx][ny]) continue;
                if (visited[nx][ny]!=0) continue;
                visited[nx][ny] = visited[cur.x][cur.y]+1;
                q.add(new Pair(nx,ny));
            }
        }

        Pair mini = new Pair(-1, INF);
        for (int i = 0; i<M; i++){
            if (info[i][0].x==0) continue;
            if (visited[info[i][0].x][info[i][0].y]==0) continue;
            if (visited[info[i][0].x][info[i][0].y]-1<mini.y){
                mini.x = i;
                mini.y = visited[info[i][0].x][info[i][0].y]-1;
            }
            else if (visited[info[i][0].x][info[i][0].y]-1==mini.y){
                if (info[mini.x][0].x> info[i][0].x) mini.x = i;
                else if (info[mini.x][0].x == info[i][0].x && info[mini.x][0].y > info[i][0].y) mini.x = i;
            }
        }
        return mini;
    }

    static int bfs(int x, int y, int dx, int dy){
        int[][] visited = new int[N+1][N+1];
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(x,y));
        visited[x][y] = 1;
        while(!q.isEmpty()){
            Pair cur = q.poll();

            for (int i = 0; i<4; i++){
                int nx = cur.x+d[i][0];
                int ny = cur.y+d[i][1];
                if (nx<1||nx>N||ny<1||ny>N) continue;
                if (arr[nx][ny]) continue;
                if (visited[nx][ny]!=0) continue;
                visited[nx][ny] = visited[cur.x][cur.y]+1;
                q.add(new Pair(nx,ny));
            }
        }
        return visited[dx][dy]-1;
    }
}
