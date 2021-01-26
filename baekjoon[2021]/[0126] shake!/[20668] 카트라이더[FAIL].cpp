#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int N, M;
vector<pair<int, pair<long double, int>>> edge[10001];
long double dp[10001][11], INF=10000000000000012;//i번지점에서 속도 j번일때 목적지 N까지 최소 시간
long double solve(int i, int j) {
    if (j < 1)
        return INF;
    if (i == N)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    long double & r = dp[i][j];
    r = INF;
    for (int x = 0; x < edge[i].size(); x++) {
        int next = edge[i][x].first;
        if (j > edge[i][x].second.second) continue;
        r = min(r, min(min(solve(next, j + 1), solve(next, j)), solve(next, j - 1))+edge[i][x].second.first*10000000/(long double)j);
    }
    return r;
}
int main() {
    cin >> N >> M;
    int a, b, k;
    long double l;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> l >> k;
        edge[a].push_back({ b,{l,k} });
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 11; j++) {
            dp[i][j] = -1;
        }
    }
    //출발지 1 목적지 N
    cout << fixed;
    cout << setprecision(9);//double or long double 유효숫자범위 때문에 오답??? -> 처리 어떻게
    cout << round(min(solve(1, 1), solve(1, 2))*100)/1000000000;
    return 0;
}