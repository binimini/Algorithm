import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {
    static int N, INF = 987654321;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());

        int[][] o = new int[N][N];
        int[][] d = new int[N][N];
        for (int i = 0; i<N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j<N; j++) {
                 o[i][j] = Integer.parseInt(st.nextToken());
                 d[i][j] = o[i][j];
            }
        }

        for (int k = 0; k<N; k++) {
            for (int i = 0; i<N; i++) {
                for (int j = 0; j<N; j++) {
                    if (i==k || j==k ) continue;
                    if (o[i][j] == o[i][k] + o[k][j]){
                        d[i][j] = INF;
                    }
                }
            }
        }
        int[][] res = new int[N][N];
        boolean IMP = false;
        int SUM = 0;
        for (int i = 0; i<N; i++) {
            for (int j = 0; j<N; j++) {
                if (d[i][j] != INF) SUM += d[i][j];
            }
        }
        for (int k = 0; k<N; k++) {
            for (int i = 0; i<N; i++) {
                for (int j = 0; j<N; j++) {
                    if (i==k || j==k ) continue;
                    if (d[i][j] > d[i][k] + d[k][j]){
                        d[i][j] = d[i][k] + d[k][j];
                    }
                }
            }
        }
        for (int i = 0; i<N; i++) {
            for (int j = 0; j<N; j++) {
                if (d[i][j] != o[i][j]) {
                    IMP = true;
                    break;
                }
            }
        }
        if (IMP) System.out.println(-1);
        else System.out.println(SUM/2);
    }
}