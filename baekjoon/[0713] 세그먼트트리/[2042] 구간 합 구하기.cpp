#include <iostream>
#include <vector>
using namespace std;
int N, M, K;
vector<long long int> arr, tree;
long long int init(vector<long long int>& arr, vector<long long int>& tree, int node, int start, int end) {
    if (start == end) {
        return tree[node] = arr[start];
    }
    int mid = (start + end) / 2;
    return tree[node] = init(arr, tree, node * 2, start, mid) + init(arr, tree, node * 2 + 1, mid + 1, end);
}
void update(vector<long long int>& tree, int node, int start, int end, int index, long long int differ) {
    if (!(start <= index && index <= end)) return;
    tree[node] += differ;
    if (start != end) {
        int mid = (start + end) / 2;
        update(tree, node * 2, start, mid, index, differ);
        update(tree, node * 2 + 1, mid + 1, end, index, differ);
    }
}
long long int sum(vector<long long int>& tree, int node, int start, int end, int left, int right) {
    if (start > right || end < left) return 0;
    if (left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    return sum(tree, node * 2, start, mid, left, right) + sum(tree, node * 2 + 1, mid + 1, end, left, right);
}
int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> K;
    long long int temp;
    arr.assign(N, 0);
    long long int treesize = N;
    treesize *= 4;
    tree.assign(treesize, 0);
    for (int i = 0; i < N; i++) {
        cin >> temp;
        arr[i] = temp;
    }
    init(arr, tree, 1, 0, N - 1);
    long long int a, b, c;
    for (int i = 0; i < M + K; i++) {
        cin >> a >> b >> c;
        if (a == 1) {
            int temp = c - arr[b - 1];
            arr[b - 1] = c;
            update(tree, 1, 0, N - 1, b - 1, temp);
        }
        else if (a == 2) cout << sum(tree, 1, 0, N - 1, b - 1, c - 1) << "\n";
    }
    return 0;
}