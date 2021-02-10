#include <bits/stdc++.h>
using namespace std;
int N, K;
vector<int> edge[501];
int matched[501] = { 0 };//행 -> 열 이분 매칭
//같은 행에서 최대 한 번 매칭(A)
//같은 열에서 최대 한 번 매칭(B) -> 모두 만족한 최대매칭 == 최소 달리기 수
bool visited[501] = { 0 };
bool dfs(int node) {
    if (visited[node]) return 0;
    visited[node] = 1;
    for (int i = 0; i < edge[node].size(); i++) {
        int next = edge[node][i];
        if (matched[next] == 0 || dfs(matched[next])) {
            matched[next] = node;
            return 1;
        }
    }
    return 0;
}
int main() {
    std::ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    int a, b;
    for (int i = 0; i < K; i++) {
        cin >> a >> b;
        edge[a].push_back(b);//행별로 돌멩이 있는 열들 집어넣기
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