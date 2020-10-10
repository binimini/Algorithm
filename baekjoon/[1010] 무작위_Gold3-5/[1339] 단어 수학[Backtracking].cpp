#include <bits/stdc++.h>
using namespace std;
int N, R = 0;
string s[11];
int status = 0, kind = 0, arr[26] = { 0 }, calcu[26] = { 0 };
bool visited[10] = { 0 };
void dfs(int x, int cnt) {
    if (cnt == kind) {
        int result = 0;
        for (int i = 0; i < 26; i++) {
            result += calcu[i] * (9 - arr[i]);
        }
        R = max(R, result);
        return;
    }
    while (!(status & (1 << x))) {
        x++;
    }
    for (int i = 0; i < kind; i++) {
        if (visited[i]) continue;
        arr[x] = i;
        visited[i] = 1;
        dfs(x + 1, cnt + 1);
        visited[i] = 0;
    }
}
int main() {//백트래킹 풀이 문자열 읽는데 s[i][j] 일일히 읽지 말것 -> 전처리 //다항식 취급해 그리디 풀이도 가능
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> s[i];
        for (int j = 0; j < s[i].size(); j++) {
            calcu[s[i][j] - 'A'] += (int)pow(10, s[i].size() - 1 - j);
            if (status & (1 << (s[i][j] - 'A'))) continue;
            else {
                kind++;
                status |= (1 << (s[i][j] - 'A'));
            }
        }
    }
    dfs(0, 0);
    cout << R;
    return 0;
}