#include <bits/stdc++.h>
using namespace std;
int N, p[3000], cnt[3000] = { 0 };
pair<int, int> xy[3000][2];
int find_p(int x) {
    if (p[x] == x)
        return x;
    else return p[x] = find_p(p[x]);
}
void union_p(int x, int y) {
    x = find_p(x);
    y = find_p(y);
    if (x < y)
        p[y] = x;
    else
        p[x] = y;
}
int ccw(pair<int,int>& a,pair<int,int>& b,pair<int,int>& c) {
    int v = a.first * b.second + b.first * c.second + c.first * a.second - a.first * c.second - b.first * a.second - c.first * b.second;
    if (v > 0)
        return 1;
    if (v == 0)
        return 0;
    else
        return -1;
}
bool cross(int a, int b) {
    int r1 = ccw(xy[a][0], xy[a][1], xy[b][0]) * ccw(xy[a][0], xy[a][1], xy[b][1]);
    int r2 = ccw(xy[b][0], xy[b][1], xy[a][0]) * ccw(xy[b][0], xy[b][1], xy[a][1]);
    if (r1 <= 0 && r2 <= 0) {
        if (r1 == 0 && r2 == 0) {
            if (xy[a][0] > xy[a][1]) swap(xy[a][0], xy[a][1]);
            if (xy[b][0] > xy[b][1]) swap(xy[b][0], xy[b][1]);
            return xy[a][0] <= xy[b][1] && xy[b][0] <= xy[a][1];
        }
        else return true;
    }
    else
        return false;
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        p[i] = i;
        cin >> xy[i][0].first >> xy[i][0].second >> xy[i][1].first >> xy[i][1].second;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            if (find_p(i) == find_p(j)) continue;
            if (cross(i, j))
                union_p(i, j);
        }
    }
    for (int i = 0; i < N; i++) {
        cnt[find_p(i)]++;
    }
    int g_cnt = 0, m_cnt = 0;
    for (int i = 0; i < N; i++) {
        if (cnt[i] != 0) {
            g_cnt++;
            if (cnt[i] > m_cnt)
                m_cnt = cnt[i];
        }
    }
    cout << g_cnt << '\n' << m_cnt << '\n';
    return 0;
}