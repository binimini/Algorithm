#include <iostream>
using namespace std;
int N;
long long int dp[31][31];
long long int find_dp(int one, int half) {
    if (!one && !half)
        return 1;
    if (dp[one][half] != -1)
        return dp[one][half];
    long long int& r = dp[one][half] = 0;
    if (half != 0)
        r += find_dp(one, half - 1);
    if (one != 0)
        r += find_dp(one - 1, half + 1);
    return r;
        
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (1) {
        cin >> N;
        if (N == 0)
            break;
        for (int i = 0; i <= 30; i++) {
            for (int j = 0; j <= 30; j++) {
                dp[i][j] = -1;
            }
        }
        cout << find_dp(N, 0)<<"\n";
    }
    return 0;
}