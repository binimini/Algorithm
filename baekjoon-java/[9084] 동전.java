import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static int T,N,M;
    static int[] arr = new int[20];
    static int[][] dp = new int[20][10001];

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        T = Integer.parseInt(st.nextToken());
        for (int i = 0; i<T; i++){
            st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            for (int j = 0; j<N; j++){
                Arrays.fill(dp[j], -1);
            }

            st = new StringTokenizer((br.readLine()));
            for (int j = 0; j<N; j++){
                arr[j] = Integer.parseInt(st.nextToken());
            }

            st = new StringTokenizer(br.readLine());
            M = Integer.parseInt(st.nextToken());
            System.out.println(solve(N-1, M));
        }
    }

    static int solve(int n, int m){
        if (n<0 && m==0) return 1;
        if (m<0 || n<0) return 0;
        if (dp[n][m]!=-1) return dp[n][m];

        dp[n][m] = 0;
        for (int i = m/arr[n]; i>=0; i--){
            dp[n][m] += solve(n-1, m-arr[n]*i);
        }
        return dp[n][m];
    }
}
