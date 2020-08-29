#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
string A,B;
int dp[1000][1000];
vector<int> v[26];
vector<int> r;
int find_dp(int x, int y) {//위치가 A에서 x, B에서 y일때 최대부분문자열의 길이
    if (x >= A.size() || y >= B.size())
        return 0;//범위 넘으면 0 // 저장되기 시작
    if (dp[x][y] != -1)
        return dp[x][y];
    if (A[x] == B[y])
        return dp[x][y] = max(find_dp(x + 1,y + 1) + 1, max(find_dp(x,y + 1), find_dp(x + 1,y)));
    else return dp[x][y] = max(find_dp(x + 1,y),find_dp(x,y + 1));

}
void find_string(int x,int y) {
    if (x >= A.size() || y >= B.size())
        return;
    if (A[x] == B[y]) {//같을 떄 LCS에 포함
        cout << A[x];
        find_string(x + 1, y + 1);
    }
    else {
        if (dp[x][y] == dp[x + 1][y])//문자 사용하지 않은 쪽으로 타고 넘어가기
            find_string(x + 1, y);
        else if (dp[x][y] == dp[x][y + 1])
            find_string(x, y + 1);
    }
}
int main() {//LCS 2
    memset(dp, -1, sizeof(dp));
    cin >> A >> B;
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < B.size(); j++) {
            find_dp(i, j);
        }
    }
    cout << dp[0][0] << '\n';//0,0이 모든 문자 포함하므로 가장 큰 수 나오게 되어있다
    if (dp[0][0]!=0)
        find_string(0,0);
    return 0;
}