#include <bits/stdc++.h>
using namespace std;
int N;
long long int M;
struct matrix {
    int size;
    matrix(int s) {
        size = s;
        for (int i = 0; i<size; i++){ 
            for (int j = 0; j < size; j++) {
                m[i][j] = 0;
            }
        }
    }
    int m[5][5];
};
matrix operator*(matrix& a, matrix& b) {
    matrix res(a.size);
    for (int i = 0; i < a.size; i++) {
        for (int j = 0; j < a.size; j++) {
            for (int k = 0; k < a.size; k++) {
                res.m[i][j] += a.m[i][k] * b.m[k][j];
            }
            res.m[i][j] = res.m[i][j] % 1000;
        }
    }
    return res;
}
matrix pow(matrix a, long long int n, int size){
    matrix b(size);
    if (n == 1)
        return a;
    if (n == 0) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++)
                b.m[i][j] = 1;
        }
        return b;
    }
    if (n % 2 == 0) {
        b = pow(a, n / 2, size);
        return b * b;
    }
    else if (n % 2 != 0) {
        b = pow(a, (n - 1) / 2, size);
        b = b * b;
        return a * b;
    }
}

int main() {
    cin >> N >> M;//M 범위 long long int로 해야함에 주의!!
    matrix result(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> result.m[i][j];
        }
    }
    result = pow(result, M, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << (result.m[i][j])%1000 << " ";//1번 곱할 경우 모듈러 연산 적용 안될수도 있으므로 최종에서 한 번 더 한다.
        }
        cout << '\n';
    }
    return 0;
}