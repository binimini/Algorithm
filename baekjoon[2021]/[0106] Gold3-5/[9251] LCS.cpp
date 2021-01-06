#include <bits/stdc++.h>
using namespace std;
string A, B;
int dp[1001][1001];
int solution(int i, int j) {
    if (i >= A.size() || j >= B.size())
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
   
    if (A[i] == B[j])
        return dp[i][j] = solution(i + 1, j + 1) + 1;
    else 
        return dp[i][j] = max(solution(i, j + 1), solution(i + 1, j));  
}
int main() {
    cin >> A >> B;
    memset(dp, -1, sizeof(dp));
    cout << solution(0, 0);
    return 0;
}