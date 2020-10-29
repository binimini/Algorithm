#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, INF = -1000000001;
vector<pair<int, int>> v;
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    int length = 0, start = INF, end =INF;
    int a, b;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        v.push_back(make_pair(min(a, b), max(a, b)));
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < N; i++) {
        if (start == INF && end == INF)
            start = v[i].first, end = v[i].second;
        else if (v[i].first <= end && start <= v[i].second) {
            start = min(v[i].first, start);
            end = max(v[i].second, end);
        }
        else {
            length += end - start;
            start = v[i].first;
            end = v[i].second;
        }
    }
    length += end - start;
    cout << length;
}