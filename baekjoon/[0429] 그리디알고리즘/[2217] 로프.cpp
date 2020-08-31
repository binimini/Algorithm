#include <iostream>
#include <algorithm>
using namespace std;
int N, arr[100000], M = 0;
int main() {
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N, greater<int>());
    for (int i = 0; i < N; i++) {
        M = max(arr[i] * (i + 1), M);
    }
    cout << M << "\n";
}