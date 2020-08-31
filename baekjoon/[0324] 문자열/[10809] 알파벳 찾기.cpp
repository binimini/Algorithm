#include <iostream>
using namespace std;

int main() {
    string S;
    int arr[26];
    for (int i = 0; i < 26; i++) {
        arr[i] = -1;
    }
    cin >> S;
    for (int j = S.size() - 1; j > -1; j--) {
        int temp = S[j] - 97;
        arr[temp] = j;
    }
    for (int k = 0; k < 26; k++) {
        cout << arr[k] << ' ';
    }

    return 0;
}