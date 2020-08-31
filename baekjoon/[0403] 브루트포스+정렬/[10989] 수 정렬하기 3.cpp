#include <iostream>
using namespace std;
int arr[10000] = { 0 };
void counting_sort(int n) {
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        arr[temp - 1]++;
    }
    for (int j = 0; j < 10000; j++) {
        for (int k = 0; k < arr[j]; k++) {
            cout << j + 1 << '\n';
        }
    }
}
int main() {
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    counting_sort(N);
    return 0;
}