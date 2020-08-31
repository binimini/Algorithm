#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N, M, parent[50001], visited[50001] = { 0 };
pair<int, int> arr[10000];
vector<int> child[50001];
queue<int> q;
void find_parent() {
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int i = 0; i < child[node].size(); i++) {
            if (visited[child[node][i]]) continue;
            visited[child[node][i]] = 1;
            parent[child[node][i]] = node;
            q.push(child[node][i]);
        }
    }
}
void parent_search() {
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        visited[node]++;
        if (visited[node] == 2) {
            while (!q.empty()) {
                q.pop();
            }
            cout << node << "\n";
            return;
        }
        if (node == 1)
            return;
        q.push(parent[node]);
    }
}
int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    int a, b;
    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b;
        child[a].push_back(b);
        child[b].push_back(a);
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    q.push(1);
    visited[1] = 1;
    find_parent();
    for (int i = 0; i < M; i++) {
        for (int j = 1; j <= N; j++) {
            visited[j] = 0;
        }
        q.push(arr[i].first);
        parent_search();
        q.push(arr[i].second);
        parent_search();
    }
    return 0;
}