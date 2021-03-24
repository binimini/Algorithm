#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int T, N, x, y, X, Y;
queue<pair<int, int>> q;
bool visited[100] = { 0 };
pair<int, int> lo[100];
bool bfs() {
    while (!q.empty()) {
        int xx = q.front().first;
        int yy = q.front().second;
        if (abs(X - xx) + abs(Y - yy) <= 1000)
            return 1;
        q.pop();
        int dist;
        for (int i = 0; i < N; i++) {
            if (visited[i]) continue;
            dist = abs(xx - lo[i].first) + abs(yy - lo[i].second);
            if (dist > 1000) continue;
            visited[i] = 1;
            q.push(lo[i]);
            if (abs(X - lo[i].first) + abs(Y - lo[i].second) <= 1000)
                return 1;
        }
    }
    return 0;
}
int main() {
    FASTIO;
    cin >> T;
    for (int t = 0; t < T; t++) {
        while (!q.empty())
            q.pop();
        cin >> N;
        cin >> x >> y;
        q.push(make_pair(x, y));
        for (int i = 0; i < N; i++) {
            visited[i] = 0;
            cin >> lo[i].first >> lo[i].second;
        }
        cin >> X >> Y;
        if (bfs())
            cout << "happy\n";
        else
            cout << "sad\n";
    }
    return 0;
}