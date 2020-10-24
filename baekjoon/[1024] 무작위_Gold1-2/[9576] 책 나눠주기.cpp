#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i<b; i++)
int T, N, M;
vector<bool> visited;//초기화하고 i번째 기준으로 dfs 시킬때 각 dfs(i) 방문여부
vector<int> A, B;//A 매칭 노드 B 매칭 노드 표시 //이어나감
vector<int> e[1001];
bool dfs(int a) {//이분 매칭
    if (visited[a]) return false;//아미 처리한 것일 경우 지나감???
    visited[a] = true;
    for (int b = 0; b < e[a].size(); b++) {
        if (B[e[a][b]] == -1 || dfs(B[e[a][b]])) {//연결되지 않았거나 연결되었던 A가 다른 매칭 가능한 경우
            A[a] = e[a][b];
            B[e[a][b]] = a;

            return true;
        }
    }
    return false;
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    FOR(t, 0, T) {
        cin >> N >> M;
        int a, b;
        for (int i = 1; i <= M; i++) {
            e[i].clear();
            cin >> a >> b;
            for (int j = a; j <= b; j++) {
                e[i].push_back(j);
            }
        }
        A = vector<int>(M+1, -1);
        B = vector<int>(N+1, -1);
        int cnt = 0;
        for (int i = 1; i <= M; i++) {
            visited = vector<bool>(M+1, false);
            if (dfs(i))
                cnt++;
        }
        cout << cnt << "\n";
    }

    return 0;
}