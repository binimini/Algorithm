#include <bits/stdc++.h>
using namespace std;
int N, M;
int a[200], b[200];
int main() {//수정코드
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> b[i];
    }
    bool CH = 0;
    for (int x = 0; x <= 512; x++) {
        for (int i = 0; i < N; i++) {
            CH = 0;
            for (int j = 0; j < M; j++) {
                if ((x | (a[i] & b[j])) == x) {
                    CH = 1;
                    break;
                }
            }
            if (!CH)
                break;
        }
        if (CH) {
            cout << x;
            break;
        }
    }
    return 0;
}