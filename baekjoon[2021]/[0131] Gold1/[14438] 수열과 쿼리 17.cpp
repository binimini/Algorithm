#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int N, M, INF = 1000000001;
int tree[400001] = { 0 }, arr[100001];

int init(int node, int start, int end) {
    if (start == end)
        return tree[node] = arr[start];
    int mid = (start + end) / 2;
    return tree[node] = min(init(node * 2, start, mid), init(node * 2 + 1, mid + 1, end));
}

int update(int node, int start, int end, int idx) {//최소값 기준 세그먼트 트리 update?
    //포함시 init 처럼 할 시 O(logN)?
    if (!(start<=idx&&idx<=end))
        return tree[node];//return INF면 바뀐 idx가 최소 아닌 경우 잘못된 답이 나올 수 있음?
    if (start == end)
        return tree[node] = arr[start];
    int mid = (start + end) / 2;
    return tree[node] = min(update(node * 2, start, mid, idx), update(node * 2 + 1, mid + 1, end, idx));
}

int query(int node, int start, int end, int left, int right) {
    if (left > end || right < start)
        return INF;
    if (left <= start && end <= right)
        return tree[node];

    int mid = (start + end) / 2;
    return min(query(node * 2, start, mid, left, right), query(node * 2 + 1, mid + 1, end, left, right));
}

int main() {
    FASTIO;
    cin >> N;//input
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    init(1, 0, N - 1);//segment tree initialization
    
    cin >> M;
    int a, b, c;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        if (a == 1) {//update
            arr[b - 1] = c;
            update(1,0,N-1,b-1);
        } else if (a == 2) {//query
            cout <<query(1,0,N-1, b-1, c-1)<<"\n";
        }
    }
    return 0;
}