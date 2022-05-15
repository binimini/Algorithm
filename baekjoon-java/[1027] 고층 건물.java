import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

import static java.lang.Math.max;
import static java.lang.Math.min;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int maxiSee = 0;
        int[] num = new int[N+1];
        for (int i = 1; i<=N; i++) {
            num[i] = Integer.parseInt(st.nextToken());
        }

        for (int i = 1; i<=N; i++) {
            int see = 0;
            for (int j = 1; j<=N; j++) {
                if (i==j) continue;
                boolean flag = true;
                for (int k = min(i,j)+1; k< max(i,j); k++) {
                    double deg = (double)(num[j] - num[i])/(j-i);
                    double standard = deg*(k-min(i,j))+num[min(i,j)];
                    if ((double) num[k] >= standard) {
                        flag = false;
                    }
                }
                if (flag) {
                    see++;
                }
            }
            if (see > maxiSee) {
                maxiSee = see;
            }
        }
        System.out.println(maxiSee);
    }
}