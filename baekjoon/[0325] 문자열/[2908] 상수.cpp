#include <iostream>
using namespace std;

int main() {
    string A, B;
    cin >> A >> B;
    int new_A = 0, new_B = 0;
    for (int i = 2; i >= 0; i--) {
        int a = A[i] - '0';
        int b = B[i] - '0';
        new_A = new_A * 10 + a;
        new_B = new_B * 10 + b;
    }
    if (new_A > new_B)
        cout << new_A << endl;
    else
        cout << new_B << endl;
    return 0;
}