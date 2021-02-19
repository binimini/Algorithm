#include <bits/stdc++.h>
using namespace std;
long long int temp, cnt = 0, res = 0;
string X, Y;
int main() {
    cin >> X;
    while (X.size() >= 2) {
        cnt++;
        temp = 0;
        for (int i = 0; i < X.size(); i++) {//자리수가 10^6까지
            temp += X[i] - '0';
        };
        X = to_string(temp);
    }
    res = stoi(X);
    cout << cnt << "\n";
    if (res % 3 == 0)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}