#include <iostream>
using namespace std;

int main() {
    int N, count = 0;
    cin >> N;
    if (N >= 100) {
        int arr[1000] = { 0 };
        for (int i = 0; i < 99; i++) {
            arr[i] = 1;
        }
        for (int i = 101; i <= 999; i++) {
            if ((i / 100) - (i % 100 / 10) == ((i % 100 / 10) - (i % 10)))
                arr[i - 1] = 1;
        }

        for (int j = 1; j <= N; j++) {
            if (arr[j - 1] == 1)
                count += 1;
        }
    }
    else
        count = N;
    cout << count << endl;
    return 0;
}