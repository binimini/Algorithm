#include <iostream>
#include <algorithm>
using namespace std;
int N, M, arr[100000];
pair<int, int> tree[400001], base = { 1000000001, 0 };//min, max
pair<int, int> init(int node, int start, int end) {
    if (start == end)
        return tree[node] = make_pair(arr[start], arr[start]);
    int mid = (start + end) / 2;
    pair<int, int> p1 = init(node * 2, start, mid);
    pair<int, int> p2 = init(node * 2 + 1, mid + 1, end);
    return tree[node] = make_pair(min(p1.first, p2.first), max(p1.second, p2.second));
}
pair<int, int> find(int node, int start, int end, int left, int right) {
    if (right<start || left>end) return base;
    if (left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    pair<int, int> p1 = find(node * 2, start, mid, left, right);
    pair<int, int> p2 = find(node * 2 + 1, mid + 1, end, left, right);
    return make_pair(min(p1.first, p2.first), max(p1.second, p2.second));
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
    pair<int, int> temp;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        temp = find(1, 0, N - 1, a - 1, b - 1);
        cout << temp.first << ' ' << temp.second << "\n";
    }
    return 0;
}