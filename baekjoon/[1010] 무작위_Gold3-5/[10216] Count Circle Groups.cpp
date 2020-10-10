#include <bits/stdc++.h>
using namespace std;
int T,N;
int p[3000];
bool ex[3000] = { 0 };
pair<pair<int, int>, int> info[3001];
int find_p(int x) {
    if (p[x] == x)
        return x;
    else
        return p[x] = find_p(p[x]);
}
void union_p(int x, int y) {
    x = find_p(x);
    y = find_p(y);
    p[x] = y;
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            ex[i] = 0;
            p[i] = i;
            cin >> info[i].first.first >> info[i].first.second >> info[i].second;
        }
        int x1, x2, y1, y2, r1, r2;
        for (int i = 0; i < N; i++) {
            x1 = info[i].first.first;
            y1 = info[i].first.second;
            r1 = info[i].second;
            for (int j = i + 1; j < N; j++) {
                x2 = info[j].first.first;
                y2 = info[j].first.second;
                r2 = info[j].second;
                int dist = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
                if (dist <= (r1 + r2) * (r1 + r2))
                    union_p(i, j);
            }
        }
        int cnt = 0, temp;
        for (int i = 0; i < N; i++) {
            temp = find_p(i);
            if (ex[temp] == 0) {
                cnt++;
                ex[temp] = 1;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}