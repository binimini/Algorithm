#include <iostream>
using namespace std;

int main() {

    int N;
    cin >> N;
    int* A = new int[N];
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        A[i] = a + b;
    }
    for (int j = 0; j < N; j++) {
        cout << A[j] << endl;
    }
    return 0;
}