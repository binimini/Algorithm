#include <bits/stdc++.h>
using namespace std;
int tree[400004], arr[100001], N, MAX_VALUE = 0, MAX_IDX;//tree array size 4*N
long long int sum[100001] = { 0 }, INF = 10000000;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int init(int node, int start, int end) {
    if (start == end)
        return tree[node] = start;

    int mid = (start + end) / 2;
    return tree[node] = (arr[init(node * 2, start, mid)] <= arr[init(node * 2 + 1, mid + 1, end)]) ? tree[node * 2] : tree[node * 2 + 1];
}
int query(int node, int start, int end, int left, int right) {
    if (right < start || end < left)
        return 0;
    else if (left <= start && end <= right)
        return tree[node];

    int mid = (start + end) / 2;
    int temp1 = query(node * 2, start, mid, left, right);
    int temp2 = query(node * 2 + 1, mid + 1, end, left, right);
    return (arr[temp1] <= arr[temp2]) ? temp1 : temp2;
}
long long int solve(int start, int end) {
    if (start > end)
        return 0;
    int idx = query(1, 1, N, start, end);
    return max((sum[end] - sum[start - 1]) * arr[idx], max(solve(start, idx - 1),solve(idx+1, end)));
}
int main() {
    FASTIO;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        sum[i] = sum[i - 1] + arr[i];
        if (MAX_VALUE < arr[i]) {
            MAX_VALUE = arr[i];
            MAX_IDX = i;
        }
    }
    arr[0] = INF;

    init(1, 1, N);//segment tree init
    cout << solve(1, N);
    return 0;
}