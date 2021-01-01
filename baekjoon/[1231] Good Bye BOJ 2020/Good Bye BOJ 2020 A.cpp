#include <bits/stdc++.h>
using namespace std;
int N;
int main() {
    std::ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    string s;
    bool flag = 1;
    char temp, ch;
    for (int i = 0; i < N; i++) {
        cin >> s;
        temp = s[0];
        if (i == 0)
            ch = temp;
        else {
            if (ch != temp) {
                flag = 0;
                break;
            }
        }
    }
    cout << flag;
    return 0;
}