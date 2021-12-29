import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

import static java.lang.Math.max;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());

        int[] arr = new int[N];
        int[] idx = new int[N+1];
        for (int i =0; i<N; i++){
            int value = Integer.parseInt(st.nextToken());
            arr[i] = value;
            idx[value] = i;
        }

        int ans = 0;
        for (int i=N; i>1; i--){
            int index = idx[i];
            int left = index-1;
            int maxi = 0;
            while(left>=0){
                if (arr[left]!=0){
                    maxi = max(maxi, arr[left]);
                    break;
                }
                left--;
            }
            int right = index+1;
            while(right<=N-1){
                if (arr[right]!=0){
                    maxi = max(maxi, arr[right]);
                    break;
                }
                right++;
            }
            arr[index] = 0;
            ans+= i-maxi;
        }
        System.out.println(ans);
    }
}
