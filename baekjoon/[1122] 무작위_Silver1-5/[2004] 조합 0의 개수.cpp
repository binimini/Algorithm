#include <bits/stdc++.h>
using namespace std;
long long int N, M;
long long int divide(long long int x, long long int n) {
    int cnt = 1;
    long long int result = 0;
    while (x >= (long long int)pow(n,cnt)) {
        result += (x / (long long int)pow(n,cnt));
        cnt++;
    }
    return result;
}
int main() {
    cin >> N >> M;
    cout <<min(divide(N, 5)-divide(M, 5) - divide(N-M,5),divide(N, 2)-divide(M, 2)-divide(N-M,2));
    return 0;
}