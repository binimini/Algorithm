#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
#define FOR(i,a,b) for(int i = a; i<b; i++)
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int V, E, cnt = 0;
bool visited[10001] = { 0 };
vector<int> edge[10001], redge[10001], scc[10001];
stack<int> s;
void dfs(int x) {
    for (int i = 0; i < edge[x].size(); i++) {
        if (visited[edge[x][i]]) continue;
        visited[edge[x][i]] = 1;
        dfs(edge[x][i]);
    }
    s.push(x);
}
void rdfs(int x, int cnt) {
    for (int i = 0; i < redge[x].size(); i++) {
        if (visited[redge[x][i]]) continue;
        visited[redge[x][i]] = 1;
        scc[cnt].push_back(redge[x][i]);
        rdfs(redge[x][i], cnt);
    }
}
int main() {
    FASTIO;
    cin >> V >> E;
    int a, b;
    FOR(i, 0, E) {
        cin >> a >> b;
        edge[a].push_back(b);
        redge[b].push_back(a);
    }
    
    FOR(i,1,V+1) {
        if (visited[i]) continue;
        dfs(i);
    }
    
    FOR(i, 1, V+1) {
        visited[i] = 0;
    }
    while (!s.empty()) {
        int st = s.top();
        s.pop();
        if (visited[st]) continue;
        cnt++;
        visited[st] = 1;
        scc[cnt].push_back(st);
        rdfs(st, cnt);
    }

    vector<pair<int,int>> order;
    cout << cnt << "\n";
    FOR(i,1,cnt+1) {
        sort(scc[i].begin(), scc[i].end());
        order.push_back(make_pair(scc[i][0], i));
    }
    
    sort(order.begin(), order.end());
    FOR(i,0,order.size()) {
        FOR(j, 0, scc[order[i].second].size()) {
            cout << scc[order[i].second][j] << " ";
        }
        cout << -1 << '\n';
    }
    return 0;
}