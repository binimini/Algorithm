import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

import static java.lang.Math.max;
import static java.lang.Math.min;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int INF = 987654321;
        int[][] dist = new int[N+1][N+1];
        for (int i = 1; i<=N; i++){
            Arrays.fill(dist[i], INF);
        }

        int u = 0, v = 0;
        while(true){
            st = new StringTokenizer(br.readLine());
            u = Integer.parseInt(st.nextToken());
            v = Integer.parseInt(st.nextToken());

            if (u==-1 && v==-1) break;
            dist[u][v] = 1;
            dist[v][u] = 1;
        }
        for (int i = 1; i<=N; i++){
            dist[i][i] = 0;
        }
        for (int k =1; k<=N; k++) {
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j<=N; j++){
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }

        ArrayList<Integer> ans = new ArrayList<>();
        int MINI = INF, MAXI = 0;
        for (int i = 1; i<=N; i++){
            MAXI = 0;
            for (int j = 1; j<=N; j++){
                if (dist[i][j]!=INF){
                    MAXI = max(MAXI, dist[i][j]);
                }
            }
            if (MAXI<MINI){
                MINI = MAXI;
                ans.clear();
                ans.add(i);
            }
            else if (MAXI==MINI){
                ans.add(i);
            }
        }

        System.out.println(MINI+" "+ans.size());
        Collections.sort(ans);
        for (int n : ans){
            System.out.print(n+" ");
        }
    }
}
