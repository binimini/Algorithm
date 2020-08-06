#include <bits/stdc++.h>
using namespace std;
int T, N;
int main() {//통과 코드
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N;
        int visited[51] = { 0 }, copy_visited[51] = { 0 };
        int temp;
        int m = 51, M = 0;
        for (int i = 0; i < N; i++) {
            cin >> temp;
            visited[temp]++;// 배치 가능한 인원 수 처리
            m = min(temp, m);
            M = max(temp, M);
        }
        int result = 0;
        for (int s = m * 2; s <= M * 2; s++) {// s 최소 - 최대
            int cnt = 0;
            for (int j = 1; j <= N; j++) {// s = 1 + s-1, 2 + s-2 , 3 + s-3... s/2 + s - s/2까지 체크 (중복 제외)
                copy_visited[j] = visited[j];
            }
            for (int j = 1; j <= s / 2; j++) {
                if (s - j > 50) continue;// s=100이고 j = 1이면 s-j = 99로 50 넘어가는 예외 처리
                if (j == s - j) {
                    if (copy_visited[j] >= 2) {
                        cnt += copy_visited[j] / 2;
                        copy_visited[j] -= copy_visited[j]/2;
                    }
                }
                else if (copy_visited[j] >= 1 && copy_visited[s - j] >= 1) {
                    int k = min(copy_visited[j], copy_visited[s - j]);
                    copy_visited[j] -= k;
                    copy_visited[s - j] -= k;
                    cnt += k;
                }
            }
            result = max(cnt, result);
        }
        cout << result << "\n";
    }
    return 0;
}