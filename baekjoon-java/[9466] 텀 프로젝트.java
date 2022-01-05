import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
    static int cnt = 0, ans = 0;
    static int[] arr;
    static int[] visited;
    static Stack<Integer> s = new Stack<>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int T = Integer.parseInt(st.nextToken());
        for (int i = 0; i<T; i++){
            st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());

            arr = new int[N+1];
            st = new StringTokenizer(br.readLine());
            for (int j =1; j<=N; j++){
                arr[j] = Integer.parseInt(st.nextToken());
            }

            cnt = 0;
            ans = 0;
            visited = new int[N+1];
            for (int j = 1; j<=N; j++){
                if (visited[j]!=0) continue;
                cnt++;
                dfs(j);
                s.clear();
            }
            System.out.println(N-ans);
        }
    }

    static void dfs(int node){
        visited[node] = cnt;
        s.push(node);
        if (visited[arr[node]]==0){
            dfs(arr[node]);
        }
        else if (visited[arr[node]]!=0&&visited[arr[node]]==visited[node]){
            while(s.peek()!=arr[node]){
                ans++;
                s.pop();
            }
            ans++;
        }
        else if (visited[arr[node]]!=0 && visited[arr[node]]!= visited[node]) return;

    }
}
