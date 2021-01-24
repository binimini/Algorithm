#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int T, K, dp[501][501], filesize[501], sum[501] = { 0 }, INF = 2100000000;
int solve(int i, int j) {//top-down
    //bottom-up 으로는 삼중 포문 통해서 dp[i][i+1] = filesize[i]+filesize[i+1]와 점화식 이용해 채워나가는 방식이 있다.
    //비슷한 방식이어도 재귀는 함수 호출 등의 이유로 시간이 더 오래 걸린다..
    if (i == j)
        return 0;
    int& r = dp[i][j];
    if (r != -1)
        return r;
    r = INF;
    for (int k = i; k < j; k++) {
        r = min(r, solve(i, k) + solve(k + 1, j) + sum[j]-sum[i-1]);
    }
    return r;
}
int main() {
    FASTIO;
    cin >> T;
    for (int t = 0; t < T; t++) {
        memset(dp, -1, sizeof(dp));
        cin >> K;
        sum[0] = 0;
        for (int i = 1; i <= K; i++) {
            cin >> filesize[i];
            sum[i] = sum[i - 1] + filesize[i];
        }
        cout <<solve(1, K)<<"\n";
    }
    return 0;
}