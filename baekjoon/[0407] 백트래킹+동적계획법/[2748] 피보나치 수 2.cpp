#include <iostream>
using namespace std;
long long int arr[91];
long long int fibo(int n) {
    for (int i = 0; i <= n; i++) {
        if (i == 0)
            arr[0] = 0;
        if (i == 1)
            arr[1] = 1;
        else if (i >= 2) {
            arr[i] = arr[i - 1] + arr[i - 2];
        }
    }
    return arr[n];
}
int main() {
    int N;
    cin >> N;
    cout << fibo(N);
    return 0;
}