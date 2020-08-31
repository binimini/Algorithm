#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef long long int ll;
int N;
vector<int> A;
map <int, int> B;
ll tree[2000001] = { 0 };
void update(int node, int start, int end, int index) {
    if (!(start <= index && index <= end)) return;
    tree[node] += 1;
    if (start == end) return;
    int mid = (start + end) / 2;
    update(node * 2, start, mid, index);
    update(node * 2 + 1, mid + 1, end, index);
}
ll sum(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}
int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    int key;
    A.push_back(0);
    for (int i = 1; i <= N; i++) {
        cin >> key;
        A.push_back(key);
    }
    for (int i = 1; i <= N; i++) {
        cin >> key;
        B[key] = i;
    }
    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        update(1, 1, N, B[A[i]]);
        ans += sum(1, 0, N - 1, B[A[i]], N);
    }
    cout << ans;
    return 0;
}