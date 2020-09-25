#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,a,b) for(int i = a; i<b; i++)
int T, N,Q;
int main() {
    FASTIO;
    cin >> T;
    FOR(t, 0, T) {
        cin >> N >> Q;
        bool incre = 1;
        int pre = 0;
        int temp;
        long long int result = 0;
        FOR(i, 0, N) {
            cin >> temp;
            if (temp > pre) {//증가
                if (!incre) {
                    incre = 1;
                    result -= pre;
                }
            }
            else if (temp < pre) {//감소
                if (incre) {
                    incre = 0;
                    result += pre;
                }
            }
            pre = temp;
        }
        if (incre)
            result += temp;
        cout << result << '\n';
    }
    return 0;
}