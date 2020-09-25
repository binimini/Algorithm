#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,a,b) for(int i = a; i<b; i++)
int T, N;
int main() {
    FASTIO;
    cin >> T;
    int temp;
    FOR(t, 0, T) {
        cin >> N;
        bool flag = true;
        int pre = 1000000001;
        FOR(i, 0, N) {
            cin >> temp;
            if (pre <= temp)
                flag = false;
            pre = temp;
        }
        if (flag)
            cout << "NO" << "\n";
        else
            cout << "YES" << "\n";
    }
    return 0;
}