#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int* arr = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    int sum, c = N * (N - 1) * (N - 2) / 6, count = 0, max = 0;
    int* num = new int[c];
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                sum = 0;
                sum += arr[i] + arr[j] + arr[k];
                if (sum <= M) {
                    num[count] = sum;
                    count++;
                }
            }
        }
    }
    for (int i = 0; i < count + 1; i++) {
        if (max < num[i])
            max = num[i];
    }
    cout << max << '\n';
    return 0;
}