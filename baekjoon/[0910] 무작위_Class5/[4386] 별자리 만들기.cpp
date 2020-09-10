#include <iostream>
#include <queue>
#include <math.h>
using namespace std;
int N, cnt = 0;
double R;
bool visited[101] = { 0 };
pair<double,double> info[101];
priority_queue<pair<double, int>> pq;
void prim() {
    while (!pq.empty()) {
        int x = pq.top().second;
        double c = -pq.top().first;
        pq.pop();

        if (visited[x]) continue;
        visited[x] = 1;
        R += c;
        cnt++; 
        if (cnt == N)
            return;
        
        for (int i = 1; i <= N; i++) {
            if (visited[i]) continue;
            double nc = (info[x].first - info[i].first) * (info[x].first - info[i].first);
            nc += (info[x].second - info[i].second) * (info[x].second - info[i].second);
            nc = sqrt(nc);
            pq.push(make_pair(-nc, i));
        }
   }

}

int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> info[i].first >> info[i].second;
    pq.push(make_pair(0, 1));
    prim();
    cout << R << '\n';
    return 0;
}