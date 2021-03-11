#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int N;
long long int ldp[100001], rdp[100001], INF = 10000000001;
int house[100001] = { 0 };
int main() {
    FASTIO;
    memset(ldp, -1, sizeof(ldp));
    memset(rdp, -1, sizeof(rdp));
    cin >> N;
    int temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        house[temp]++;
    }
    int cnt = 0;
    int prev = -1;
    long long int c;
    for (int i = 1; i <= 100000; i++) {
        if (house[i]) {
            if (prev == -1)
                ldp[i] = 0;
            else {
                c = i;
                c -= prev;
                c *= cnt;
                ldp[i] = c + ldp[prev];
            }
            prev = i;
            cnt+=house[i];
        }
    }
    prev = -1;
    cnt = 0;
    for (int i = 100000; i >= 1; i--) {
        if (house[i]) {
            if (prev == -1)
                rdp[i] = 0;
            else {
                c = prev;
                c -= i;
                c *= cnt;
                rdp[i] = c + rdp[prev];
            }
            prev = i;
            cnt+=house[i];
        }
    }
    pair<long long int, int> res = { INF, 0 };
    for (int i = 1; i <= 100000; i++) {
        if (ldp[i] == -1 && rdp[i] == -1) continue;
        if (ldp[i] == -1)
            ldp[i] = 0;
        if (rdp[i] == -1)
            rdp[i] = 0;
        if (rdp[i] + ldp[i] < res.first)
            res.first = rdp[i] + ldp[i], res.second = i;
    }
    cout << res.second;
}