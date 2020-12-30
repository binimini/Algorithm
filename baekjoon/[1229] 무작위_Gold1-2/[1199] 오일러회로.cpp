#include <bits/stdc++.h>
using namespace std;
int N, C = 1;
bool ex = 0;
int adj[1001][1001] = { 0 };
int degree[1001] = { 0 };
/*
7
0 1 1 1 0 0 1
1 0 1 0 0 0 0
1 1 0 1 0 0 1
1 0 1 0 1 1 0
0 0 0 1 0 0 1
0 0 0 1 0 0 1
1 0 1 0 1 1 0
*/
void dfs(int node) {
    for (int i = 1; i <= N; i++) {
        if (adj[node][i]>0) {
            adj[node][i]--;
            adj[i][node]--;
    //여기서 출력시 나중가야할 간선 먼저감(먼저 출력)
            //1 2 3 1 4 3 7 >>1<< 5 4 6 7 1
            dfs(i);
        }
    }
    cout << node << " ";
    //간선 다 없어진 경우 DFS호출시 출력 (따라서 역으로 출력됨)
    // 1 7 6 4 5 7 3 4 1 3 2 1

}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> adj[i][j];
            cnt += adj[i][j];
        }
        if (cnt % 2 != 0)
            ex = 1;
    }
    if (!ex) {
        dfs(1);
        cout << "1\n";
    }
    else
        cout << -1;
    return 0;
}