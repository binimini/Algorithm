#include <iostream>
using namespace std;
typedef long long int ll;
int N, Q, arr[100000];
ll tree[400001];
ll init(int node, int start, int end) {
    if (start == end)
        return tree[node] = arr[start];
    int mid = (start + end) / 2;
    return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}
void update(int node, int start, int end, int index, ll differ) {
    if (!(start <= index && index <= end))
        return;
    tree[node] += differ;
    if (start == end)
        return;
    int mid = (start + end) / 2;
    update(node * 2, start, mid, index, differ);
    update(node * 2 + 1, mid + 1, end, index, differ);
}
ll query(int node, int start, int end, int left, int right) {
    if (left > end || right < start)
        return 0;
    if (left <= start && end <= right)
        return tree[node];
    int mid = (start + end) / 2;
    return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}
int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    init(1, 0, N - 1);
    int a, b, c, d;
    long long int temp;
    for (int i = 0; i < Q; i++) {
        cin >> a >> b >> c >> d;
        if (a <= b)
            cout << query(1, 0, N - 1, a - 1, b - 1) << "\n";
        else
            cout << query(1, 0, N - 1, b - 1, a - 1) << "\n";
        temp = d;
        temp -= arr[c - 1];
        update(1, 0, N - 1, c - 1, temp);
        arr[c - 1] = d;
    }
    return 0;
}