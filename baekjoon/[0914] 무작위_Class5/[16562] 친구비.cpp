#include <bits/stdc++.h>
using namespace std;
int N, M, K;
int cost[10001], parent[10001];
bool visited[10001] = { 0 };
int find_p(int x) {
    if (parent[x] == x)
        return x;
    else return parent[x] = find_p(parent[x]);
}
void u_friend(int x, int y) {
    x = find_p(x);
    y = find_p(y);
    if (cost[x] < cost[y])
        parent[y] = x;
    else
        parent[x] = y;
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        cin >> cost[i];
    }
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        u_friend(a, b);
    }
    int result = 0;
    for (int i = 1; i <= N; i++) {
        if (visited[find_p(i)]) continue;
        visited[find_p(i)] = 1;
        result += cost[find_p(i)];
    }
    if (result > K)
        cout << "Oh no";
    else
        cout << result;
    return 0;
}