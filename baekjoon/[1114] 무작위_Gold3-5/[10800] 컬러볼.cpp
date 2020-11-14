#include <bits/stdc++.h>
using namespace std;
int N;
pair<int, int> arr[200000];
vector<vector<int>> s;
vector<int> v[200001], total;
int s_match[200001];
int lb(int color, int key) {
    int s = 0, e = v[color].size(), m;
    while (e - s > 0) {
        m = (s + e) / 2;
        if (v[color][m] < key)
            s = m + 1;
        else
            e = m;
    }
    return e;
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    int a, b;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        arr[i].first = a, arr[i].second = b;
        v[a].push_back(b);
        v[0].push_back(b);
    }
    sort(v[0].begin(), v[0].end());
    s.push_back({ v[0][0] });
    s_match[0] = 0;
    for (int i = 1; i <N; i++) {
        s[0].push_back((s[0][i - 1] + v[0][i]));
    }

    int cnt = 1;
    for (int i = 1; i <= N; i++) {
        if (v[i].empty()) {
            s_match[i] = -1;
            continue;
        }
        sort(v[i].begin(), v[i].end());
        s_match[i] = cnt;
        s.push_back({ v[i][0] });
        for (int j = 1; j < v[i].size(); j++) {
            s[cnt].push_back(s[cnt][j-1] + v[i][j]);
        }
        cnt++;
    }

    for (int i = 0; i < N; i++) {
        int totall = lb(0, arr[i].second);
        if (totall == 0) {
            cout << 0 << "\n";
            continue;
        }
        else {
            int totalsum = s[0][totall - 1];
            int locall = lb(arr[i].first, arr[i].second);
            if (locall == 0)
                cout << totalsum - 0 << "\n";
            else
                cout << totalsum - s[s_match[arr[i].first]][locall - 1] << "\n";
        }
    }
    return 0;
}