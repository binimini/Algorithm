#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int N, M;
int c[101], m[101];
int dp[10001] = { 0 };
int result = 10001;
int main() {//앱
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> m[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> c[i];
    }
    dp[c[1]] = m[1];
    for (int i = 2; i <= N; i++) {
        for (int j = 10000; j >=0; j--) {//오름차순으로 더하면 m[i] 여러번 더하는 경우 발생 가능 -> 내림차순/순차표시할이차원디피
            //ex. c[1] = 1, m[1] = 3 이면 dp[1] = 3이 max dp[2] 는 1 최대 한 번 더해야하는데  dp[1] = 3을 최대로 끌어와서 dp[2] = 6 돼버림 
            // 따라서 내림차순으로 돌리면 최대 j부터 갱신되므로  밑의 j의 것 끌어올 일 없다.
            if (j >= c[i])//c[i]까지의 범위 불가능 
                dp[j] = max(dp[j], dp[j - c[i]] + m[i]);
            if (dp[j] >= M) //c[i]미만의 값에서 최소 j 찾을 수 있어서? c[i] 이상이어야 dp 갱신되는데?
                result = min(result, j);
        }
    }
    cout << result << '\n';
    return 0;
}