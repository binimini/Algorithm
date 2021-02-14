#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int N, W, dp[1001][1001], INF=10000000;
pair<int, int> Incident[1001];
int solution(int i, int j) {
    if (i == W || j == W)
        return 0;
    int& r = dp[i][j];
    if (r != -1)
        return r;
    r = 0;
    int next = max(i, j) + 1;
    int dist1, dist2;
    if (i == 0)
        dist1 = abs(Incident[next].first - 1) + abs(Incident[next].second - 1);
    else
        dist1 = abs(Incident[next].first - Incident[i].first) + abs(Incident[next].second - Incident[i].second);

    if (j == 0)
        dist2 = abs(Incident[next].first - N) + abs(Incident[next].second - N);
    else
        dist2 = abs(Incident[next].first - Incident[j].first) + abs(Incident[next].second - Incident[j].second);
    
    return r = min(dist1 + solution(next, j), dist2 + solution(i, next));

}
void tracking(int i, int j) {
    if (i == W || j == W)
        return;
    int next = max(i, j) +1;
    int distI, distJ;
    if (i==0)
        distI = abs(Incident[next].first - 1) + abs(Incident[next].second - 1);
    else 
        distI = abs(Incident[next].first - Incident[i].first) + abs(Incident[next].second - Incident[i].second);
    if (j==0)
        distJ = abs(Incident[next].first - N) + abs(Incident[next].second - N);
    else 
        distJ = abs(Incident[next].first - Incident[j].first) + abs(Incident[next].second - Incident[j].second);
    if (dp[next][j] + distI > dp[i][next] + distJ) {
        cout << 2 << "\n";
        tracking(i, next);
    }
    else {
        cout << 1 << "\n";
        tracking(next, j);
    }
}
int main() {
    FASTIO;
    cin >> N >> W;
    for (int i = 1; i <= W; i++) {
        cin >> Incident[i].first >> Incident[i].second;
    }
    memset(dp, -1, sizeof(dp));
    cout <<solution(0, 0)<<"\n";
    tracking(0,0);

    return 0;
}