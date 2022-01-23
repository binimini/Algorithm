import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

import static java.lang.Math.max;

public class Main {
    static int N, K, W, ANS = 0;
    static int[] arr;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        arr = new int[N];
        for (int i = 0; i<N; i++){
            st = new StringTokenizer(br.readLine());
            String str = st.nextToken();
            for (int j = 0; j<str.length(); j++){
                arr[i]|=(1<<(str.charAt(j)-'a'));
            }
        }

        solve(0,0);
        System.out.println(ANS);
    }

    static void solve(int cnt, int start){
        if (cnt==K){
            int result = 0;
            for (int i =0; i<N; i++){
                if ((arr[i]|W)==W) result++;
            }
            ANS = max(ANS, result);
            return;
        }
        for (int i = start; i<26; i++){
            if ((W&(1<<i))!=0) continue;
            W|=(1<<i);
            solve(cnt+1, i+1);
            W&=~(1<<i);
        }
    }
}
