import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

import static java.lang.Math.min;

public class Main {
    static int N, M, L, ANS;
    static int[] arr;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        L = Integer.parseInt(st.nextToken());
        ANS = L;

        st = new StringTokenizer(br.readLine());
        arr = new int[N+2];
        arr[0] = 0;
        arr[N+1] = L;
        for (int i = 1; i<=N; i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(arr);

        System.out.println(solve());
    }

    static int solve(){
        int s = 1, e = L, m;
        while(e-s>=0){
            m = (s+e)/2;
            int req = 0;
            for (int i = 0; i<N+1; i++){
                req += (arr[i+1]-arr[i])%m==0 ? (arr[i+1]-arr[i])/m-1 : (arr[i+1]-arr[i])/m;
            }
            if (req>M){
                s = m+1;
            }
            else if (req<=M){
                ANS = min(ANS, m);
                e = m-1;
            }
        }
        return ANS;
    }
}
