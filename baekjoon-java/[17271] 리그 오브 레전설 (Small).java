import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static int[] dp = new int[10001];
    static int N,M;
    static int MOD = 1000000007;

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        System.out.println(solve(N));
    }

    static int solve(int n){
        dp[0] = 1;
        for (int i = 1; i<=n; i++){
            dp[i] = i-M <0 ? dp[i-1]%MOD : (dp[i-1]%MOD + dp[i-M]%MOD)%MOD;
        }
        return dp[n];
    }
}
