#include <iostream>
#include <algorithm>
using namespace std;
int N, result[50][9], arr[9], visited[9] = { 0 }, hitter_info[3] = { 0 }, out = 0, inning = 0, score = 0, M_score = 0;
int game() {
    int i = 0;
    inning = 0, out = 0, score = 0;
    hitter_info[0] = 0, hitter_info[1] = 0, hitter_info[2] = 0;
    while (inning <= N - 1) {
        if (i == 9) i = 0;
        int temp = result[inning][arr[i]];
        if (temp == 0) out++;
        else {
            for (int j = 2; j >= 0; j--) {
                if (hitter_info[j]) {
                    if (j >= 3 - temp) {
                        score++;
                        hitter_info[j] = 0;
                    }
                    else hitter_info[j] = 0, hitter_info[j + temp] = 1;
                }
            }
            if (temp == 4) score++;
            else hitter_info[temp - 1] = 1;
        }
        if (out == 3) {
            inning++;
            hitter_info[0] = 0;
            hitter_info[1] = 0;
            hitter_info[2] = 0;
            out = 0;
        }
        i++;
    }
    return score;
}
void DFS(int cnt) {
    if (cnt == 3) cnt++;

    if (cnt == 9) {
        arr[3] = 0;
        M_score = max(M_score, game());
        return;
    }
    for (int i = 1; i < 9; i++) {
        if (visited[i]) continue;
        arr[cnt] = i;
        visited[i] = 1;
        DFS(cnt + 1);
        visited[i] = 0;
    }
}
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> result[i][j];
        }
    }
    DFS(0);
    cout << M_score;
}