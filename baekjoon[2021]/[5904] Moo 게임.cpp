#include <bits/stdc++.h>
using namespace std;
int N;
int dp[1001];
char tracking(int n, int lo) {
    if (n == 0) {
        if (lo == 1)
            return 'm';
        else
            return 'o';
    }
    if (lo <= dp[n - 1])
        return tracking(n - 1, lo);
    else if (lo > dp[n - 1] && lo <= dp[n - 1] + n + 3) {
        if (lo == dp[n - 1] + 1)
            return 'm';
        else
            return 'o';
    }
    else 
        return tracking(n - 1, lo - dp[n - 1] - n - 3);
}
int main() {
    cin >> N;
    int sum = 0;
    int i = 0;
    dp[0] = 3;
    while (1) {
        i++;
        dp[i] = dp[i-1] * 2 + i + 3;
        if (dp[i] >= N)
            break;
    }
    cout <<tracking(i, N);
    
    return 0;
}