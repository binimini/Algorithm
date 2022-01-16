import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

import static java.lang.Math.max;

public class Main {
    static int T,W,BASE = 1001;
    static int[][][] dp = new int[1001][31][2];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        T = Integer.parseInt(st.nextToken());
        W = Integer.parseInt(st.nextToken());

        dp[0][W][0] = BASE;
        int temp;
        for (int i = 1; i<=T; i++){
            st = new StringTokenizer(br.readLine());
            temp = Integer.parseInt(st.nextToken())-1;

            for (int j = 0; j<=W; j++){
                if (j==W){
                    dp[i][j][0] = dp[i-1][j][0];
                    dp[i][j][1] = dp[i-1][j][1];
                }
                else {
                    dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j + 1][1]);
                    dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j + 1][0]);
                }
                dp[i][j][temp] += 1;
            }
        }

        int ans = 0;
        for (int j = 0; j<=W; j++){
            ans = max (ans, max(dp[T][j][0], dp[T][j][1]));
        }
        System.out.println(ans-BASE);
    }
}
