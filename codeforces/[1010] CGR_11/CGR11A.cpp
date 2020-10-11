#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FOR(i,a,b) for (int i = a; i<b; i++)
int T, N;
int arr[50];
int main() {
    FASTIO;
    cin >> T;
    FOR(t, 0, T) {
        vector<int> v;
        int zero_cnt = 0, sum = 0;
        cin >> N;
        FOR(i, 0, N) {
            cin >> arr[i];
            if (arr[i] == 0)
                zero_cnt++;
            else {
                sum += arr[i];
                v.push_back(arr[i]);
            }
        }
        if (sum == 0)
            cout << "NO\n";
        else {
            cout << "YES\n";
            if (sum > 0) {
                sort(v.begin(), v.end(), greater<int>());
                FOR(j, 0, v.size()) {
                    cout << v[j] << " ";
                }
            }
            else {
                sort(v.begin(), v.end(), less<int>());
                FOR(j, 0, v.size()) {
                    cout << v[j] << " ";
                }
            }
            FOR(j, 0, zero_cnt) {
                cout << 0 << " ";
            }
            cout << '\n';
        }
    }
    return 0;
}