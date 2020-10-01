#include <iostream>
using namespace std;
int dp[1500001];
long long int N;
int fibbo(int i) {
    if (dp[i] != -1)
        return dp[i];
    else
        return dp[i] = (fibbo(i - 1) + fibbo(i - 2))%1000000;
}
int main() {
    cin >> N;
    for (int i = 1; i <= 1500000; i++) {
        dp[i] = -1;
    }
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i <= 1500000; i++) {
        fibbo(i);
    }
    cout << fibbo(N % 1500000) << "\n";
    return 0;
}