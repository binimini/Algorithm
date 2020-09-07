#include <bits/stdc++.h>
using namespace std;
int N, R = 0, cnt = 0;
bool visited[100001] = { 0 };
vector<pair<int, int>> X, Y, Z;
vector<int> adj[1000001];
tuple<int,int,int> arr[100001];
priority_queue<pair<int,int>> pq;
void prim() {
    while (!pq.empty()) {
        int x = pq.top().second;
        int xc = -pq.top().first;
        pq.pop();
        if (visited[x]) continue;
        visited[x] = 1;
        R += xc;
        if (++cnt == N)
            return;
        int size = adj[x].size();
        for (int i = 0; i < size; i++) {
            if (visited[adj[x][i]]) continue;
            int temp = min(abs(get<0>(arr[x]) - get<0>(arr[adj[x][i]])), abs(get<1>(arr[x]) - get<1>(arr[adj[x][i]])));
            temp = min(temp, abs(get<2>(arr[x]) - get<2>(arr[adj[x][i]])));
            pq.push(make_pair(-temp, adj[x][i]));
        }
    }
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    int x, y, z;
    for (int i = 1; i <= N; i++) {
        cin >> x >> y >> z;
        arr[i] = make_tuple(x, y, z);
        X.push_back(make_pair(x, i));
        Y.push_back(make_pair(y, i));
        Z.push_back(make_pair(z, i));
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    sort(Z.begin(), Z.end());
    int s = X.size();
    for (int i = 0; i < s; i++) {
        if (i != s-1) {
            adj[X[i + 1].second].push_back(X[i].second);
            adj[X[i].second].push_back(X[i + 1].second);
            adj[Y[i + 1].second].push_back(Y[i].second);
            adj[Y[i].second].push_back(Y[i + 1].second);
            adj[Z[i + 1].second].push_back(Z[i].second);
            adj[Z[i].second].push_back(Z[i + 1].second);

        }
    }
    pq.push(make_pair(0,1));
    prim();
    cout << R << '\n';
    return 0;
}