#include <bits/stdc++.h>
using namespace std;
int N, R = 0;
string s[11];
int arr[26] = { 0 };
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> s[i];
        for (int j = 0; j < s[i].size(); j++) {
            arr[s[i][j] - 'A'] += int(pow(10, s[i].size() - 1 - j));
        }
    }
    sort(arr, arr + 26);
    for (int i = 0; i <= 9; i++) {
        R += arr[25-i] * (9-i);
    }
    cout << R;
    return 0;
}