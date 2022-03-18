import java.util.PriorityQueue;

import static java.lang.Math.min;

class Pair {
    int idx;
    int value;
    public Pair(int idx, int value) {
        this.idx = idx;
        this.value = value;
    }
}
class Solution {
    static int slidingWindow() {
        int result = 200000001;

        PriorityQueue<Pair> pq = new PriorityQueue<>((a, b)-> b.value - a.value);
        for (int i = 0; i<K; i++){
            pq.add(new Pair(i, stone[i]));
        }
        result = min(result, pq.peek().value);

        for (int i = K; i<N; i++){
            while(!pq.isEmpty() && pq.peek().idx < i-K+1) pq.poll();

            pq.add(new Pair(i, stone[i]));
            result = min(result, pq.peek().value);
        }
        return result;
    }

    static int N, K;
    static int[] stone;
    public int solution(int[] stones, int k) {
        N = stones.length;
        K = k;
        stone = stones;

        return slidingWindow();
    }
}