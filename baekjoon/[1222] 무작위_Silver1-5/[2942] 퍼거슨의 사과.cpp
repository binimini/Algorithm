#include <bits/stdc++.h>
using namespace std;
int R, G;
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> R >> G;
    int a = max(R, G);
    int b = min(R, G);
    while (b) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    for (int i = 1; i <= (int)sqrt(a); i++) {//최대 루트(n)*루트(n)
        if (a % i == 0) {
            cout << i << " " << R / i << " " << G / i << "\n";
            if (a / i != i)
                cout << a / i << " " << R / (a / i) << " " << G / (a / i) << "\n";
        }
    }
}