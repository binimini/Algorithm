import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main {
    static int[][][] dp;
    static String Str, A, B;
    static int solve(int i, int j, int s) { // 문제 제대로 읽자. 돌다리에서 있을 수 있는 위치는 한 개
        if (i==Str.length()) return 1;
        if (j>=A.length()) return 0;

        if (dp[i][j][s]!=-1) return dp[i][j][s];

        dp[i][j][s] = 0;
        if (s==0) {
            if (Str.charAt(i)==B.charAt(j))
                dp[i][j][s] += solve(i+1, j+1, 1);
            dp[i][j][s] += solve(i, j+1, 0);
        }
        else if (s==1) {
            if (Str.charAt(i)==A.charAt(j))
                dp[i][j][s] += solve(i+1, j+1, 0);
            dp[i][j][s] += solve(i, j+1, 1);
        }
        return dp[i][j][s];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Str = br.readLine();
        A = br.readLine();
        B = br.readLine();

        dp = new int[Str.length()][A.length()][2];
        for (int i = 0; i<Str.length(); i++) {
            for (int a = 0; a<A.length(); a++) {
                    dp[i][a][0] = -1;
                    dp[i][a][1] = -1;
            }
        }
        System.out.println(solve(0,0,0)+solve(0,0,1));
    }
}