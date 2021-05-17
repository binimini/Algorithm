#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int T,N;
int arr[1000];
int main() {
    FASTIO;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int cnt = 0;
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        int temp;
        for (int i = N-1; i >=0; i--) {     //bubble sort
            for (int j = 0; j < i; j++) {
                if (arr[j] > arr[j + 1]) {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";

    }
    return 0;
}