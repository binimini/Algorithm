#include <iostream>
using namespace std;
int N, M, K, arr[1000000], tree[4000001];
int init(int node, int start, int end) {
    if (start == end)
        return tree[node] = arr[start];
    int mid = (start + end) / 2;
    int temp1 = init(node * 2, start, mid);
    int temp2 = init(node * 2 + 1, mid + 1, end);
    long long int temp = temp1;
    temp = (temp * temp2) % 1000000007;
    return tree[node] = temp;
}
void change(int node, int start, int end, int index, int differ) {
    if (!(start <= index && index <= end))
        return;
    if (start == end) {
        tree[node] += differ;
        return;
    }
    int mid = (start + end) / 2;
    change(node * 2, start, mid, index, differ);
    change(node * 2 + 1, mid + 1, end, index, differ);
    long long int temp = tree[node * 2];
    temp = (temp * tree[node * 2 + 1]) % 1000000007;
    tree[node] = temp;
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
    long long int temp = t1;
    temp = (temp * t2) % 1000000007;
    return temp;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    init(1, 0, N - 1);
    int a, b, c;
    for (int i = 0; i < M + K; i++) {
        cin >> a >> b >> c;
        if (a == 1) {
            change(1, 0, N - 1, b - 1, c - arr[b - 1]);
            arr[b - 1] = c;
        }
        else if (a == 2) {
            cout << query(1, 0, N - 1, b - 1, c - 1) << "\n";
        }
    }
    return 0;
}