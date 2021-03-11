#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0);
int N;
priority_queue<pair<int, int>> pq;
int main() {
    FASTIO;
    cin >> N;
    int a, b;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        pq.push(make_pair(-a, b));
    }
    int res = 0;
    while (!pq.empty()) {
        int x = -pq.top().first;
        int y = pq.top().second;
        pq.pop();
        if (res < x)
            res = x;
        res += y;
    }
    cout << res;
    return 0;
}