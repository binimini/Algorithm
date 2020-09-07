#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,a,b) for (int i = a; i<b; i++)
int T, N;
int arr[100000];
int main() {
    FASTIO;
    cin >> T;
    FOR(t, 0, T) {
        cin >> N;
        long long int sum = 0, cost = 0;
        FOR(i, 0, N) {
            cin >> arr[i];
            if (arr[i] > 0) {
                sum += arr[i];
            }
            else {
                sum += arr[i];
                if (sum < 0) {
                    cost -= sum;
                    sum = 0;
                }
            }
        }
        cout <<cost<< '\n';
    }
    return 0;
}