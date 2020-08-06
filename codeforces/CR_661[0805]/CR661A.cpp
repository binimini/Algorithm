#include <bits/stdc++.h>
using namespace std;
int T, N;
int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        bool CH = 0;
        int arr[50] = { 0 };
        for (int j = 0; j < N; j++) {
            cin >> arr[j];
        }
        sort(arr, arr + N);
        for (int j = 0; j < N; j++) {
            if (arr[j + 1] - arr[j] > 1) {
                CH = 1;
                break;
            }
        }
        if (CH == 1)
            cout << "NO" << "\n";
        else if (CH == 0)
            cout << "YES" << "\n";
    }
}