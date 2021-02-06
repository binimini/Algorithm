#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int N, Q;
ll tree[4000001] = { 0 }, arr[1000001] = { 0 };
void update(int node, int start, int end, int idx, ll differ) {
    if (!(start <= idx && idx <= end))
        return;
    tree[node] += differ;
    if (start != end) {
        int mid = (start + end) / 2;
        update(node * 2, start, mid, idx, differ);
        update(node * 2 + 1, mid + 1, end, idx, differ);
    }
}
ll query(int node, int start, int end, int left, int right) {
    if (start > right || end < left)
        return 0;
    if (left <= start && end <= right)
        return tree[node];
    int mid = (start + end) / 2;
    return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}

int main() {
    FASTIO;
    cin >> N >> Q;
    int a, b, c;
    ll temp;
    for (int i = 0; i < Q; i++) {
        cin >> a >> b >> c;
        if (a == 1) {//if already added, add value
            arr[b - 1] += c;
            update(1, 0, N - 1, b - 1, c);
        }
        else if (a == 2) {
            cout << query(1, 0, N - 1, b - 1, c - 1)<<"\n";
        }
    }
    return 0;
}