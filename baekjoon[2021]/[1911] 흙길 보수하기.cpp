#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int N;
long long int L, res = 0;
vector<pair<long long int, long long int>> v;
bool comp(pair<int, int> x, pair<int, int> y) {
    if (x.first == y.first)
        return x.second < y.second;
    return x.first < y.first;
}
int main() {
    FASTIO;
    cin >> N>>L;
    long long int a, b;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    sort(v.begin(), v.end(), comp);
    long long int end = 0, cnt = 0, dist;
    for (int i = 0; i < N; i++) {
        if (v[i].first > end) {//이미 놓인 널판지 뒤에 웅덩이
            dist = v[i].second - v[i].first;
            cnt = (dist % L == 0) ? dist / L : dist / L + 1;
            res += cnt;
            end = v[i].first + cnt * L - 1;
        }
        else if (v[i].second-1 <= end) continue;
        else {
            dist = v[i].second -1 - end;
            cnt = (dist % L == 0) ? dist / L : dist / L + 1;
            res += cnt;
            end = end + cnt * L;
        }
    }
    cout << res;
    return 0;
}