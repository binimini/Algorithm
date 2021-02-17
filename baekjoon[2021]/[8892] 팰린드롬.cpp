#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int T, N;
string arr[100], res;
bool flag = 0;
bool check(string str) {
    for (int i = 0; i < str.size() / 2; i++) {
        if (str[i] != str[str.size() - 1 - i])
            return false;
    }
    return true;
}
int main() {
    FASTIO;
    cin >> T;
    for (int t = 0; t < T; t++) {
        flag = 0;
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j) continue;
                res = arr[i] + arr[j];
                if (check(res)) {
                    flag = 1;
                    break;
                }
            }
            if (flag)
                break;
        }
        if (flag)
            cout << res << "\n";
        else
            cout << 0 << "\n";
    }
    return 0;
}