#include <bits/stdc++.h>
using namespace std;
int N, M;
bool visited[1001] = { 0 };
vector<int> edge[1001];
int staff_from_task[1001] = { 0 };
bool dfs(int node) {
    if (visited[node]) return 0;
    visited[node] = 1;
    for (int i = 0; i < edge[node].size(); i++) {
        int next = edge[node][i];
        if (staff_from_task[next] == 0 || dfs(staff_from_task[next])) {
            staff_from_task[next] = node;
            return 1;
        }
    }
    return 0;
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    int size, temp;
    for (int i = 1; i <= N; i++) {
        cin >> size;
        for (int j = 0; j < size; j++) {
            cin >> temp;
            edge[i].push_back(temp);
        }
    }
    int res = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++)
            visited[j] = 0;
        if (dfs(i))
            res++;
    }
    cout << res;
    return 0;
}