#include <iostream>
#include <algorithm>
using namespace std;
int N, dp_m[2][3], dp_M[2][3], arr[100000][3];
int main() {//내려가기
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    dp_m[0][0] = arr[0][0], dp_M[0][0] = arr[0][0];
    dp_m[0][1] = arr[0][1], dp_M[0][1] = arr[0][1];
    dp_m[0][2] = arr[0][2], dp_M[0][2] = arr[0][2];
    for (int i = 1; i < N; i++) {
        int x = i % 2;
        dp_m[x][0] = min(dp_m[1-x][0], dp_m[1-x][1]) + arr[i][0];
        dp_m[x][1] = min(dp_m[1-x][2],min(dp_m[1-x][0], dp_m[1-x][1])) + arr[i][1];
        dp_m[x][2] = min(dp_m[1 - x][1], dp_m[1 - x][2]) + arr[i][2];
    }
    for (int i = 1; i < N; i++) {
        int x = i % 2;
        dp_M[x][0] = max(dp_M[1-x][0], dp_M[1-x][1]) + arr[i][0];
        dp_M[x][1] = max(dp_M[1-x][2], max(dp_M[1-x][0], dp_M[1-x][1])) + arr[i][1];
        dp_M[x][2] = max(dp_M[1-x][1], dp_M[1-x][2]) + arr[i][2];
    }
    int x = (N - 1) % 2;
    cout << max(dp_M[x][2], max(dp_M[x][0], dp_M[x][1]))<<" " <<min(dp_m[x][2], min(dp_m[x][0], dp_m[x][1]));
    return 0;
}