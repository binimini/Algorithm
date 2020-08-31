#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
stack<int> s;
int T, N;
int arr[100001];
int dp[100001];
bool visited[100001] = { 0 };
void dfs(int x) {
    if (dp[x] != -1) {// 0이든 1이든 dp 정해진 node로 타고들어가면 사이클일 수 없음 -> dp[] = 0
        while (!s.empty()) {
            dp[s.top()] = 0;
            s.pop();
        }
        return;
    }
    if (visited[x]) {// stack으로 쌓아서 사이클 생기면 dp[] = 1 / dp[] = 0
        while (s.top() != x) {
            dp[s.top()] = 1;
            s.pop();
        }
        dp[s.top()] = 1;
        s.pop();
        while (!s.empty()) {
            dp[s.top()] = 0;
            s.pop();
        }
        return;
    }
    visited[x] = 1;
    s.push(x);
    dfs(arr[x]);
}
int main() {//텀 프로젝트
    //N번 dfs 돌리면 ->O(NX(N+N)) O(N^2)
    // dfs 돌리면서 dp[node]
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    memset(dp, -1, sizeof(dp));
    for (int t = 0; t < T; t++) {
        cin >> N;
        for (int i = 1; i <= N; i++) {
            cin >> arr[i];
        }
        for (int i = 1; i <= N; i++) {
            dfs(i);//한 번 방문시 visted 사용되어도 dp값도 정해져서 visited 초기화 안해도 되는 듯
        }
        int cnt = 0;
        for (int i = 1; i <= N; i++) {
            if (dp[i] == 0)
                cnt++;
            dp[i] = -1;
            visited[i] = 0;
        }
        cout << cnt << "\n";
    }
    return 0;
}