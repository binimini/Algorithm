#include <bits/stdc++.h>
using namespace std;
string S;
bool flag = 0;
int s[10][10];
int arr[10], temp_sum[10][10] = { 0 };
int N;
bool check(int idx, int num) {
    for (int i = 0; i <idx; i++) {
        if (temp_sum[i][idx - 1] + num < 0 && s[i][idx] != -1)
            return false;
        else if (temp_sum[i][idx - 1] + num > 0 && s[i][idx] != 1)
            return false;
        else if (temp_sum[i][idx - 1] + num == 0 && s[i][idx] != 0)
            return false;
    }
    return true;
}
void dfs(int cnt) {
    if (cnt == N) {
        for (int i = 0; i < N; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        flag = 1;
        return;
    }
    if (s[cnt][cnt] == 0) {
        arr[cnt] = 0;
        dfs(cnt + 1);
        if (flag) return;
    }
    else if (s[cnt][cnt] == 1 ) {
        for (int i = 1; i <= 10; i++) {
            if (!check(cnt, i)) continue;
            for (int j = 0; j <=cnt; j++) {
                temp_sum[j][cnt] = temp_sum[j][cnt-1]+i;
            }
            arr[cnt] = i;
            dfs(cnt + 1);
            if (flag) return;
        }
    }
    else if (s[cnt][cnt] == -1) {
        for (int i = -1; i >= -10; i--) {
            if (!check(cnt, i)) continue;
            for (int j = 0; j <=cnt; j++) {
                temp_sum[j][cnt] = temp_sum[j][cnt-1]+i;
            }
            arr[cnt] = i;
            dfs(cnt + 1);
            if (flag) return;
        }
    }
    
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> S;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i; j <N; j++) {
            if (S[cnt]=='+')
                s[i][j] = 1;
            else if (S[cnt]=='-')
                s[i][j] = -1;
            else
                s[i][j] = 0;
            cnt++;
        }
    }
    dfs(0);
    return 0;
}