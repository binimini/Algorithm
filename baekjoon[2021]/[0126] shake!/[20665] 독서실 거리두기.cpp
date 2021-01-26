#include <bits/stdc++.h>
using namespace std;
bool use[101] = { 0 };
int N, T, P, res = 720;
int main() {
    std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> T >> P;
    vector<pair<int, int>> v;
    string a, b;
    for (int i = 0; i < T; i++) {
        cin >> a >> b;
        v.push_back(make_pair(stoi(a), stoi(b)));
    }
    sort(v.begin(),v.end());
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < T; i++) {
        while (!pq.empty()&&(-pq.top().first <= v[i].first)) {
            use[pq.top().second] = 0;
            pq.pop();
        }
        if (pq.empty()) {
            use[1] = 1;
            if (P == 1)
                res -= (v[i].second / 100 - v[i].first / 100) * 60 + (v[i].second % 100 - v[i].first % 100);
            pq.push(make_pair(-v[i].second, 1));
        }
        else {
            pair<int, int> mindist_max = { 0,0 };//min dist, seat number
            for (int j = 1; j <= N; j++) {
                if (use[j]) continue;
                int mindist = 99;
                for (int k = 1; k <= N; k++) {
                    if (use[k] && k != j)
                        mindist = min(mindist, abs(k - j));
                }
                if (mindist_max.first < mindist) {
                    mindist_max.first = mindist;
                    mindist_max.second = j;
                }
            }
            use[mindist_max.second] = 1;
            if (mindist_max.second == P)
                res -= (v[i].second / 100 - v[i].first / 100) * 60 + (v[i].second % 100 - v[i].first % 100);
            pq.push(make_pair(-v[i].second, mindist_max.second));
        }
        
    }
    cout << res;
    return 0;
}