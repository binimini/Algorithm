#include <bits/stdc++.h>
using namespace std;
int dp[5001], MOD=1000000;
string s;
int solution(int n) {
    if (n == 0) {
        return 1;
    }
    if (n < 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    int& r = dp[n];
    r = 0;
    if (n >= 2) {
        int x = (s[s.size() - n] - '0') * 10 + s[s.size() - n + 1] - '0';
        if (s[s.size() - n] - '0' != 0 && x > 0 && x <= 26) {
            r = (r + solution(n - 2)) % MOD;
        }
    }
    if (s[s.size() - n] - '0' > 0)
        r = (r + solution(n - 1)) % MOD;
    return r;
}
int main() {
    memset(dp, -1, sizeof(dp));
    cin >> s;
    cout << solution(s.size());
    return 0;
}