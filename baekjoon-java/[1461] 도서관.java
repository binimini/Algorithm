import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
import static java.lang.Math.max;

public class Main {
    static int N,M, ANS, MAXI = 0;
    static ArrayList<Integer> plus = new ArrayList<>();
    static ArrayList<Integer> minus = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i<N; i++){
            int temp = Integer.parseInt(st.nextToken());

            if (temp>0){
                plus.add(temp);
            }
            else {
                minus.add(-temp);
            }
        }

        solve(plus);
        solve(minus);
        System.out.println(ANS-MAXI);
    }

    static void solve(ArrayList<Integer> arr){
        Collections.sort(arr);
        for (int i = arr.size()-1; i>=0; i-=M){
            ANS += arr.get(i)*2;
        }
        if (!arr.isEmpty()) {
            MAXI = max(MAXI, arr.get(arr.size() - 1));
        }
    }
}
