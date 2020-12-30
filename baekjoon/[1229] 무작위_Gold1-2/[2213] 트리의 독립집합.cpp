#include <bits/stdc++.h>
using namespace std;
int N;
int w[10001];
vector<int> e[10001];
int dp[10001][2];
bool visited[10001] = { 0 };
vector<pair<int, int>> v[10000][2];
int solution(int node, int in) {
    if (dp[node][in] != -1)
        return dp[node][in];
    visited[node] = 1;
    bool visit = 1;
    for (int i = 0; i < e[node].size(); i++) {
        if (!visited[e[node][i]]) {
            visit = 0;
            break;
        }
    }
    if (visit) {
        visited[node] = 0;
        if (in) return w[node];
        else return 0;
    }

    int& r = dp[node][in];
    r = 0;
    for (int i = 0; i < e[node].size(); i++) {
        if (visited[e[node][i]]) continue;
        if (in) {
            r += solution(e[node][i], 0);
            v[node][in].push_back({ e[node][i], 0 });
        }
        else {
            int t1 = solution(e[node][i], 0);
            int t2 = solution(e[node][i], 1);
            if (t1 < t2) {
                v[node][in].push_back({ e[node][i], 1 });
                r += t2;
            }
            else {
                v[node][in].push_back({ e[node][i], 0 });
                r += t1;
            }
        }
    }
    if (in)
        r += w[node];
    visited[node] = 0;
    return r;
}
void tracking(int r) {
    queue<pair<int,int>> q;
    int n, b;
    if (dp[1][1] == r)
        q.push({ 1,1 });
    else
        q.push({ 1,0 });
    vector<int> result;
    while (!q.empty()) {
        n = q.front().first;
        b = q.front().second;
        q.pop();
        if (b)
            result.push_back(n);
        for (int i = 0; i < v[n][b].size(); i++) {
            q.push(v[n][b][i]);
        }
    }
    sort(result.begin(), result.end());
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << "\n";
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> w[i];
    }
    int a, b;
    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    memset(dp, -1, sizeof(dp));
    int result = max(solution(1, 0), solution(1, 1));
    cout << result<<"\n";
    tracking(result);
    return 0;
}