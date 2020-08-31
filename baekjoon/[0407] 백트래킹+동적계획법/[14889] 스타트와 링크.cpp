#include <iostream>
#include <algorithm>
using namespace std;
//start <-> link member 동일할 경우 제거할 방법
int N, result, m = 1901, check;
int start[11], link[11], synergy[21][21], start_link[21];
bool prob(int x, int cnt) {
    check = 0;
    for (int i = 1; i <= cnt; i++) {
        if (start_link[i] == x)
            check++;
    }
    if (check > N / 2)
        return false;
    return true;
}
void DFS(int cnt) {
    if (cnt == N) {
        result = 0;
        int check1 = 1, check2 = 1;
        for (int i = 1; i <= N; i++) {
            if (start_link[i] == 1) {
                start[check1] = i;
                check1++;
            }
            else {
                link[check2] = i;
                check2++;
            }
        }
        for (int i = 1; i <= N / 2; i++) {
            for (int j = i + 1; j <= N / 2; j++) {
                result += synergy[start[i]][start[j]] + synergy[start[j]][start[i]] - synergy[link[i]][link[j]] - synergy[link[j]][link[i]];
            }
        }
        m = min(abs(result), m);
        return;
    }
    for (int i = 1; i <= 2; i++) {
        start_link[cnt + 1] = i;
        if (prob(i, cnt + 1))
            DFS(cnt + 1);
    }
}
int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> synergy[i][j];
        }
    }
    DFS(0);
    cout << m << '\n';
}