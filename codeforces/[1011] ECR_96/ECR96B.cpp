#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FOR(i,a,b) for (int i = a; i<b; i++)
int T, N, K;
int main() {
    FASTIO;
    cin >> T;
    FOR(t, 0, T) {
        vector<int> v;
        cin >> N >> K;
        int temp;
        FOR(i, 0, N) {
            cin >> temp;
            v.push_back(temp);
        }
        sort(v.begin(), v.end());

        long long int m = v.back();
        v.pop_back();
        while (K != 0) {
            K--;
            m += v.back();
            v.pop_back();
        }
        cout << m << "\n";
    }
    return 0;
}