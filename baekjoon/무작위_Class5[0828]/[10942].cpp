#include <iostream>
#include <cstring>
using namespace std;
int N, M;
int dp[2000][2000];
int arr[2000];
int query(int s, int e) {
    if (s > e)
        return 1;
    if (dp[s][e] != -1)
        return dp[s][e];
    if (s == e)
        return dp[s][e] = 1;
    if (arr[s] != arr[e])
        return dp[s][e] = 0;
    return dp[s][e] = query(s + 1, e - 1);
}
int main() {//팰린드롬?
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    cin >> M;
    int S, E;
    for (int i = 0; i < M; i++) {
        cin >> S >> E;
        cout << query(S-1, E-1) << "\n";
    }
    return 0;
}