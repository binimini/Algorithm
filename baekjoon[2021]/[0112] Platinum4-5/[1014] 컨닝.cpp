#include <bits/stdc++.h>
using namespace std;
int C,N,M, dp[10][1025];
bool mapp[10][10] = { 0 };

int check1(int n, int x) {//n행의 x상태가 가능한지(부서진 칸 사용하지 않고, 학생끼리 안 겹치는지)
    int pre = -1, cnt = 0;
    for (int i = 0; i < M; i++) {
        if (x & (1 << i)) {
            cnt++;
            if (mapp[n][i]) return -1;
            if (pre != -1) {
                if (i - pre <= 1)
                    return -1;
            }
            pre = i;
        }
    }
    return cnt;
}
bool check2(int x, int y) {//i-1번째 줄의 x상태와 i번째의 y상태가 가능한지 여부
    for (int i = 0; i < M; i++) {
        if (x & (1 << i)) {
            if (i!=0&&(y & (1 << (i - 1))))
                return false;
            if (i!=M-1&&(y & (1 << (i + 1))))
                return false;
        }
    }
    return true;
}

int solution(int i, int x) {//i-1 행 상태 x일때 i~n-1행까지의 최대 학생 수
    //행별로 쪼개서 본다!!!!! dp 접근 방식 문제를 더 작은 문제로 나누는 것 명심하자
    if (i == N)
        return 0;
    if (dp[i][x] != -1)
        return dp[i][x];
    int& r = dp[i][x];
    r = 0;
    for (int y = 0; y < (1<<M); y++) {
        int thisrow = check1(i, y);
        if (thisrow == -1) continue;
        if (check2(x, y))
            r = max(r, solution(i + 1, y) + thisrow);
    }
    return r;
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> C;
    for (int c = 0; c < C; c++) {
        cin >> N >> M;
        char temp;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> temp;
                if (temp == 'x')
                    mapp[i][j] = 1;
                else if (temp == '.')
                    mapp[i][j] = 0;
            }
        }
        memset(dp, -1, sizeof(dp));
        cout << solution(0, 0)<<"\n";
    }
    return 0;
}