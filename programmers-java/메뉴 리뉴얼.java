import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    static void solve(int N, int cnt, int cur, int status) {
        if (cnt == N) {
            int orderCnt = 0;
            for (int i = 0; i<arr.length; i++) {
                if ((arr[i]|status) == arr[i]) orderCnt++;
            }
            if (orderCnt>=2 && orderCnt>=maxi[N]) {
                if (orderCnt>maxi[N]){
                    maxi[N] = orderCnt;
                    res[N].clear();
                }
                res[N].add(status);
            }
            return;
        }
        for (int i = cur; i<26; i++) {
            if ((status&(1<<i))!=0) continue;
            solve(N, cnt+1, i, status|(1<<i));
        }
    }
    static int[] maxi = new int[11];
    static List<Integer>[] res = new List[11];
    static int[] arr;
    public String[] solution(String[] orders, int[] course) {
        arr = new int[orders.length];
        for (int i = 0; i<orders.length; i++){
            int temp = 0;
            for (int j = 0; j < orders[i].length(); j++){
                temp |= (1<<(orders[i].charAt(j)-'A'));
            }
            arr[i] = temp;
        }

        for (int i = 0; i<course.length; i++) {
            res[course[i]] = new ArrayList<>();
            maxi[course[i]] = 1;
            solve(course[i], 0, 0, 0);
        }

        List<String> result = new ArrayList<>();
        for (int i = 0; i<course.length; i++) {
            for (int j = 0; j<res[course[i]].size(); j++) {
                StringBuilder temp = new StringBuilder();
                for (int k = 0; k<26; k++) {
                    if ((res[course[i]].get(j) & (1<<k))!=0) {
                        temp.append((char) ('A' + k));
                    }
                }
                result.add(temp.toString());
            }
        }
        String[] strArr = result.toArray(String[]::new);
        Arrays.sort(strArr);
        return strArr;
    }
}