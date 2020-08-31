#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> child[500000];
int leaf_num = 0, N, cnt = 0, level[500000] = { 0 };
queue<int> q;
void DFS(int node, int lev) {
    for (int i = 0; i < child[node].size(); i++) {
        if (level[child[node][i]]) continue;
        level[child[node][i]] = lev;
        DFS(child[node][i], lev + 1);
    }
}
int main() {
    cin >> N;
    int a, b;
    for (int i = 1; i < N; i++) {
        cin >> a >> b;
        child[a].push_back(b);
        child[b].push_back(a);
    }
    for (int i = 2; i <= N; i++) {
        if (child[i].size() == 1)
            leaf_num++, q.push(i);
    }
    level[1] = -1;
    DFS(1, 1);
    int sum = 0;
    while (!q.empty()) {
        int i = q.front();
        q.pop();
        sum += level[i];
    }
    if (sum % 2 == 0)
        cout << "No";
    else cout << "Yes";
    return 0;
}