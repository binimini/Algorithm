import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static int[] dp = new int[1001];

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Integer N = Integer.parseInt(br.readLine());
        for (int i = 0; i<N; i++){
            System.out.println(solve(Integer.parseInt(br.readLine())));
        }
    }

    static int solve(int n){
        if (n<1) return 0;
        if (n==1) return 1;
        if (dp[n]!=0) return dp[n];

        dp[n] = 1;
        for (int i = n-2; i>=0; i-=2){
            dp[n]+= solve((n-i)/2);
        }
        return dp[n];
    }
}
