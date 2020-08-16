#include <bits/stdc++.h>
using namespace std;
int R, G, B;
int arr_r[201], arr_g[201], arr_b[201];
int dp[201][201][201] = { 0 };
int D(int r, int g, int b) {
    int& v = dp[r][g][b];
    if (r > R || g > G || b > B) 
        return 0;
    if (v != -1)
        return v;
    return v = max(max(D(r + 1, g + 1, b)+arr_r[r]*arr_g[g], D(r + 1, g, b + 1)+arr_r[r]*arr_b[b]), D(r, g + 1, b + 1)+arr_g[g]*arr_b[b]);
}
int main() {
    cin >> R >> G >> B;
    for (int i = 0; i < R; i++) {
        cin >> arr_r[i];
    }
    for (int i = 0; i < G; i++) {
        cin >> arr_g[i];
    }
    for (int i = 0; i < B; i++) {
        cin >> arr_b[i];
    }
    sort(arr_r, arr_r + R, greater<int>());
    sort(arr_g, arr_g + G, greater<int>());
    sort(arr_b, arr_b + B, greater<int>());
    memset(dp, -1, sizeof(dp));
    cout <<D(0,0,0);
    return 0;
}