#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,a,b) for (int i = a; i<b; i++)
int N;
int arr[100000];
int main() {
    FASTIO;
    cin >> N;
    FOR(i, 0, N) {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    if (N % 2 == 0)
        cout << N / 2 - 1 << '\n';
    else
        cout << N / 2 << '\n';
    FOR(i, 0, N) {
        if (i % 2 == 0) {
            cout << arr[N / 2 + i/2] << " ";
        }
        else
            cout << arr[i/2] << " ";
    }
    cout << "\n";
    return 0;
}