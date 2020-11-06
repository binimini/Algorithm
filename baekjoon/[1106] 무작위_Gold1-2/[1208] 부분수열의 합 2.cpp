#include <bits/stdc++.h>
using namespace std;
int N,S,arr[40];
vector<int> A, B;
long long int cnt = 0;
void dfsA(int n,int sum) {
    if (n == N / 2) {
        A.push_back(sum);
        return;
    }
    dfsA(n + 1, sum + arr[n]);
    dfsA(n + 1, sum);
}
void dfsB(int n, int sum) {
    if (n == N) {
        B.push_back(sum);
        return;
    }
    dfsB(n + 1, sum + arr[n]);
    dfsB(n + 1, sum);
}
int lb(int k) {
    int s = 0, e = A.size(), m;
    while (e - s > 0) {
        m = (s + e) / 2;
        if (A[m] < k)
            s = m + 1;
        else
            e = m;
    }
    return e;
}
int ub(int k) {
    int s = 0, e = A.size(), m;
    while (e - s > 0) {
        m = (s + e) / 2;
        if (A[m] <= k)
            s = m + 1;
        else
            e = m;
    }
    return e;
}
int main() {
    cin >> N >>S;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    dfsA(0,0);
    dfsB(N/2,0);
    sort(A.begin(), A.end());
    for (int i = 0; i < B.size(); i++) {
        cnt += ub(S - B[i]);
        cnt -= lb(S - B[i]);
    }
    if (S == 0)
        cnt--;
    cout << cnt;
    return 0;
}