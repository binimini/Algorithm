import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

class Date {
    int month;
    int day;
    public Date(int month, int day) {
        this.month = month;
        this.day = day;
    }
}

public class Main {
    static Date[][] dates;

    static int comp(Date x, Date y) {
        if (x.month== y.month) return Integer.compare(x.day, y.day);
        else return Integer.compare(x.month, y.month);
    }
    static Date next(Date cur) {
        boolean flag = false;
        if (cur.month==2) {
            if (cur.day==28) flag = true;
        }
        else if (cur.month==4 || cur.month == 6 || cur.month==9 || cur.month ==11) {
            if (cur.day==30) flag = true;
        }
        else {
            if (cur.day == 31 && cur.month!=12) flag = true;
        }
        if (flag) {
            return new Date(cur.month+1, 1);
        }
        else return new Date(cur.month, cur.day+1);
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        dates = new Date[N][2];

        for (int i=0; i<N; i++) {
            st = new StringTokenizer(br.readLine());
            int m1 = Integer.parseInt(st.nextToken());
            int d1 = Integer.parseInt(st.nextToken());
            int m2 = Integer.parseInt(st.nextToken());
            int d2 = Integer.parseInt(st.nextToken());
            dates[i][0] = new Date(m1, d1);
            dates[i][1] = new Date(m2, d2);
        }
        Arrays.sort(dates, (a, b) -> {
            if (comp(a[0], b[0])!=0){
                return comp(a[0], b[0]);
            }
            else {
                return comp(a[1], b[1])*-1;
            }
        });
        int CNT = 0, idx = 0;
        PriorityQueue<Date> pq = new PriorityQueue<Date>((a,b)->comp(a,b)*-1);
        Date cur = new Date(3, 1);
        pq.add(cur);
        while(!pq.isEmpty()) {
            if (comp(cur, new Date(11, 30))==1){
                break;
            }
            if (comp(cur, pq.peek()) ==1) {
                pq.poll();
                continue;
            }
            cur = pq.peek();
            CNT++;
            pq.poll();
            while(idx!=N && comp(cur, dates[idx][0])!=-1) {
                pq.add(dates[idx][1]);
                idx++;
            }
        }

        if(comp(cur, new Date(11, 30))!=1) System.out.println(0);
        else System.out.println(CNT-1);
    }
}