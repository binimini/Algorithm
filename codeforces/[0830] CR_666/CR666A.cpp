#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,a,b) for (int i = a; i<b; i++)
int T, N;
int main() {
    FASTIO;
    cin >> T;
    FOR(t, 0, T) {
        cin >> N;
        int arr[26] = { 0 };
        string temp;
        FOR(i, 0, N) {
            cin >> temp;
            FOR(j, 0, temp.size()) {
                arr[temp[j] - 'a']++;
            }
        }
        bool CH = 1;
        FOR(i, 0, 26) {
            if (arr[i] % N != 0) {
                CH = 0;
                break;
            }
        }
        if (CH == 1)
            cout << "YES\n";
        else if (CH == 0)
            cout << "NO\n";
    }
    return 0;
}