import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

import static java.lang.Math.max;

class Main {
    static int N;
    static int[][] dice;
    static Map<Integer, Integer> match = new HashMap<>();
    static int MAXI = 0;
    static void solve(int bot, int idx, int val) {
        if (idx==N) {
            MAXI = max(MAXI, val);
            return;
        }
        int except = -1;
        for (int i = 0; i<6; i++) {
            if (dice[idx][i]==bot) {
                except = i; // idx (x)
            }
        }

        int temp = 0;
        for (int i = 0; i<6; i++) {
            if (except==i || match.get(except)==i) continue;
            temp = max(temp, dice[idx][i]);
        }
        solve(dice[idx][match.get(except)], idx+1, val+temp); // 현재 주사위 윗면 -> 다음 주사위 바닥면
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        dice = new int[N+1][7];
        match.put(0,5);
        match.put(5,0);
        match.put(1,3);
        match.put(3,1);
        match.put(2,4);
        match.put(4,2);

        for (int i = 0; i<N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j<6; j++) {
                dice[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for (int i = 1; i<=6; i++) {
            solve(i, 0, 0);
        }

        System.out.println(MAXI);
    }
}