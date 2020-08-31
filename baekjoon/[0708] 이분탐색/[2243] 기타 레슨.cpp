#include <iostream>
#include <algorithm>
using namespace std;
int N, M, L = 10001, R = 0, result, arr[100000];
bool check(int key) {
    int cnt = 1, min = key;
    for (int i = 0; i < N; i++) {
        if (min == 0)
            cnt++, min = key;
        if (min >= arr[i])
            min -= arr[i];
        else {
            cnt++;
            if (key > arr[i])
                min = key - arr[i];
            else if (key == arr[i]) {
                min = 0;
            }
            else return false;
        }
    }
    if (cnt <= M)
        return true;
    else return false;
}
int binary_search(int left, int right) {
    int mid;
    while (right - left >= 0) {
        mid = (left + right) / 2;
        if (check(mid)) {
            result = min(mid, result);
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return result;
}
int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        L = min(L, arr[i]);
        R += arr[i];
    }
    result = R;
    cout << binary_search(L, R);
    return 0;
}