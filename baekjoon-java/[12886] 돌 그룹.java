import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

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
class Main {
    static Tuple calcu(int a, int b, int c) {
        int[] s = new int[3];
        if (a<b) {
            s[0]= 2*a;
            s[1]= b-a;
        }
        else {
            s[0]= a-b;
            s[1]= 2*b;
        }
        s[2] = c;
        Arrays.sort(s);
        return new Tuple(s[0], s[1], s[2]);
    }
    static int sum;
    static boolean solve(int a, int b, int c) {
        if (sum%3!=0) return false;
        if (a==b && b==c) return true;

        boolean[][] visited = new boolean[1501][1501];

        Queue<Tuple> q = new LinkedList<>();
        q.add(new Tuple(a,b,c));
        visited[a][b] = true;
        while(!q.isEmpty()) {
            int x = q.peek().x;
            int y = q.peek().y;
            int z = q.peek().z;
            if (x==y && x==sum/3) return true;
            q.poll();

            Tuple t;
            if (x!=y) {
                t = calcu(x,y,z);
                if (!visited[t.x][t.y]){
                    visited[t.x][t.y] = true;
                    q.add(t);
                }
            }
            if (x!=z) {
                    t = calcu(x,z,y);
                    if (!visited[t.x][t.y]) {
                        visited[t.x][t.y] = true;
                        q.add(t);
                    }
            }
            if (y!=z) {
                    t = calcu(z,y,x);
                    if (!visited[t.x][t.y]){
                        visited[t.x][t.y] = true;
                        q.add(t);
                    }
            }
        }
        return false;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int A = Integer.parseInt(st.nextToken());
        int B = Integer.parseInt(st.nextToken());
        int C = Integer.parseInt(st.nextToken());
        sum = A+B+C;
        System.out.println(solve(A,B,C) ? 1:0);
    }
}