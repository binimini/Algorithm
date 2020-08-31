#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
int T, N, cnt = 0;
bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}
int main() {
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        cnt = N;
        vector<pair<int, int>> arr_first;
        for (int j = 0; j < N; j++) {
            int x, y;
            cin >> x >> y;
            arr_first.push_back(make_pair(x, y));
        }
        int m = 100001;
        sort(arr_first.begin(), arr_first.end(), compare);
        for (int k = 0; k < N; k++) {
            m = min(arr_first[k].second, m);
            if (arr_first[k].second > m) {
                cnt--;
            }
        }
        cout << cnt << "\n";
    }
}