#include <bits/stdc++.h>
using namespace std;
int T,N,K;
int tree[400004], arr[100001];
vector<int> result;
int init(int node, int start, int end) {
    if (start == end) {
        return tree[node] = arr[start];
    }
    int mid = (start + end) / 2;
    tree[node] = init(node * 2, start, mid) * init(node * 2 + 1, mid + 1, end);
    return tree[node];
}
void update(int node, int start, int end, int idx,int pre, int to) {
    if (!(start <= idx && idx <= end))
        return;
    if (pre == 0) {//arr[idx] 바꿔놓은 후에
        init(node, start, end);
    }
    else {
        if (pre == -1 && to == 1)
            tree[node] *= -1;
        else
            tree[node] *= to;
        if (start != end) {
            int mid = (start + end) / 2;
            update(node * 2, start, mid, idx, pre, to);
            update(node * 2 + 1, mid + 1, end, idx, pre, to);
        }
    }
}
int query(int node, int start, int end, int left, int right) {
    if (right < start || left > end) {
        return 1;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    return query(node * 2, start, mid, left, right) * query(node * 2 + 1, mid + 1, end, left, right);
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(cin >>N>>K){
        result.clear();
        for (int i = 1; i <= N; i++) {
            cin >> arr[i];
            if (arr[i] > 0)
                arr[i] = 1;
            else if (arr[i] < 0)
                arr[i] = -1;
            else
                arr[i] = 0;
        }
        init(1, 1, N);
        char comm;
        int a, b;
        for (int i = 0; i < K; i++) {
            cin >> comm >> a >> b;
            if (comm == 'C') {
                if (b > 0)
                    b = 1;
                else if (b < 0)
                    b = -1;
                int temp = arr[a];
                arr[a] = b;
                if (temp == arr[a])
                    continue;
                update(1, 1, N, a, temp, arr[a]);
            }
            else if (comm == 'P') {
                result.push_back(query(1, 1, N, a, b));
            }
        }
        for (int i = 0; i < result.size(); i++) {
            if (result[i] == 1)
                cout << '+';
            else if (result[i] == -1)
                cout << '-';
            else
                cout << '0';
        }
        cout << "\n";
    }
    return 0;
}