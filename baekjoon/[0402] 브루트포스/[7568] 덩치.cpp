#include <iostream>
using namespace std;
int main() {
    int N;
    cin >> N;
    int** arr = new int* [N];
    int* result = new int[N];
    for (int i = 0; i < N; i++) {
        result[i] = N;
        arr[i] = new int[2];
        cin >> arr[i][0] >> arr[i][1];
    }
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if ((arr[i][0] > arr[j][0]) && (arr[i][1] > arr[j][1]))
                result[i]--;
            else if ((arr[i][0] < arr[j][0]) && (arr[i][1] < arr[j][1]))
                result[j]--;
            else
                result[i]--, result[j]--;
        }
    }
    for (int k = 0; k < N; k++) {
        cout << result[k] << " ";
    }
    return 0;
}