#include <iostream>
#include <cstring>
using namespace std;
int T, N, dp[500][13];
int find_case(int n, int state) {
    if (n < 0) return 0;//n-2에서 음수가 나오는 경우 = n줄 넘은 경우 불가 +0
    if (n == 0) {//상태 거쳐 n항일 때
        if (state == 0) return 1;//다 채워진 경우 +1
        else return 0;
    }
    int& c = dp[n][state];
    if (c != -1)
        return c;
    c = 0;//후 각각 경우 값 더하기 
    if (state == 0) {
        c += find_case(n - 1, 0);
        c += find_case(n - 1, 3);
        c += find_case(n - 1, 9);
        c += find_case(n - 1, 12);
        c += find_case(n - 2, 0);//다음 줄까지 다 채워진 경우 그 다음 줄로
    }
    else if (state == 3) {
        c += find_case(n - 1, 0);
        c += find_case(n - 1, 12);

    }
    else if (state == 6) {
        c += find_case(n - 1, 9);

    }
    else if (state == 9) {//그 줄 x..x인 것만 고려 / 블록과 상태 별도
        c += find_case(n - 1, 0);
        c += find_case(n - 1, 6);
    }
    else if (state == 12) {
        c += find_case(n - 1, 0);
        c += find_case(n - 1, 3);
    }
    return c;
}
int main() {
    cin >> T;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < T; i++) {
        cin >> N;
        cout << find_case(N, 0) << '\n';
    }
    return 0;
}