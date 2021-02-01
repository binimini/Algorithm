#include <iostream>
#include <vector>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int N, M, K;
vector<long long int> arr, tree;

long long int init(int node, int start, int end) {
    if (start == end) 
        return tree[node] = arr[start];
    
    int mid = (start + end) / 2;
    return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}
void update(int node, int start, int end, int index, long long int differ) {
    if (!(start <= index && index <= end)) return;
    
    tree[node] += differ;
    if (start != end) {//update child node
        int mid = (start + end) / 2;
        update(node * 2, start, mid, index, differ);
        update(node * 2 + 1, mid + 1, end, index, differ);
    }
}
long long int sum(int node, int start, int end, int left, int right) {
    if (start > right || end < left) 
        return 0;
    if (left <= start && end <= right) 
        return tree[node];

    int mid = (start + end) / 2;
    return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

int main() {//20210201 refactoring
    FASTIO;
    cin >> N >> M >> K;

    long long int treesize = N;//initialization
    treesize *= 4;
    arr.assign(N, 0);
    tree.assign(treesize, 0);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    init(1, 0, N - 1);
    
    long long int a, b, c, temp;
    for (int i = 0; i < M + K; i++) {//query
        cin >> a >> b >> c;
        if (a == 1) {
            temp = c - arr[b - 1];//c long long int, temp also have to be long long int
            arr[b - 1] = c;
            update(1, 0, N - 1, b - 1, temp);
        }
        else if (a == 2) 
            cout << sum(1, 0, N - 1, b - 1, c - 1) << "\n";
    }
    return 0;
}