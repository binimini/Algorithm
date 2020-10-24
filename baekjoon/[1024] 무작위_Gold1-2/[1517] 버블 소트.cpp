#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i<b; i++)
int N;
pair<int, int> arr[500000];
long long int tree[2000001] = { 0 };
void update(int node, int start, int end, int index, long long int diff) {//node tree 번호(1부터시작) start, end, index(arr, 0부터시작), diff 차이값 
    if (!(start <= index && index <= end))
        return;
    tree[node] += diff;
    if (start == end)
        return;
    int mid = (start + end) / 2;
    update(node * 2, start, mid, index, diff);
    update(node * 2+1, mid+1, end, index, diff);
}
long long int sum(int node, int start, int end, int left, int right) {//left right 구하고자하는 범위
    if (start > right || end < left)
        return 0;
    if (left <= start && end <= right)
        return tree[node];
        
    int mid = (start + end) / 2;
    return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    FOR(i, 0, N) {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr, arr + N);
    long long int cnt = 0;
    FOR(i, 0, N) {
        cnt += sum(1, 0, N - 1, arr[i].second, N - 1);
        update(1, 0, N - 1, arr[i].second, 1);
    }
    cout << cnt;
    return 0;
}