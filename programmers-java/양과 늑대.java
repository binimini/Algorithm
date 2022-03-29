import java.util.ArrayList;
import java.util.List;

class Solution {
    static int N, ANS;
    static int[] vertex;
    static List<Integer>[] edge;
    static boolean[][][] visited;
    static void dfs(int node, int sheep, int wolf) {
        ANS = Math.max(ANS, sheep);

        for (int i = 0; i<edge[node].size(); i++){
            int value = vertex[node];
            int next = edge[node].get(i);
            int nsheep = value==0 ? sheep+1 : sheep;
            int nwolf = value==1 ? wolf+1 : wolf;

            if (nwolf >= nsheep) continue;
            if (visited[next][nsheep][nwolf]) continue;

            visited[next][nsheep][nwolf] = true;
            vertex[node] = -1;
            dfs(next, nsheep, nwolf);
            vertex[node] = value;
            visited[next][nsheep][nwolf] = false;
        }
    }

    public int solution(int[] info, int[][] edges) {
        N = info.length;
        edge = new List[N];
        vertex = info;
        visited = new boolean[N][20][20];
        for (int i=0; i<N; i++){
            edge[i] = new ArrayList<>();
        }
        for (int[] relation: edges){
            edge[relation[0]].add(relation[1]);
            edge[relation[1]].add(relation[0]);
        }

        dfs(0,0,0);
        return ANS;
    }
}