#include <bits/stdc++.h>
using namespace std;
int N, M, K;
long long int arr[1000000];
long long int tree[4000004], lazy[4000004];
long long int init(int node, int start, int end) {
    if (start == end)
        return tree[node] = arr[start];
    int mid = (start + end) / 2;
    return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}
void update_lazy(int node, int start, int end) {
    if (lazy[node] != 0) {
        tree[node] += lazy[node] * (end - start + 1);
        if (start != end) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}
void update_range(int node, int start, int end, int left, int right,long long int diff) {
    update_lazy(node, start, end);
    if (left > end || right < start)
        return;
    if (left <= start && end <= right) {
        tree[node] += diff * (end - start + 1);
        if (start != end) {
            lazy[node * 2] += diff;
            lazy[node * 2+1] += diff;
        }
        return;
    }
    int mid = (start + end) / 2;
    update_range(node * 2, start, mid, left, right, diff);
    update_range(node * 2+1, mid+1, end, left, right, diff);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
long long sum(int node, int start, int end, int left, int right) {
    update_lazy(node, start, end);
    if (left > end || right < start)
        return 0;
    if (left <= start && end <= right)
        return tree[node];
    int mid = (start + end) / 2;
    return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    init(1, 0, N - 1);
    int a, b, c;
    long long d;
    for (int i = 0; i < M + K; i++) {
        cin >> a;
        if (a == 1) {
            cin >> b >> c >> d;
            update_range(1, 0, N - 1, b - 1, c - 1, d);
        }
        else {
            cin >> b >> c;
            cout << sum(1, 0, N - 1, b-1, c-1) << '\n';
        }
    }
    return 0;
}