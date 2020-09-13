#include <bits/stdc++.h>
using namespace std;
int T, N;
pair<int, int> xy[20];
bool visited[20] = { 0 };
long long int INF = 100000000000, result = INF;
void DFS(int cnt, int node) {
    if (cnt == N / 2) {
        long long int xx = 0, yy = 0;
        for (int i = 0; i < N; i++) {
            if (visited[i] == 1)
                xx -= xy[i].first, yy -= xy[i].second;
            else
                xx += xy[i].first, yy += xy[i].second;
        }
        long long int temp = xx * xx + yy * yy;
        result = min(result, temp);
        return;
    }
    for (int i = node; i < N; i++) {
        if (visited[i]) continue;
        visited[i] = 1;
        DFS(cnt + 1,i+1);
        visited[i] = 0;
    }

}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    for (int t = 0; t < T; t++) {
        result = INF;
        cin >> N;
        for (int i = 0; i < N; i++) {
            visited[i] = 0;
            cin >> xy[i].first >> xy[i].second;
        }
        DFS(0,0);
        cout << fixed<< setprecision(8);
        cout<< sqrt(double(result)) << "\n";
    }
    return 0;
}