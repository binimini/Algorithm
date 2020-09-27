#include <iostream>
#include <vector>
using namespace std;
#define FOR(i,a,b) for(int i = a; i<b; i++)
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0);
int N, M;
bool FLAG = 0;
vector<int> edge[2000];
bool visited[2000] = { 0 };
void dfs(int node, int cnt) {
    if (cnt >= 5) {
        FLAG = 1;
        return;
    }
    FOR(i, 0, edge[node].size()) {
        if (visited[edge[node][i]]) continue;
        visited[edge[node][i]] = 1;
        dfs(edge[node][i], cnt + 1);
        visited[edge[node][i]] = 0;//사이클 돌아서 가지 않을 수 있으므로 백트래킹 필요
    }
}
int main() {
    FASTIO;
    cin >> N >> M;
    int a, b;
    FOR(i, 0, M) {
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    FOR(i, 0, N) {
        if (FLAG)
            break;
        FOR(j, 0, N) {
            visited[j] = 0;
        }
        visited[i] = 1;
        dfs(i, 1);
    }
    cout << FLAG;
    return 0;
}