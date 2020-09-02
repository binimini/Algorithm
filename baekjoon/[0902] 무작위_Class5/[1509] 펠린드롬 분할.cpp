#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define FOR(i,a,b); for (int i = a; i<b; i++)
string S;
int dp[2500], INF = 987654321;
bool ispail[2500][2500] = { 0 };
int main() {
    cin >> S;
    FOR(i, 0, S.size()) {
        FOR(j, 0, i+1) {//j부터 i까지 페일드롬인지 여부
            if (i == j) {
                ispail[i][j] = 1;
                continue;
            }
            if (S[i] == S[j]) {
                if (j + 1 == i)
                    ispail[i][j] = 1;
                else 
                    ispail[i][j] = ispail[i - 1][j + 1];//j+1 - i-1까지는 j i(i>=j) 이미 i = j-1일때값 정함
            }
        }
    }
    
    FOR(i, 0, S.size()) {
        dp[i] = 987654321;
        FOR(j, 0, i+1) {
            if (ispail[i][j]) {//최소 자기자신은 페일드롬 //i 당 한 경우는 존재
                if (j == 0)
                    dp[i] = min(dp[i], 1);//0 - i 경우
                else dp[i] = min(dp[j - 1] + 1, dp[i]);//dp[i] = dp[j-1] + 1(j - i) or dp[i]
            }
        }
    }
    cout << dp[S.size() - 1];
    return 0;
}