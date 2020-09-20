#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,a,b) for (int i = a; i<b; i++)
int T, N;
vector<int> dq;
vector<int> v;
int main() {
    FASTIO;
    cin >> N;
    int temp;
    FOR(i, 0, N) {
        cin >> temp;
        dq.push_back(temp);
    }
    sort(dq.begin(), dq.end());
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            v.push_back(dq[N/2+i/2]);
        }
        else {
            v.push_back(dq[i/2]);
        }
    }
    int pre = -1, cnt = 0;
    for (int i = 0; i < N; i++) {
        if (pre != -1 && i != N - 1) {
            if (v[i] < pre && v[i] < v[i + 1])
                cnt++;
        }
        pre = v[i];
    }
    cout << cnt << "\n";
    for (int i = 0; i < N; i++) {
        cout << v[i] << " ";
    }
    cout << "\n";
    
    return 0;
}