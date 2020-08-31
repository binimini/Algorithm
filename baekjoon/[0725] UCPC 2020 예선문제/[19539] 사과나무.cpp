#include <iostream>
using namespace std;
int N, arr[100000];
int main() {
    cin >> N;
    int sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    if (sum % 3 != 0) {
        cout << "NO";
    }
    else if (sum % 3 == 0) {
        int temp = 0;
        for (int i = 0; i < N; i++) {
            temp += arr[i] / 2;
        }
        if (temp >= sum / 3) {
            cout << "YES";
        }
        else cout << "NO";
    }
    return 0;
}