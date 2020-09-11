#include <iostream>
#include <algorithm>
using namespace std;
int comm[100001];
int INF = 1000000;
int dp[100001][5][5];
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n = 1, temp;
    while (1) {
        cin >> temp;
        if (!temp)
            break;
        comm[n] = temp;
        n++;
    }
    for (int i = 1; i <= 100000; i++) {
        for (int j = 0; j <= 4; j++) {
            for (int k = 0; k <= 4; k++) {
                dp[i][j][k] = INF;
            }
        }
    }
    dp[0][0][0] = 0;
    dp[1][comm[1]][0] = 2;
    dp[1][0][comm[1]] = 2;
    for (int i = 2; i < n; i++) {
        for (int j = 4; j >= 0; j--) {
            for (int k = 4; k >= 0; k--) {
                dp[i][j][k] = min(dp[i][j][k], dp[i - 1][0][k] + 2);
                dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][0] + 2);
                dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k] + 1);
                if (k == 1) {
                    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][4] + 3);
                    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][2] + 3);
                    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][3] + 4);
                }
                else if (k == 2) {
                    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][1] + 3);
                    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][3] + 3);
                    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][4] + 4);
                }
                else if(k==3){
                    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][2] + 3);
                    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][4] + 3);
                    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][1] + 4);
                }
                else{
                    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][1] + 3);
                    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][3] + 3);
                    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][2] + 4);
                }
                if (j == 1) {
                    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][4][k] + 3);
                    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][2][k] + 3);
                    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][3][k] + 4);
                }
                else if (j == 2) {
                    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][1][k] + 3);
                    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][3][k] + 3);
                    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][4][k] + 4);
                }
                else if (j == 3) {
                    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][2][k] + 3);
                    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][4][k] + 3);
                    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][1][k] + 4);
                }
                else {
                    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][1][k] + 3);
                    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][3][k] + 3);
                    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][2][k] + 4);
                }
                if (j != comm[i] && k != comm[i])
                    dp[i][j][k] = INF;
            }
        }
    }
    int result = INF;
    for (int i = 0; i <= 4; i++) {
        for (int j = 0; j <= 4; j++) {
            result = min(dp[n - 1][i][j], result);
        }
    }
    cout << result << "\n";
    return 0;
}