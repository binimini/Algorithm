#include <iostream>
#include <algorithm>
using namespace std;
int N, M, arr[100000], tree[400001];
int init(int node, int start, int end) {
    if (start == end)
        return tree[node] = arr[start];
    int mid = (start + end) / 2;
    int temp1 = init(node * 2, start, mid);
    int temp2 = init(node * 2 + 1, mid + 1, end);
    return tree[node] = min(temp1, temp2);
}
int query(int node, int start, int end, int left, int right) {
    if (left > end || right < start)
        return -1;
    if (left <= start && end <= right)
        return tree[node];
    int mid = (start + end) / 2;
    int t1 = query(node * 2, start, mid, left, right);
    int t2 = query(node * 2 + 1, mid + 1, end, left, right);
    if (t1 == -1)
        return t2;
    else if (t2 == -1)
        return t1;
    return min(t1, t2);
}
int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    init(1, 0, N - 1);
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        cout << query(1, 0, N - 1, a - 1, b - 1) << "\n";
    }
    return 0;
}