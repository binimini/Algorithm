#include <iostream>
#include <vector>
using namespace std;
int n, m, sum = 0, visited[501] = { 0 };
vector<int> child[501];
void DFS(int node, int cnt) {
    if (cnt == 2) return;
    for (int i = 0; i < child[node].size(); i++) {
        if (!visited[child[node][i]]) {
            sum++, visited[child[node][i]] = 1;
        }
        DFS(child[node][i], cnt + 1);
    }
}
int main() {
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    cin >> n >> m;
    int p, c, temp;
    for (int i = 0; i < m; i++) {
        cin >> p >> c;
        child[p].push_back(c);
        child[c].push_back(p);
    }
    visited[1] = 1;
    DFS(1, 0);
    cout << sum;
    return 0;
}