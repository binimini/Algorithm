#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int arr[100000], check = 0;
int main() {
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    string temp;
    cin >> temp;
    int size = temp.size();
    int sum = 0;
    for (int i = 0; i < size; i++) {
        arr[i] = temp[i] - '0';
        if (arr[i] == 0)
            check = 1;
        sum += arr[i];
    }
    sort(arr, arr + size, greater<int>());
    if (check == 1) {
        if (sum % 3 == 0) {
            for (int i = 0; i < size; i++) {
                cout << arr[i];
            }
        }
        else
            cout << -1 << "\n";
    }
    else
        cout << -1 << "\n";

}