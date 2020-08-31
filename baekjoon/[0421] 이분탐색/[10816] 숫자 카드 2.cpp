#include <iostream>
#include <algorithm>
using namespace std;
int N, M, arr[500000];
int lower_bound(int start, int end, int key) {
    while (end - start > 0) {
        int mid = (start + end) / 2;
        if (arr[mid] < key)
            start = mid + 1;
        else
            end = mid;
    }
    return end;
}
int upper_bound(int start, int end, int key) {
    while (end - start > 0) {
        int mid = (start + end) / 2;
        if (arr[mid] <= key)
            start = mid + 1;
        else
            end = mid;
    }
    return end;//+1 안하면 0 기준 인덱스 +1 하면 1 기준 인덱스
}
int main() {
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    cin >> M;
    for (int i = 0; i < M; i++) {
        int temp;
        cin >> temp;
        cout << upper_bound(0, N, temp) - lower_bound(0, N, temp) << "\n";
    }
    return 0;
}