#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int N, M;
pair<int, int> p[501];
bool happy[501] = { 0 };
int main() {
    FASTIO;
    int temp;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        happy[i] = 1;
    }
    for (int i = 1; i <= N; i++) {
        cin >> p[i].first >> p[i].second;
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> temp;
        happy[temp] = 0;
    }
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (happy[i] && happy[p[i].first] && happy[p[i].second])
            cnt++;
    }
    cout << cnt;
    return 0;
}