#include <iostream>
#include <algorithm>
using namespace std;
int arr[100001], N, M;
bool BinarySearch(int start, int end, int key) {
    while (end - start >= 0) {
        int mid = (start + end) / 2;
        if (arr[mid] == key)
            return true;
        else if (key > arr[mid])
            start = mid + 1;
        else
            end = mid - 1;
    }
    return false;
}
int main() {
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N + 1);
    cin >> M;
    for (int j = 1; j <= M; j++) {
        int temp;
        cin >> temp;
        cout << BinarySearch(1, N, temp) << "\n";
    }
    return 0;
}