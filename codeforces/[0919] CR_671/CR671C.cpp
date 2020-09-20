#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,a,b) for (int i = a; i<b; i++)
int T, N, X;
int arr[1000];
int main() {
    FASTIO;
    cin >> T;
    FOR(t, 0, T) {
        cin >> N >> X;
        int cntp = 0, cntm = 0;
        bool CH = 1, FLAG = 0;
        FOR(i, 0, N) {
            cin >> arr[i];
            if (arr[i] != X)
                CH = 0;
            if (arr[i] - X < 0)
                cntm += (arr[i] - X);
            else if (arr[i] - X > 0)
                cntp += (arr[i] - X);
            if (arr[i] == X)
                FLAG = 1;
        }
        if (CH == 1)
            cout << 0 << "\n";
        else if (cntm + cntp == 0)
            cout << 1 << "\n";
        else {
            if (FLAG)
                cout << 1 << "\n";
            else
                cout << 2 << "\n";
        }
    }
    return 0;
}