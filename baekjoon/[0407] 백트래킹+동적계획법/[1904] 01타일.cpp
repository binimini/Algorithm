#include <iostream>
using namespace std;
int arr[1000001];
int main() {
    int N;
    cin >> N;
    arr[1] = 1;
    arr[2] = 2;
    for (int i = 3; i <= N; i++) {
        arr[i] = (arr[i - 1] + arr[i - 2]) % 15746;
    }
    cout << arr[N] << '\n';
    return 0;
}