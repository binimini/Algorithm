#include <iostream>
using namespace std;

int dn(int a) {
    int dn;
    if (a >= 1000)
        dn = a % 10 + a % 100 / 10 + a % 1000 / 100 + a / 1000 + a;
    else if (a >= 100)
        dn = a % 10 + a % 100 / 10 + a / 100 + a;
    else if (a >= 10)
        dn = a % 10 + a / 10 + a;
    else
        dn = a + a;
    return dn;
}

int main() {
    int arr[10000] = { 0 };
    for (int i = 0; i < 10000; i++) {
        if (dn(i + 1) - 1 <= 9999) {
            arr[dn(i + 1) - 1] = 1;
        }
    }

    for (int j = 0; j < 10000; j++) {
        if (arr[j] == 0)
            cout << j + 1 << endl;
    }

    return 0;
}
