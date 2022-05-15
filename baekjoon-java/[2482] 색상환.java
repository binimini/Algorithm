import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main {
    static int MOD = 1000000003;
    static int dp[][] = new int[1001][1001];
    static int solve(int n, int k) {
        if (n<=0||k<=0) return 0;
        if (k==1) return n;
        if (dp[n][k] != -1) return dp[n][k];
        return dp[n][k] = (solve(n-1, k) + solve(n-2, k-1))%MOD;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int K = Integer.parseInt(br.readLine());

        for (int i = 0; i<=N; i++) {
            for (int j = 0; j<=K; j++) {
                dp[i][j] = -1;
            }
        }
        if (K==1) System.out.println(N);
        else System.out.println((solve(N-1, K) + solve(N-3, K-1))%MOD);
    }
}