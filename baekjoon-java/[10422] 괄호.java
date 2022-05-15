import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {
    static int MOD = 1000000007;
    static long [] dp;
    static long solve(int n) {
        if (n%2!=0) return 0;
        if (n==0) return 1;
        if (dp[n] > 0) return dp[n];

        for (int i = 0; i<=n-2; i+=2) {
            dp[n] += (solve(i)*solve(n-2-i))%MOD;
        }
        dp[n] = dp[n]%MOD;
        return dp[n];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        dp = new long[5001];

        int T = Integer.parseInt(st.nextToken());
        for (int i = 0; i<T; i++) {
            st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            System.out.println(solve(N));
        }
    }
}