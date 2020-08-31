#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> child[20001];
int T, V, E, CH = 0;
int visited[20001] = { 0 };
queue<int> q;
void BFS() {
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int i = 0; i < child[node].size(); i++) {
            if (visited[child[node][i]]) {
                if (visited[child[node][i]] == visited[node]) {
                    CH = 1;
                    while (!q.empty()) {
                        q.pop();
                    }
                    return;
                }
                continue;
            }
            visited[child[node][i]] = (-1) * visited[node];
            q.push(child[node][i]);
        }
    }
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> V >> E;
        CH = 0;
        int a, b;
        for (int j = 0; j < E; j++) {
            cin >> a >> b;
            child[a].push_back(b);
            child[b].push_back(a);
        }
        for (int j = 1; j <= V; j++) {
            if (CH == 1) {
                cout << "NO" << "\n";
                break;
            }
            if (visited[j]) continue;
            visited[j] = 1;
            q.push(j);
            BFS();
        }
        if (CH == 0)
            cout << "YES" << "\n";
        for (int k = 1; k <= V; k++) {
            visited[k] = 0;
            child[k].clear();
        }
    }
    return 0;
}