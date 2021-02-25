#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int V, E, cnt = 0;
int visited[100001] = { 0 };
vector<int> edge[100001];
vector<pair<int, int>> cutedge;
int dfs(int node, int parent) {
    int ret = visited[node];
    for (int i = 0; i < edge[node].size(); i++) {
        int next = edge[node][i];
        if (next == parent) continue;//부모(u->v에서 dfs(v)에서 u) 예외처리 안할시 
        //visited[u]가 low 범위에 들어가(양방향그래프라서) 무조건 절단선 아니게 됨!!!
        
        if (!visited[next]) {//이미 방문한 node는 현재 간선 아닌 다른 경로가 있다는 것(그래프는 이어져있다는 가정하에!!)=> 따라서 체크필요X?
            visited[next] = ++cnt;
            int low = dfs(next, node);
            if (visited[node] < low) {// u -> v 간선에서 v를 통한 최소 visited값은 v이상이어야한다.
                //즉 visited[u]<visited[v]<=low 인것 visited[u]>=low의 경우 우회로가 존재한다는 의미이므로 절단선일 수 없다.
                cutedge.push_back({ min(node, next), max(node, next) });
            }
            ret = min(ret, low);
        }
        else
            ret = min(ret, visited[next]);
    }
    return ret;
}
int main() {
    FASTIO;
    cin >> V >> E;
    int a, b;
    for (int i = 0; i < E; i++) {
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    for (int i = 1; i <= V; i++) {
        if (!visited[i]) {
            visited[i] = ++cnt;
            dfs(i, 0);
        }
    }
    sort(cutedge.begin(), cutedge.end());
    cout << cutedge.size() << "\n";
    for (int i = 0; i < cutedge.size(); i++) {
        cout << cutedge[i].first << " " << cutedge[i].second << "\n";
    }
    return 0;
}