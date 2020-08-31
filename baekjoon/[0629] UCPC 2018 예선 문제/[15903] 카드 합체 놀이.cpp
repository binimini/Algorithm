#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
long long int arr[1000];
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < m; i++) {
        sort(arr, arr + n);
        long long int temp = arr[0] + arr[1];
        arr[0] = temp, arr[1] = temp;
    }
    long long int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    cout << sum;

}