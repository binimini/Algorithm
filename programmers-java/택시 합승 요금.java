import static java.lang.Math.min;

class Solution {
    static int[][] dist;
    static int N, INF = 587654321;
    static void floyd_warshall() {
        for (int k = 1; k<=N; k++) {
            for (int i = 1; i<=N; i++) {
                for (int j = 1; j<=N; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }
    }
    public int solution(int n, int s, int a, int b, int[][] fares) {
        N = n;
        dist = new int[N+1][N+1];
        for (int i = 1; i<=N; i++){
            for (int j =1; j<=N; j++){
                if (i==j) continue;
                dist[i][j] = INF;
            }
        }

        for (int i = 0; i<fares.length; i++){
            dist[fares[i][0]][fares[i][1]] = fares[i][2];
            dist[fares[i][1]][fares[i][0]] = fares[i][2];
        }
        floyd_warshall();

        int res = INF;
        for (int i = 1; i<=N; i++) {
            res = min(res, dist[s][i]+dist[i][a]+dist[i][b]);
        }
        return res;
    }
}