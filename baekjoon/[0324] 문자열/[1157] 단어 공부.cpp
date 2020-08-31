#include <iostream>
using namespace std;

int main() {
    string S;
    cin >> S;
    int arr[26] = { 0 };
    for (int i = 0; i < S.size(); i++) {
        int temp = S[i];
        if (temp >= 97) {
            arr[temp - 97]++;
        }
        else
            arr[temp - 65]++;
    }
    int lo, max = 0;
    for (int j = 0; j < 26; j++) {
        if (arr[j] > max) {
            max = arr[j];
            lo = j;
        }
    }
    char R = lo + 65;
    for (int k = 0; k < 26; k++) {
        if (arr[k] == max)
            if (k != lo) {
                cout << "?" << endl;
                break;
            }
        if (k == 25) {
            cout << R << endl;
            break;
        }
    }
}