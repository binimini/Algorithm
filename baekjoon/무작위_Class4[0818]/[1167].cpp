#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0);
#define FOR(i,a,b) for(int i = a; i<b; i++)
int N;
vector<pair<int,int>> tree[100001];
queue<int> q;
int visited[100001] = { 0 };
void BFS() {
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 0; i < tree[x].size(); i++) {
            if (visited[tree[x][i].first]) continue;
            visited[tree[x][i].first] = visited[x] + tree[x][i].second;
            q.push(tree[x][i].first);
        }
    }
}
int main() {//트리의 지름
    //임의의 한 점에서 가장 먼 점 찾고
    //그 점에서 가장 먼점까지의 거리
    FASTIO;
    cin >> N;
    int a, b, c;
    for (int i = 0; i < N; i++) {
        cin >> a;
        while (1) {
            cin >> b;
            if (b == -1)
                break;
            else cin >> c;
            tree[a].push_back(make_pair(b, c));
        }
    }
    q.push(1);
    visited[1] = 1;
    BFS();
    pair<int, int> M = { 0,0 };
    for (int i = 1; i <= N; i++) {
        if (visited[i] > M.second)
            M.second = visited[i], M.first = i;
        visited[i] = 0;
    }
    q.push(M.first);
    visited[M.first] = 1;
    BFS();
    int result = 0;
    for (int i = 0; i < N; i++) {
        if (visited[i] > result)
            result = visited[i];
    }
    cout << result - 1 << "\n";
    return 0;
}