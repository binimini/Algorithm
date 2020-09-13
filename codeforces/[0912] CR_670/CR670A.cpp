#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,a,b) for(int i=a; i<b; i++)
int T, N;
int cnt[101] = { 0 };
int main() {
    FASTIO;
    cin >> T;
    FOR(t, 0, T) {
        for (int i = 0; i <= 100; i++) {
            cnt[i] = 0;
        }
        cin >> N;
        int temp;
        FOR(i,0,N){
            cin >> temp;
            cnt[temp]++;
        }
        int a = 0;
        while (1) {
            if (cnt[a] != 0) {
                cnt[a]--;
                a++;
            }
            else if (cnt[a] == 0)
                break;
        }
        int b = 0;
        while (1) {
            if (cnt[b] != 0) {
                cnt[b]--;
                b++;
            }
            else if (cnt[b] == 0)
                break;
        }
        cout << a + b << "\n";
    }
    return 0;
}