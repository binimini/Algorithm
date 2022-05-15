import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    static class Pair {
        int node;
        int prev;
        public Pair(int node, int prev) {
            this.node = node;
            this.prev = prev;
        }
    }
    static int N, M;
    static List<Integer>[] edge;
    static int[] visited = new int[501];
    static String bfs() {
        int tCnt = 0, cnt = 0;
        boolean isTree = true;
        Queue<Pair> q = new LinkedList<>();
        for (int i = 1; i<=N; i++) {
            if (visited[i] !=0) continue;
            cnt++;
            visited[i] = cnt;
            isTree = true;
            q.add(new Pair(i,0));
            while(!q.isEmpty()) {
                int x = q.peek().node;
                int p = q.peek().prev;
                q.poll();

                for (int j = 0; j<edge[x].size(); j++) {
                    if (visited[edge[x].get(j)]==0) {
                        visited[edge[x].get(j)] = cnt;
                        q.add(new Pair(edge[x].get(j), x));
                    }
                   else if (edge[x].get(j)!=p && visited[edge[x].get(j)]==cnt) {
                       isTree = false;
                    }
                }
            }
            if (isTree) tCnt++;
        }
        if (tCnt==0) return "No trees.";
        else if (tCnt==1) return "There is one tree.";
        else return "A forest of "+tCnt+" trees.";
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int caseCnt = 1;
        while(true) {

            StringTokenizer st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());
            if (N==0 && M ==0) break;

            edge = new List[N+1];
            for (int i = 1; i <= N; i++) {
                edge[i] = new ArrayList<Integer>();
                visited[i] = 0;
            }
            for (int i = 0; i < M; i++) {
                st = new StringTokenizer(br.readLine());
                int u = Integer.parseInt(st.nextToken());
                int v = Integer.parseInt(st.nextToken());
                edge[u].add(v);
                edge[v].add(u);
            }
            System.out.println("Case "+caseCnt+": "+bfs());
            caseCnt++;
        }
    }
}