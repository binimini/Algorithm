import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int V,E, INF = 4000001;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        V = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());

        int[][] dist = new int[V+1][V+1];
        for (int [] d : dist) {
            Arrays.fill(d, INF);
        }

        for (int i = 0; i<E; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            dist[a][b] = c;
        }
        for (int k = 1; k<=V; k++) {
            for (int i = 1; i<=V; i++){
                for (int j = 1; j<=V; j++) {
                    dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        int RES = INF;
        for (int i =1; i<=V; i++) {
            RES = Math.min(RES, dist[i][i]);
        }
        if (RES==INF)
            System.out.println(-1);
        else
            System.out.println(RES);
    }
}