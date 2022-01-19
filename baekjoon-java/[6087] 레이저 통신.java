import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int H,W,X,Y,DX,DY;
    static char[][] arr;
    static int[][] d = {{1,0},{0,1},{-1,0},{0,-1}};
    static class Node{
        int x;
        int y;
        int z;
        int v;
        public Node(int x, int y, int z, int v){
            this.x = x;
            this.y = y;
            this.z = z;
            this.v = v;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        H = Integer.parseInt(st.nextToken());
        W = Integer.parseInt(st.nextToken());

        boolean first = true;
        arr = new char[W][H];
        for (int i = 0; i<W; i++){
            st = new StringTokenizer(br.readLine());
            String temp = st.nextToken();
            for (int j = 0; j<H; j++){
                arr[i][j] = temp.charAt(j);

                if (arr[i][j]=='C'&& first){
                    first = false;
                    X = i;
                    Y = j;
                    arr[i][j] = '.';
                }
                else if (arr[i][j]=='C'&&!first){
                   DX = i;
                   DY = j;
                }
            }
        }
        System.out.println(bfs());
    }

    static int bfs(){
        int[][] visited = new int[W][H];
        Queue<Node> q = new LinkedList<>();
        visited[X][Y] = 1;
        for (int i =0; i<4; i++){
            q.add(new Node(X,Y,i,1));
        }

        while(!q.isEmpty()){
            int x = q.peek().x;
            int y = q.peek().y;
            int z = q.peek().z;
            int v = q.peek().v;
            q.poll();

            if (visited[x][y]!=v) continue; // 다른 방향에 의해 작아졌을 수 있을 수 있다

            for (int i = 0; i<4; i++){
                int nx = x+ d[i][0];
                int ny = y+ d[i][1];
                if (nx<0 || nx>W-1 || ny<0 || ny>H-1) continue;
                if (arr[nx][ny]=='*') continue;

                int temp = z==i ? visited[x][y] : visited[x][y]+1; // 방향 꺾을 경우 거울 사용
                if (visited[nx][ny]==0 || (visited[nx][ny]!=0 && temp<=visited[nx][ny])) { // 다른 방향도 체크해야하므로 같을 경우 포함
                    visited[nx][ny] = temp;
                    q.add(new Node(nx, ny, i, visited[nx][ny]));
                }
            }
        }

        return visited[DX][DY]-1;
    }
}
