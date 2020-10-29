#include <bits/stdc++.h>
using namespace std;
int N, K, result = 0;
int arr[50] = { 0 };
void dfs(int cnt, int status, int j) {
    if (cnt == K-5) {
        int temp = 0;
        for (int i = 0; i < N; i++) {
            if ((status | arr[i]) == status)
                temp++;
        }
        result = max(result, temp);
        return;
    }
    for (int i = j; i <= 25; i++) {
        if (status & (1 << i)) continue;
        status |= 1 << i;
        dfs(cnt + 1, status, i+1);
        status &= ~(1 << i);
    }
}
int main() {
    cin >> N >> K;
    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            arr[i] |= 1 << (s[j] - 'a');
        }
    }

    if (K < 5)
        cout << 0;
    else {
        int temp = 0;
        temp |= 1 << ('a' - 'a');
        temp |= 1 << ('n' - 'a');
        temp |= 1 << ('t' - 'a');
        temp |= 1 << ('i' - 'a');
        temp |= 1 << ('c' - 'a');
        dfs(0, temp, 0);
        cout << result;
    }
    return 0;
}