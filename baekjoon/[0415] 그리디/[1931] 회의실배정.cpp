#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
int N, s_t, e_t, pre, cnt = 0;
vector<pair<int, int>> v;
bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> s_t >> e_t;
        v.push_back(make_pair(s_t, e_t));
    }
    sort(v.begin(), v.end(), compare);
    pre = 0;
    for (int i = 0; i < N; i++) {
        if (v[i].first >= pre) {
            cnt++;
            pre = v[i].second;
        }
    }
    cout << cnt << "\n";
    return 0;
}