#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
priority_queue<pair<int,int>> pq;;
int N, K;
int d[3] = { 0,-1,1 }, INF = 9876543, dist[100001];
void dijkstra() {//각 간선의 가중치 다르므로(*2, +1, +1) BFS 불가
    while (!pq.empty()) {
        int xcost = -pq.top().first;
        int x = pq.top().second;

        pq.pop();
        if (xcost > dist[x]) continue;
        for (int i = 0; i < 3; i++) {
            int nx = x + d[i];
            int nxcost = xcost+1;
            if (!i)
                nx = x * 2, nxcost--;
            if (nx < 0 || nx>100000) continue;

            if (nxcost < dist[nx]) {
                dist[nx] = nxcost;
                pq.push(make_pair(-nxcost, nx));
            }
        }
    }
}
int main() {//숨바꼭질 3
    cin >> N >> K;
    memset(dist, INF, sizeof(dist));
    dist[N] = 0;
    pq.push(make_pair(0,N));
    dijkstra();
    cout << dist[K];
    return 0;
}