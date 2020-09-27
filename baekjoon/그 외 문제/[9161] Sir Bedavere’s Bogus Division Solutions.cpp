#include <bits/stdc++.h>
using namespace std;
int main() {
    int ni, ci, nj, cj;
    for (int i = 100; i <= 999; i++) {
        for (int j = 100; j <= 999; j++) {
            if (i == j)
                continue;
            ni = i / 10;
            ci = i % 10;
            nj = j % 100;
            cj = j / 100;
            if (ci==cj&&double(i) / j == double(ni) / nj) {
                cout << i << " / " << j << " = " << ni << " / " << nj << "\n";
            }
        }
    }
    return 0;
}