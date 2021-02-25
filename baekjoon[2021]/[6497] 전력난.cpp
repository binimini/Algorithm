#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int N, M, res;
vector <pair<int, pair<int, int>>> v;
int parent[100000];
bool cmp(pair<int,pair<int,int>> a, pair<int,pair<int,int>> b) {
    return a.first < b.first;
}
int find_p(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find_p(parent[x]);
}
void union_p(int x, int y) {
    x = find_p(x);
    y = find_p(y);
    if (x < y)
        parent[y] = x;
    else
        parent[x] = y;
}
int kruskal() {
    int cnt = 0, ret = 0;
    while (cnt < N - 1) {
        for (int i = 0; i < v.size(); i++) {
            if (find_p(v[i].second.first) == find_p(v[i].second.second)) continue;
            else {
                union_p(v[i].second.first, v[i].second.second);
                ret += v[i].first;
                cnt++;
            }
        }
    }
    return ret;
}
int main() {
    FASTIO;
    while (1) {
        cin >> N >> M;
        if (!N && !M)
            break;
        res = 0;
        v.clear();
        for (int i = 0; i < N; i++) {
            parent[i] = i;
        }
        int a, b, c;
        for (int i = 0; i < M; i++) {
            cin >> a >> b >> c;
            v.push_back({ c,{a,b} });
            res += c;
        }
        sort(v.begin(), v.end(), cmp);
        cout << res - kruskal()<<"\n";
    }
    return 0;
}