#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
bool compare(pair<int, int>a, pair<int, int>b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}
int main() {
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<pair<int, int>> v;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
    sort(v.begin(), v.end(), compare);
    for (int j = 0; j < N; j++) {
        cout << v[j].first << " " << v[j].second << '\n';
    }
    return 0;
}