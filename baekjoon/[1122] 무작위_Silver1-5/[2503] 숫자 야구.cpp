#include <bits/stdc++.h>
using namespace std;
int N, result = 0;
int info[100][3], arr[3];
bool use[10] = { 0 };
bool check() {
    int s, b, num;
    for (int i = 0; i < N; i++) {
        s = 0, b = 0, num = info[i][0];
        for (int k = 0; k < 3; k++) {
            for (int j = 0; j < 3; j++) {
                if ((num % 10) == arr[j]) {
                    if (k == j)
                        s++;
                    else
                        b++;
                }
            }
            num /= 10;
        }
        if (!(s == info[i][1] && b == info[i][2]))
            return false;
    }
    return true;
}
void dfs(int cnt) {
    if (cnt == 3) {
        if (check())
            result++;
        return;
    }
    for (int i = 1; i <= 9; i++) {
        if (use[i]) continue;
        arr[cnt] = i;
        use[i] = 1;
        dfs(cnt + 1);
        use[i] = 0;
    }
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> info[i][0] >> info[i][1] >> info[i][2];
    }
    dfs(0);
    cout << result;
    return 0;
}