import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

class Main {
    static int N;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());

        int[][] arr = new int[N][2];
        for (int i = 0; i<N; i++) {
            st = new StringTokenizer(br.readLine());
            arr[i][1] = Integer.parseInt(st.nextToken()); // p
            arr[i][0] = Integer.parseInt(st.nextToken()); // d
        }
        Arrays.sort(arr, (a, b) -> Integer.compare(a[0], b[0]));

        PriorityQueue<Integer> pq = new PriorityQueue<>((a,b)->Integer.compare(a,b)*-1);
        int day = 10000, idx = N-1, maxi = 0;
        while(true) {
            if (day==0) break;
            while (idx >=0 && arr[idx][0]==day) {
                pq.add(arr[idx][1]);
                idx--;
            }
            if (!pq.isEmpty()) {
                maxi += pq.peek();
                pq.poll();
            }
            day--;
        }
        System.out.println(maxi);
    }
}