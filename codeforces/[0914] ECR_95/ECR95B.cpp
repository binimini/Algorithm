#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,a,b) for (int i = a; i<b; i++)
int T, N;
int arr[100];
bool locked[100] = { 0 };
vector<int> v;
int main() {
    FASTIO;
    cin >> T;
    FOR(t, 0, T) {
        cin >> N;
        FOR(i, 0, N) {
            cin >> arr[i];
        }
        FOR(i, 0, N) {
            cin >> locked[i];
            if (locked[i] == 0) {
                v.push_back(arr[i]);
            }
        }
        sort(v.begin(), v.end());
        FOR(i, 0, N) {
            if (locked[i]) {
                cout << arr[i] << " ";
            }
            else {
                cout << v.back() << " ";
                v.pop_back();
            }
        }
        cout << "\n";

    }
    return 0;
}