#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int N, M, d[10001], dp[10002][501] = { 0 }, Max = -10000001;//배열 크기 조건 확실히..
int find_max(int n, int status) {
    if (n > N+1)
        return Max;
    if (status > M)
        return Max;
    if (n == N+1) {
        if (status ==0)
            return 0;
        else return Max;
    }
    if (dp[n][status] != -1)
        return dp[n][status];
    if (status > 0) 
       return dp[n][status] = max(find_max(n + 1, status + 1) + d[n], find_max(n + status, 0));
    else if (status==0) 
       return dp[n][status] = max(find_max(n + 1,status+1)+d[n], find_max(n+1, 0));
}
int main() {//달려달려
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> d[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << find_max(1,0) << "\n";
    return 0;
}