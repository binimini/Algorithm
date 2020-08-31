#include <iostream>
#include <algorithm>
using namespace std;
int N, M, E = 0, H = 0, H_arr[1000000];
long long int sum = 0;
int binary_search(int start, int end) {
    int mid;
    while (end - start >= 0) {
        mid = (end + start) / 2;
        sum = 0;
        for (int i = 0; i < N; i++) {
            if (H_arr[i] <= mid) continue;
            else sum = sum + H_arr[i] - mid;
        }
        if (sum > M) {
            start = mid + 1;
            H = max(H, mid);
        }
        else if (sum == M) {
            return mid;
        }
        else if (sum < M)
            end = mid - 1;
    }
    return H;
}
int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> H_arr[i];
        E = max(E, H_arr[i]);
    }
    cout << binary_search(0, E);
    return 0;
}