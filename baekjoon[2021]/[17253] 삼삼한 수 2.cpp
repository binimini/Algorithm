#include <bits/stdc++.h>
using namespace std;
long long int N, arr[40];
bool flag = 0;
int main() {
    cin >> N;
    int cnt = 39;
    long long int test = 1;
    for (int i = 0; i < 40; i++) {
        arr[i] = test;
        test *= 3;
    }
    while (cnt >= 0&&N!=0) {
        if (arr[cnt]<= N) {
            N -= arr[cnt];//pow로 연산시 제곱승 너무 커질 경우 오차 발생
            flag = 1;
        }
        cnt--;
    }
    if (N == 0&&flag)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}