#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int V, E, cnt = 1;
bool iscutv[10001] = { 0 };
int visited[10001] = { 0 };
vector<int> edge[10001];
int dfs(int node, bool root) {//단절점과 단절선 //양방향 간선이므로 일방 dfs스패닝트리를 만들어 접근한다!!
    int ret = visited[node];
    int child = 0;
    //더 갈 곳 없을 경우 dfs 여기서 끝나므로 단절점 아니게됨
    for (int i = 0; i < edge[node].size(); i++) {
        int next = edge[node][i];
        if (!visited[next]) {
            child++;
            visited[next] = cnt++;
            int low = dfs(next, 0);
            if (!root && low >= visited[node]) {//node의 자식노드가 visited[node] 이전 노드에 방문할 수 없다면 절단점
                //(dfs 값 사이클 같은 경우 자기자신까지 가능)
                //(우회로 존재하는 다른 자식노드 있을 수 있지만 이미 connected component 늘어나게 되므로 cutv)
                //if low<visited[node] 우회로 존재 -> cutv가 아님으로 판정 시 우회로 존재하지않는 자식노드 있음에도 notcutv로 판정 가능 주의!!
                iscutv[node] = 1;
            }
            ret = min(ret, low);
        }
        else
            ret = min(ret, visited[next]);//이미 방문한 점이어도 이전값 확인은 해야함
    }
    //root의 경우 !visited[next]인 개수 세서 판정해야한다 왜 edge[node].size()로 판정하면 안될까??
    //-> ex) 루트가 사이클 내 점일 경우 edge[node].size는 2이지만 루트를 끊어내도 connected component는 하나다.
    if (root)
        iscutv[node] = (child >= 2);
    return ret;
}
int main() {
    FASTIO;
    cin >> V >> E;
    int a, b;
    for (int i = 0; i < E; i++) {
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);//양방향 그래프
    }

    for (int i = 1; i <= V; i++) {
        if (!visited[i]) {
            visited[i] = cnt++;
            dfs(i, 1);
        }
    }
    vector<int> result;
    int res = 0;
    for (int i = 1; i <= V; i++) {
        if (iscutv[i]) {
            res++;
            result.push_back(i);
        }
    }
    cout << res << "\n";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}