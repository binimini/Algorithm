#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N, visited[10001] = { 0 };
pair<int, int> maxi = { 0,0 }, parent[10001];
vector<pair<int, int>> child[10001];
queue<int> q;
void find_maxi() {
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        if (parent[node].first != -1 && visited[parent[node].first] == 0)
            visited[parent[node].first] = parent[node].second + visited[node], q.push(parent[node].first);
        for (int i = 0; i < child[node].size(); i++) {
            if (visited[child[node][i].first]) continue;
            visited[child[node][i].first] = visited[node] + child[node][i].second;
            q.push(child[node][i].first);
        }
    }
}
int main() {
    cin >> N;
    int p, c, v;
    for (int i = 0; i < N - 1; i++) {
        cin >> p >> c >> v;
        parent[c] = make_pair(p, v);
        child[p].push_back(make_pair(c, v));
    }
    parent[1] = { -1,0 };
    q.push(1);
    visited[1] = -1;
    find_maxi();
    for (int i = 1; i <= N; i++) {
        if (visited[i] > maxi.first)
            maxi.first = visited[i], maxi.second = i;
        visited[i] = 0;
    }
    q.push(maxi.second);
    visited[maxi.second] = 1;
    find_maxi();
    maxi.first = 0, maxi.second = 0;
    for (int i = 1; i <= N; i++) {
        if (visited[i] > maxi.first)
            maxi.first = visited[i], maxi.second = i;
    }
    cout << maxi.first - 1 << '\n';
    return 0;
}