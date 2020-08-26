#include <iostream>
#include <queue>
using namespace std;
priority_queue<pair<int, int>> pq;
int dist[100001], d[3] = { 0,-1,1 };
int N, K, cnt = 0, INF = 987654321;
void dijkstra() {
    while (!pq.empty()) {
        int VERCOST = -pq.top().first;
        int VER = pq.top().second;
        pq.pop();
        if (VERCOST > dist[K]) return;//K까지의 최소 비용 이후 필요x
        if (dist[VER] < VERCOST) continue;
        for (int i = 0; i < 3; i++) {
            int NEXTCOST = 1;
            int NEXT = VER + d[i];
            if (i == 0)
                NEXT = 2 * VER;
            if (NEXT < 0 || NEXT>100000) continue;
            if (dist[NEXT] >= NEXTCOST + VERCOST) {
                if (dist[NEXT] == NEXTCOST + VERCOST) {
                    if (NEXT == K) {
                        cnt++;
                    }
                }
                else {
                    dist[NEXT] = NEXTCOST + VERCOST;
                    if (NEXT == K)
                        cnt++;
                }
                pq.push(make_pair(-dist[NEXT], NEXT));//dist값과 새로운 비용값이 같아도 넣어줘야 방법 몇가지인지 체크 가능
            }
        }
    }
}
int main() {//숨바꼭질 2
    for (int i = 0; i <= 100000; i++) {
        dist[i] = INF;
    }
    cin >> N >> K;
    pq.push(make_pair(0, N));
    dist[N] = 0;
    if (N == K)//같을 경우 비용은 제대로 0이지만 cnt = 0으로 잘못됨
        cnt = 1;
    dijkstra();
    cout << dist[K] << "\n" << cnt << "\n";

}