#include <bits/stdc++.h>
using namespace std;
int N, C = 1, cnt = 0;
bool ex = 0;
int adj[1001][1001] = { 0 };
int degree[1001] = { 0 };
bool visited[1001] = { 0 };
vector<int> v;
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
void dfs(int node) {//위예제는 잘 나오는데 왜 백트래킹도 앞출력처럼 9%에서 WA?
    if (node == 1 && C == N && cnt==0) {
        for (int i = 0; i < v.size(); i++)
            cout << v[i]<<" ";
        cout << "\n";
        ex = 1;
        return;
    }
    for (int i = 1; i <= N; i++) {
        if (adj[node][i] > 0) {
            adj[node][i]--;
            adj[i][node]--;
            cnt -= 2;
            bool flag = visited[i];
            if (!flag)
                C++;
            visited[i] = 1;
            v.push_back(i);
            dfs(i);
            v.pop_back();
            if (ex)
                return;
            if (!flag)
                visited[i] = 0, C--;
            cnt += 2;
            adj[node][i]++;
            adj[i][node]++;
        }
    }
    //간선 다 없어진 경우 DFS호출시 출력 (따라서 역으로 출력됨)
    // 1 7 6 4 5 7 3 4 1 3 2 1

}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> adj[i][j];
            cnt += adj[i][j];
        }
        if (cnt % 2 != 0)
            ex = 1;
    }
    if (!ex) {
        visited[1] = 1;
        v.push_back(1);
        dfs(1);
    }
    else
        cout << -1;
    return 0;
}