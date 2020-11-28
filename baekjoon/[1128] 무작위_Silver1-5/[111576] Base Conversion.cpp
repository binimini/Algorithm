#include <bits/stdc++.h>
using namespace std;
int A, B, M;
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> A >> B;
    cin >> M;
    int v = 0, temp;
    for (int i = M-1; i >=0; i--) {
        cin >> temp;
        v += temp * (int)pow(A, i);
    }
    int cnt = 0;
    long long int mod = 1;
    while (v >= mod) {
        cnt++;
        mod = (int)pow(B, cnt);
    }
    cnt--;
    while (cnt != -1) {
        mod = (int)pow(B, cnt);
        cout << v / mod << " ";
        v = v % mod;
        cnt--;
    }
    return 0;
}