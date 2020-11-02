#include <bits/stdc++.h>
using namespace std;
int N;
vector<pair<int, int>> v;
vector<int> tree;
int get(int node, int start, int end,int left,int right) {
    if (left > end || right < start)
        return 0;
    if (left <= start && end <= right)
        return tree[node];
    int mid = (start + end) / 2;
    return get(node * 2, start, mid, left, right) + get(node * 2 + 1, mid + 1, end, left, right);
}
void update(int node, int start, int end, int idx, int diff) {
    if (!(start <= idx && idx <= end))
        return;
    tree[node] += diff;
    if (start != end) {
        int mid = (start + end) / 2;
        update(node * 2, start, mid, idx, diff);
        update(node * 2 + 1, mid + 1, end, idx, diff);
    }
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    tree = vector<int>(N*4+1, 0);
    int temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        v.push_back({ -temp,-i });
    }
    sort(v.begin(), v.end());
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        cnt = max(cnt, get(1, 0, N - 1, 0, -v[i].second));
        update(1, 0, N - 1, -v[i].second, 1);
    }
    cout << cnt+1;
    return 0;
}