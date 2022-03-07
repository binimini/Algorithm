import java.util.Arrays;
import java.util.PriorityQueue;

class Solution {
    static boolean isLessThan(String s1, int h, int m, int s) {
        if (Integer.parseInt(s1.substring(0, 2)) == h) {
            if (Integer.parseInt(s1.substring(3, 5)) == m){
                return Integer.parseInt(s1.substring(6, 8)) <= s;
            }
            else return Integer.parseInt(s1.substring(3, 5)) < m;
        }
        else return Integer.parseInt(s1.substring(0, 2)) < h;
    }

    static int[] afterTime(String str, int h, int m, int s) {
        int hour = Integer.parseInt(str.substring(0, 2));
        int min = Integer.parseInt(str.substring(3, 5));
        int sec = Integer.parseInt(str.substring(6, 8));

        int[] after = new int[3];
        after[2] = (s+sec)%60;
        after[1] = (m+min+(s+sec)/60)%60;
        after[0] = h+hour+(m+min+(s+sec)/60)/60;
        return after;
    }

    long sum[][][] = new long [100][60][60];
    public String solution(String play_time, String adv_time, String[] logs) {
        Arrays.sort(logs);
        int hour = Integer.parseInt(play_time.substring(0, 2));
        int idx = 0;
        PriorityQueue<String> pq = new PriorityQueue<>();
        for (int h = 0; h<=hour; h++){
            for (int m = 0; m<=59; m++){
                for (int s = 0; s<=59; s++){
                    sum[h][m][s] = pq.size();
                    while(!pq.isEmpty() && isLessThan(pq.peek(), h, m, s)) {
                        pq.poll();
                    }
                    while(idx<logs.length && isLessThan(logs[idx], h, m, s)) {
                        pq.add(logs[idx++].substring(9));
                    }
                }
            }
        }
        long prev = -1;
        for (int h = 0; h<=hour; h++) {
            for (int m = 0; m <= 59; m++) {
                for (int s = 0; s <= 59; s++) {
                    if (prev!=-1)
                        sum[h][m][s] = prev+sum[h][m][s];
                    prev = sum[h][m][s];
                }
            }
        }

        long res = 0;
        String resStr = "";
        for (int h = 0; h<=hour; h++) {
            for (int m = 0; m <= 59; m++) {
                for (int s = 0; s <= 59; s++) {
                    int[] temp = afterTime(adv_time, h, m, s);
                    if (temp[0]<100 && sum[temp[0]][temp[1]][temp[2]] - sum[h][m][s] > res) {
                        res = sum[temp[0]][temp[1]][temp[2]] - sum[h][m][s];
                        resStr = String.format("%02d",h)+":"+String.format("%02d",m)+":"+String.format("%02d",s);
                    }
                }
            }
        }
        return resStr;
    }
}