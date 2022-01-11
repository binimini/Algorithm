import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static long[][] dp = new long[2][21];
    static int N;
    static int[] arr;
    static int flag = 0;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());

        arr = new int[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i<N; i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }

        dp[flag][arr[0]] = 1;
        for (int i = 1; i<N-1; i++){
            flag = 1-flag;
            for (int j = 0; j<= 20; j++){
                dp[flag][j] = 0;
                if (j-arr[i]>=0 && j-arr[i]<=20) {
                    dp[flag][j] += dp[1-flag][j - arr[i]];
                }
                if (j+arr[i]>=0 && j+arr[i]<=20) {
                    dp[flag][j] += dp[1-flag][j + arr[i]];
                }
            }
        }
        System.out.println(dp[flag][arr[N-1]]);
    }
}
