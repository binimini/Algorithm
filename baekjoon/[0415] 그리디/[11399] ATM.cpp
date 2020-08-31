#include <iostream>
#include <algorithm>
using namespace std;
int N, arr[1000], result = 0, sum = 0;
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    for (int i = 0; i < N; i++) {
        sum += arr[i];
        result += sum;
    }
    cout << result << "\n";
}