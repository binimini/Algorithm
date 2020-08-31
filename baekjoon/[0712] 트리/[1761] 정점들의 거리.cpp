#include <iostream>
#include <vector>
using namespace std;
int N, M;
vector<pair<int, int>> child[40001];
bool visited[40001] = { 0 };
int info[40001][3];
int find(int node1, int node2) {
    int dist = info[node1][2] + info[node2][2];
    while (node1 != node2) {
        if (info[node1][1] == info[node2][1]) {
            node1 = info[node1][0];
            node2 = info[node2][0];
        }
        else if (info[node1][1] > info[node2][1]) {
            node1 = info[node1][0];
        }
        else if (info[node1][1] < info[node2][1]) {
            node2 = info[node2][0];
        }
    }
    dist -= 2 * info[node1][2];
    return dist;
}
void root(int node, int depth, int length) {
    info[node][2] = length;
    for (int i = 0; i < child[node].size(); i++) {
        if (visited[child[node][i].first]) continue;
        visited[child[node][i].first] = 1;
        info[child[node][i].first][0] = node;
        info[child[node][i].first][1] = depth;
        root(child[node][i].first, depth + 1, length + child[node][i].second);
    }
}
int main() {
    cin >> N;
    int a, b, c;
    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b >> c;
        child[a].push_back(make_pair(b, c));
        child[b].push_back(make_pair(a, c));
    }
    visited[1] = 1;
    info[1][1] = 0, info[1][2] = 0;
    root(1, 1, 0);
    cin >> M;
    int d, e;
    for (int i = 0; i < M; i++) {
        cin >> d >> e;
        cout << find(d, e) << "\n";
    }
}