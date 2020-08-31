#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int N, M, V, visited[1001] = { 0 };
vector<int> route[1001];
void DFS(int node) {
    if (visited[node] == 1)
        return;
    else {
        cout << node << " ";
        visited[node] = 1;
        for (int i = 0; i < route[node].size(); i++) {
            DFS(route[node][i]);
        }
    }
}
void BFS() {
    queue<int> q;
    visited[V] = 1;
    cout << V << " ";
    q.push(V);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int i = 0; i < route[node].size(); i++) {
            if (visited[route[node][i]] == 1) continue;
            visited[route[node][i]] = 1;
            cout << route[node][i] << " ";
            q.push(route[node][i]);
        }
    }
}
int main() {
    cin >> N >> M >> V;
    for (int i = 0; i < M; i++) {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        route[temp1].push_back(temp2);
        route[temp2].push_back(temp1);
    }
    for (int i = 1; i <= N; i++) {
        sort(route[i].begin(), route[i].end());
    }
    DFS(V);
    cout << "\n";
    for (int i = 1; i <= N; i++) {
        visited[i] = 0;
    }
    BFS();
    return 0;
}