import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    static class Pair {
        int x;
        int y;
        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
    static int INF = 987654321;
    static void bfs(int start) {
        dist = new int[N+1];
        for (int i = 1; i<=N; i++){
            dist[i] = INF;
        }
        PriorityQueue<Pair> pq = new PriorityQueue<>((Pair a, Pair b)-> a.x > b.x ? 1:-1 );
        pq.add(new Pair(0, start));
        dist[start] = 0;
        while(!pq.isEmpty()) {
            int xc = pq.peek().x;
            int x = pq.peek().y;
            pq.poll();
            if (xc > dist[x]) continue;

            for (int i = 0; i<edge[x].size(); i++) {
                int n = edge[x].get(i).x;
                int nc = edge[x].get(i).y;
                if (dist[n] > xc + nc) {
                    dist[n] = xc + nc;
                    pq.add(new Pair(dist[n], n));
                }
            }
        }
    }

    static int T,N,D,S;
    static List<Pair>[] edge;
    static int[] dist;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        T = Integer.parseInt(st.nextToken());
        for (int t= 0; t<T; t++) {
            st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            D = Integer.parseInt(st.nextToken());
            S = Integer.parseInt(st.nextToken());
            edge = new List[N+1];
            for (int i = 1; i<=N; i++) {
                edge[i] = new ArrayList<Pair>();
            }
            for (int i = 0; i<D; i++) {
                st = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                int s = Integer.parseInt(st.nextToken());
                edge[b].add(new Pair(a, s));
            }

            bfs(S);
            int cnt = 0, d = 0;
            for (int i = 1; i<=N; i++) {
                if (dist[i]==INF) continue;
                cnt++;
                d = Math.max(d, dist[i]);
            }
            System.out.println(cnt+" "+d);
        }
    }
}