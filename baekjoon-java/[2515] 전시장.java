import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

import static java.lang.Math.max;

public class Main {
    static int N,S;
    static int[] dp = new int[300000];
    static int[][] arr;

    static int lb(int s, int k){
        int e = N, m;
        while(e-s>0){
            m = (s+e)/2;
            if (arr[m][0]<k){
                s = m+1;
            }
            else
                e = m;
        }
        return e;
    }

    static int solve(int idx){
        if (idx>=N) return 0;
        if (dp[idx]!=-1) return dp[idx];

        dp[idx] = 0;
        int nextIdx = lb(idx+1, arr[idx][0]+S);

        dp[idx] = max(dp[idx], solve(idx+1));
        dp[idx] = max(dp[idx], solve(nextIdx)+ arr[idx][1]);

        return dp[idx];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        S = Integer.parseInt(st.nextToken());

        arr = new int[N][2];
        for (int i = 0; i<N; i++){
            st = new StringTokenizer(br.readLine());
            arr[i][0] = Integer.parseInt(st.nextToken());
            arr[i][1] = Integer.parseInt(st.nextToken());
        }

        Arrays.fill(dp, -1);
        Arrays.sort(arr, (o1, o2) -> {
            if (o1[0]==o2[0]){
                return Integer.compare(o2[1],o1[1]);
            }
            else return Integer.compare(o1[0],o2[0]);
        });


        System.out.println(solve(0));
    }
}
