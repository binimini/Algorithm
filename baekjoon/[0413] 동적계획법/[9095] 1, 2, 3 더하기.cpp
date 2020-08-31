#include <iostream>
using namespace std;
int T, dp[11];
int main() {
    cin >> T;
    int* arr = new int[T];
    for (int i = 0; i < T; i++) {
        cin >> arr[i];
    }
    dp[1] = 1, dp[2] = 2, dp[3] = 4;
    for (int i = 4; i <= 10; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    for (int i = 0; i < T; i++) {
        cout << dp[arr[i]] << "\n";
    }
    return 0;
}