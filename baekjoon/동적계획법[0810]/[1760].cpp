#include <iostream>
using namespace std;
int N, dp[31] = { 0 };
int case_(int n) {
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;
    if (dp[n] != 0) 
        return dp[n];
    return dp[n] = case_(n - 2)*2 + case_(n - 1);
}
int main() {//타일 코드
    cin >> N;
    int symm;
    if (N % 2 != 0)
        symm = case_((N - 1) / 2);
    else symm = case_(N / 2) + 2*case_(N/2-1);
    cout << (case_(N) - symm) / 2 + symm << '\n';
    //결과 = (전체 케이스 - symm한 케이스) / 2 + symm한 케이스
    return 0;
}