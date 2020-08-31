#include <iostream>
using namespace std;
int N, L, map[100][100], R_cnt = 0;
bool row_check(int i) {
    bool visited[100] = { 0 };
    int h = map[i][0], cnt = 1;
    for (int k = 1; k < N; k++) {
        if (h == map[i][k]) { cnt++; continue; }
        else if (h - map[i][k] == 1) {
            if (k + L - 1 <= N - 1) {
                for (int l = k; l <= k + L - 1; l++) {
                    if (map[i][l] != map[i][k]) return false;
                    if (visited[l]) return false;
                    visited[l] = 1;
                }
                h = map[i][k];
                cnt = 1;
            }
            else return false;
        }
        else if (map[i][k] - h == 1) {
            if (cnt < L) return false;
            else {
                for (int l = k - L; l < k; l++) {
                    if (visited[l]) return false;
                    visited[l] = 1;
                }
                cnt = 1;
                h = map[i][k];
            }
        }
        else return false;
    }
    return true;
}
bool col_check(int j) {
    bool visited[100] = { 0 };
    int h = map[0][j], cnt = 1;
    for (int k = 1; k < N; k++) {
        if (h == map[k][j]) { cnt++; continue; }
        else if (h - map[k][j] == 1) {
            if (k + L - 1 <= N - 1) {
                for (int l = k; l <= k + L - 1; l++) {
                    if (map[l][j] != map[k][j]) return false;
                    if (visited[l]) return false;
                    visited[l] = 1;
                }
                h = map[k][j];
                cnt = 1;
            }
            else return false;
        }
        else if (map[k][j] - h == 1) {
            if (cnt < L) return false;
            else {
                for (int l = k - L; l < k; l++) {
                    if (visited[l]) return false;
                    visited[l] = 1;
                }
                cnt = 1;
                h = map[k][j];
            }
        }
        else return false;
    }
    return true;

}
int main() {
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        if (row_check(i))
            R_cnt++;
    }
    for (int i = 0; i < N; i++) {
        if (col_check(i))
            R_cnt++;
    }
    cout << R_cnt << '\n';
    return 0;
}