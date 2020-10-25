#include <iostream>
#include <queue>
using namespace std;
#define FOR(i,a,b) for (int i = a; i<b; i++)
int N, arr[125][125], dist[125][125], d[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
priority_queue<pair<int, pair<int, int>>> pq;
void dijk() {
    while (!pq.empty()) {
        int vx = pq.top().second.first;
        int vy = pq.top().second.second;
        int vc = -pq.top().first;
        pq.pop();
        if (vc > dist[vx][vy]) continue;
        for (int i = 0; i < 4; i++) {
            int nx = vx + d[i][0];
            int ny = vy + d[i][1];
            int nc = vc + arr[nx][ny];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if (dist[nx][ny] > nc) {
                dist[nx][ny] = nc;
                pq.push(make_pair(-nc, make_pair(nx, ny)));
            }
        }
    }
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int cnt = 0;
    while (1) {
        cnt++;
        cin >> N;
        if (!N)
            break;
        FOR(i, 0, N) {
            FOR(j, 0, N) {
                dist[i][j] = 1000001;
                cin >> arr[i][j];
            }
        }
        dist[0][0] = arr[0][0];
        pq.push({ -arr[0][0],{0,0} });
        dijk();
        cout << "Problem "<<cnt<<": "<<dist[N - 1][N - 1] << "\n";
    }
    return 0;
}