#include <bits/stdc++.h>
using namespace std;
int T,N;
int main() {//틀린 코드
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        int arr[50] = { 0 };
        int k[101] = { 0 };
        bool visited[50] = { 0 };
        for (int j = 0; j < N; j++) {
            cin >> arr[j];
        }
        for (int x = 0; x < N; x++) {
            for (int y = x + 1; y < N; y++) {// 동시에 사용할 수 없는 경우도 세어지므로 비논리적
                k[arr[x] + arr[y]]++;
            }
        }
        int s_value = 0, s = -1;
        for (int j = 0; j < 101; j++) {
            if (k[j] > s)
                s = k[j], s_value =  j;
        }
        int result = 0;
        for (int x = 0; x < N; x++) {
            if (visited[x]) continue;
            for (int y = x+1; y < N; y++) {
                if (visited[y]) continue;
                if (arr[x] + arr[y] == s_value) {
                    visited[x] = 1, visited[y] = 1, result++;
                    break;
                }
            }
        }
        cout << result << "\n";
    }
    return 0;
}