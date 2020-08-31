#include <iostream>
using namespace std;
int main() {
    while (1) {
        int arr[3];
        int max = 0;
        cin >> arr[0] >> arr[1] >> arr[2];
        if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0)
            break;
        for (int i = 0; i < 3; i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }
        if (max * max * 2 == arr[0] * arr[0] + arr[1] * arr[1] + arr[2] * arr[2])
            cout << "right" << endl;
        else
            cout << "wrong" << endl;
    }
    return 0;
}