#include <bits/stdc++.h>
using namespace std;
int D, INF = 1000000008, mod = 1000000007;
int dp[100001][9] = { 0 };//1-8
vector<int> v[9];
int main() {
    cin >> D;
    v[1] = { 2,3 };
    v[2] = { 1,3,4 };
    v[3] = { 1,2,4,5 };
    v[4] = { 2,3,5,6 };
    v[5] = { 3,4,6,8 };
    v[6] = { 4,5,7 };
    v[7] = { 6,8 };
    v[8] = { 5,7 };
    for (int i = 1; i <= D; i++) {
        for (int j = 1; j <= 8; j++) {
            dp[i][j] = INF;
        }
    }
    dp[0][1] = 1;
    for (int i = 1; i <= D; i++) {
        for (int j = 1; j <= 8; j++) {
            dp[i][j] = 0;
            for (int k = 0; k < v[j].size(); k++) {
                if (dp[i - 1][v[j][k]] >= INF) continue;
                dp[i][j] = (dp[i][j]+ dp[i - 1][v[j][k]])%mod;
            }
        }
    }
    cout << dp[D][1]%mod << "\n";
    return 0;
}