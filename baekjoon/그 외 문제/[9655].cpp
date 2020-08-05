#include <iostream>
using namespace std;
int N, dp[1001] = { 0 };
int find_dp(int n) {
	if (dp[n] != 0) return dp[n];
	if (find_dp(n - 3) * -1 == -1 && find_dp(n - 1) * -1 == -1)
		return dp[n] = -1;
	else  return dp[n] = 1;
}
int main() {//돌 게임
	cin >> N;
	dp[1] = 1;
	dp[2] = -1;
	dp[3] = 1;
	if (find_dp(N) == 1)
		cout << "SK";
	else if (find_dp(N)==-1)
		cout << "CY";
	return 0;
}