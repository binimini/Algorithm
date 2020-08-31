#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, M, G = 0, E = 0, ST, ED, CH = 0, visited[10001] = { 0 };
vector<pair<int, int>> route[10001];
void DFS(int node, int mid) {
    visited[node] = 1;
    if (node == ED) {
        CH = 1;
        return;
    }
    for (int i = 0; i < route[node].size(); i++) {
        if (route[node][i].second < mid) continue;
        if (visited[route[node][i].first]) continue;
        else {
            DFS(route[node][i].first, mid);
        }
    }
}
void binary_search(int left, int right) {
    int mid;
    while (right - left >= 0) {
        mid = (right + left) / 2;
        for (int i = 1; i <= N; i++) {
            visited[i] = 0;
        }
        DFS(ST, mid);
        if (CH) {
            G = max(mid, G);
            left = mid + 1;
            CH = 0;
        }
        else {
            right = mid - 1;
        }
    }
}
int main() {
    cin >> N >> M;
    int a, b, c;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        E = max(E, c);
        route[a].push_back(make_pair(b, c));
        route[b].push_back(make_pair(a, c));
    }
    cin >> ST >> ED;
    binary_search(0, E);
    cout << G;
    return 0;
}