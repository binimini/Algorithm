#include <iostream>
#include <algorithm>
using namespace std;
int N, M, arr[5000], mini = 10001, maxi = 0, R;
int binary_search(int left, int right) {
    int mid;
    while (right - left >= 0) {
        mid = (right + left) / 2;
        int temp = 1, min_stan = arr[0], max_stan = arr[0];
        for (int i = 1; i < N; i++) {
            if (abs(arr[i] - min_stan) > mid || abs(max_stan - arr[i]) > mid) {
                temp++;
                min_stan = arr[i];
                max_stan = arr[i];
            }
            else {
                min_stan = min(min_stan, arr[i]);
                max_stan = max(max_stan, arr[i]);
            }
        }
        if (temp <= M) {
            R = min(mid, R);
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return R;
}
int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
    }
    R = maxi - mini;
    cout << binary_search(0, maxi - mini);
    return 0;
}