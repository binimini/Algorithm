#include <iostream>
using namespace std;
long long int arr[101];
int T, N;
int main() {
    cin >> T;
    for (int j = 0; j < T; j++) {
        cin >> N;
        arr[1] = 1, arr[2] = 1, arr[3] = 1, arr[4] = 2, arr[5] = 2;
        for (int i = 6; i <= N; i++) {
            arr[i] = arr[i - 1] + arr[i - 5];
        }
        cout << arr[N] << '\n';
    }
    return 0;
}