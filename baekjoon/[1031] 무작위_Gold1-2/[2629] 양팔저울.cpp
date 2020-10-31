#include <bits/stdc++.h>
using namespace std;
int N, M, arr[31];
bool dp[31][16001] = { 0 };
void solution(int n, int value) {
    if (n > N||value>15000||value<0)
        return;
    if (dp[n][value]) 
        return;
    dp[n][value] = 1;
    solution(n + 1, value + arr[n + 1]);
    solution(n + 1, abs(value - arr[n + 1]));
    solution(n + 1, value);
}
int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    solution(0,0);
    cin >> M;
    for (int i = 0; i < M; i++) {
        int temp;
        bool flag = 0;
        cin >> temp;
        if (temp <= 15000) {
            for (int i = 0; i <= N; i++) {
                if (dp[i][temp]) {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag)
            cout << "Y ";
        else 
            cout << "N ";
    }
    return 0;
}