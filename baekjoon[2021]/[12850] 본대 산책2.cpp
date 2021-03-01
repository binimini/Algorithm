#include <bits/stdc++.h>
using namespace std;
int D, MOD = 1000000007;
struct matrix {//행렬(8*8)
    matrix() {//기본적으로 0으로 초기화
        memset(m, 0, sizeof(m));
    }
    long long int m[8][8];
};
matrix operator*(matrix& a, matrix& b) {//행렬곱
    matrix result;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 8; k++) {
                result.m[i][j] += a.m[i][k] * b.m[k][j];
            }
            result.m[i][j] = result.m[i][j] % MOD;
        }
    }
    return result;
}
matrix pow(matrix n, int k) {//제곱
    if (k == 1)//자기자신반환
        return n;
    matrix m;
    if (k == 0) {//1 행렬반환
        memset(m.m, 1, sizeof(m.m));
        return m;
    }
    if (k % 2 == 0) {//짝수
        m = pow(n, k / 2);
        return m * m;
    }
    else if (k % 2 != 0) {//홀수
        m = pow(n, (k-1) / 2);//(k-1)/2 제곱임에 주의!!
        m = m * m;
        return m * n;//자기자신 한 번 더 곱하기
    }
}
int main() {
    cin >> D;
    matrix base;
    base.m[0][1] = 1, base.m[1][0] = 1, base.m[0][2] = 1, base.m[2][0] = 1;//기본적 경로 초기화(갈 수 있는)
    base.m[1][2] = 1, base.m[2][1] = 1, base.m[1][3] = 1, base.m[3][1] = 1;
    base.m[2][3] = 1, base.m[3][2] = 1, base.m[2][4] = 1, base.m[4][2] = 1;
    base.m[3][4] = 1, base.m[4][3] = 1, base.m[5][3] = 1, base.m[3][5] = 1;
    base.m[5][4] = 1, base.m[4][5] = 1, base.m[5][6] = 1, base.m[6][5] = 1;
    base.m[7][4] = 1, base.m[4][7] = 1, base.m[7][6] = 1, base.m[6][7] = 1;
    base = pow(base,D);
    cout << base.m[0][0];//최종적으로 돌아올 수 있는 경로만 취급
    return 0;
}