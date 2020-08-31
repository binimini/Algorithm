#include <iostream>
using namespace std;
int R, C, W, dp[30][30] = { 0 };
int pasc(int r, int c) {
    if (r < 1 || r>29 || c < 1 || c>29 || r < c) return 0;
    if (dp[r][c] != 0)
        return dp[r][c];
    return dp[r][c] = pasc(r - 1, c - 1) + pasc(r - 1, c);
}
int main() {
    dp[1][1] = 1;
    int R, C, W;
    cin >> R >> C >> W;
    long long int sum = 0;
    for (int i = 0; i < W; i++) {
        for (int j = 0; j <= i; j++) {
            sum += pasc(R + i, C + j);
        }
    }
    cout << sum << "\n";
    return 0;
}