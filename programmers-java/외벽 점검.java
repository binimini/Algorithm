import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import static java.lang.Math.min;

class Solution {
    static void check(int node){
        if (node==arr.length) {
            int dist = 0;
            List<Integer> d = new ArrayList<>();
            for (int i = 0; i<arr.length; i++){
                if (connect[i]) {
                    if (i==arr.length-1) {
                        dist += N-arr[i]+arr[0];
                        if (d.size()!=0) {
                            d.set(0, dist + d.get(0));
                        }
                        else{
                            d.add(dist);
                        }
                    }
                    else {
                        dist += (arr[i+1]-arr[i]);
                    }
                }
                else {
                        d.add(dist);
                        dist = 0;

                }
            }
            int idx = friend.length-1;
            Collections.sort(d);

            for (int i = d.size()-1; i>=0; i--){
                if (idx<0) return;
                if (friend[idx]<d.get(i)) return;
                idx--;
            }
            RES = min(RES, friend.length-1 - idx);
            return;
        }

        for (int i = node; i<arr.length; i++) {
            connect[i] = true;
            check(i+1);
            connect[i] = false;
            check(i+1);
        }
    }

    static int N, INF = 987654321, RES = INF;
    static int[] arr, friend;
    static boolean[] connect;
    public int solution(int n, int[] weak, int[] dist) {
        N = n;
        arr = weak;
        friend = dist;
        connect = new boolean[arr.length];
        Arrays.sort(friend);

        check(0);

        return RES==INF ? -1 : RES;
    }
}