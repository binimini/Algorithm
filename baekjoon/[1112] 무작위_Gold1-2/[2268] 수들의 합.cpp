#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
long long int tree[4000004] = { 0 };
int arr[1000001] = { 0 };
int N, M;
void update(int node, int start, int end, int idx, int diff) {
    if (!(start <= idx && idx <= end))
        return;
    tree[node] += diff;
    if (start != end) {
        int mid = (start + end) / 2;
        update(node * 2, start, mid, idx, diff);
        update(node * 2+1, mid+1, end, idx, diff);
    }
}
ll sum(int node, int start, int end, int left, int right) {
    if (end < left || right < start)
        return 0;
    if (left <= start && end <= right)
        return tree[node];
    int mid = (start + end) / 2;
    return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}
int main() {
    FASTIO;
    cin >> N >> M;
    int a, b, c;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        if (a) {
            update(1, 1, N, b, c - arr[b]);
            arr[b] = c;
        }
        else {
            cout << sum(1, 1, N, min(b,c), max(b,c)) << "\n";
        }
    }
    return 0;
}