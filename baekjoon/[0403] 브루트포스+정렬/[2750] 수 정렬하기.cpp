#include <iostream>
using namespace std;
int arr[1000];
void bubblesort(int n) {
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            int temp;
            if (arr[j] > arr[j + 1]) {
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    bubblesort(N);
    for (int j = 0; j < N; j++) {
        cout << arr[j] << '\n';
    }
    return 0;
}