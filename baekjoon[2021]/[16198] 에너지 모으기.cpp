#include <bits/stdc++.h>
using namespace std;
int N, arr[10], res = 0;
bool rem[10] = { 0 };
void dfs(int n, int energy) {
    res = max(res, energy);
    if (n == N - 2)
        return;
    int first_flag = -1, last_flag = -1;
    for (int i = 0; i < N; i++) {
        if (first_flag==-1 && !rem[i]) 
            first_flag = i;

        if (!rem[i])
            last_flag = i;
    }
    int temp1, temp2;

    for (int i = 0; i < N; i++) {
        if (i != first_flag && i != last_flag&& !rem[i]) {
            rem[i] = 1;
            for (int j = i - 1; j >= 0; j--) {
                if (!rem[j]) {
                    temp1 = j;
                    break;
                }
            }
            for (int j = i + 1; j < N; j++) {
                if (!rem[j]) {
                    temp2 = j;
                    break;
                }
            }
            dfs(n+1, energy+arr[temp1]*arr[temp2]);
            rem[i] = 0;
        }
    }
}
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    dfs(0, 0);
    cout << res;
    return 0;
}