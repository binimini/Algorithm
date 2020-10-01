#include <bits/stdc++.h>
using namespace std;
int mod = 1000000007;
int N, K;
//4000000의 nCk 4000000을 반복해서 곱하므로 longlongint 범위 벗어날 수 있음
//나누기, 나머지에 대한 모듈러 연산 불가능 -> (n-k)!k! 나누기 연산 불가
// -> (n-k)!k!의 역원을 구해 곱한다. (곱에 대한 모듈러 연산 가능)

//페르마의 소정리 a^p =(합동) a (mod p) a^(p-1) =(합동) 1 (mod p)
// -> a*a^(p-2) =(합동) 1 (mod p) -> a의 역원 a^(p-2) a에 (n-k)!k! 대입

//1000000005 제곱 O(N)시 시간 초과 -> 분할 정복을 통한 제곱 -> O(logN)

long long int divided_pow(int a, int n) {
    if (n == 0)
        return 1;
    long long int b;
    if (n % 2 == 0) {
        b = divided_pow(a, n / 2);
        b = (b * b) % mod;
        return b;
    }
    else if (n % 2 != 0) {
        b = divided_pow(a, (n - 1) / 2);
        b = (b * b) % mod;
        b = (b * a) % mod;
        return b;
    }
}
int main() {
    long long int result = 1;
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        result = (result * i) % mod;
    }
    
    long long int forinverse = 1;
    for (int i = 1; i <= N - K; i++) {
        forinverse = (forinverse * i) % mod;
    }
    for (int i = 1; i <= K; i++) {
        forinverse = (forinverse * i) % mod;
    }
    long long int inverse;
    inverse = divided_pow(forinverse, mod - 2);
    
    cout << (result * inverse) % mod;
    return 0;
}