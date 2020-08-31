#include <iostream>
using namespace std;
int N, CNT1 = 0, CNT2 = 1, R = -1;
int s1[100001], s2[100001], s3[100001];
int main() {
    cin.tie(NULL);
    cin >> N;
    char temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        s1[i] = temp - '0';
        s2[i] = s1[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> temp;
        s3[i] = temp - '0';
    }
    bool prev = 0;
    for (int i = 0; i < N; i++) {
        if (prev == 1) {
            CNT1++;
            prev = 0;
            s1[i - 1] = 1 - s1[i - 1];
            s1[i] = 1 - s1[i];
            if (i < N) {
                s1[i + 1] = 1 - s1[i + 1];
            }
        }
        if (s1[i] != s3[i]) {
            prev = 1;
        }
    }
    bool CH = 1;
    for (int i = 0; i < N; i++) {
        if (s1[i] != s3[i]) {
            CH = 0;
            break;
        }
    }
    if (CH) R = CNT1;
    s2[0] = 1 - s2[0];
    s2[1] = 1 - s2[1];
    prev = 0;
    for (int i = 0; i < N; i++) {
        if (prev == 1) {
            CNT2++;
            prev = 0;
            s2[i - 1] = 1 - s2[i - 1];
            s2[i] = 1 - s2[i];
            if (i < N) {
                s2[i + 1] = 1 - s2[i + 1];
            }
        }
        if (s2[i] != s3[i]) {
            prev = 1;
        }
    }
    CH = 1;
    for (int i = 0; i < N; i++) {
        if (s2[i] != s3[i]) {
            CH = 0;
            break;
        }
    }
    if (CH) {
        if (R == -1 || CNT2 < R)
            R = CNT2;
    }
    cout << R;
    return 0;
}