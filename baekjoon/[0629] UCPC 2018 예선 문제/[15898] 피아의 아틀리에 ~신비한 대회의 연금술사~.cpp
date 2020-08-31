#include <iostream>
#include <algorithm>
using namespace std;
int N, max_sum = 0, arr[3] = { 0 }, visited[10] = { 0 }, rot_loc[6] = { 0 };
pair<int, char> ingre[10][4][4], bomb[5][5], copy_bomb[5][5];
int calculate() {
    for (int x = 0; x < 3; x++) {
        int dx = 0, dy = 0;
        if (rot_loc[x * 2 + 1] == 1) dy = 1;
        else if (rot_loc[x * 2 + 1] == 2) dx = 1;
        else if (rot_loc[x * 2 + 1] == 3) dx = 1, dy = 1;
        if (rot_loc[x * 2] == 1) {
            for (int j = 0; j < 4; j++) {
                for (int i = 3; i >= 0; i--) {
                    bomb[dx + j][dy + 3 - i].first += ingre[arr[x]][i][j].first;
                    if (ingre[arr[x]][i][j].second != 'W')
                        bomb[dx + j][dy + 3 - i].second = ingre[arr[x]][i][j].second;
                }
            }
        }
        else if (rot_loc[x * 2] == 2) {
            for (int i = 3; i >= 0; i--) {
                for (int j = 3; j >= 0; j--) {
                    bomb[dx + 3 - i][dy + 3 - j].first += ingre[arr[x]][i][j].first;
                    if (ingre[arr[x]][i][j].second != 'W')
                        bomb[dx + 3 - i][dy + 3 - j].second = ingre[arr[x]][i][j].second;
                }
            }
        }
        else if (rot_loc[x * 2] == 3) {
            for (int j = 3; j >= 0; j--) {
                for (int i = 0; i < 4; i++) {
                    bomb[dx + 3 - j][dy + i].first += ingre[arr[x]][i][j].first;
                    if (ingre[arr[x]][i][j].second != 'W')
                        bomb[dx + 3 - j][dy + i].second = ingre[arr[x]][i][j].second;
                }
            }
        }
        else {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    bomb[dx + i][dy + j].first += ingre[arr[x]][i][j].first;
                    if (ingre[arr[x]][i][j].second != 'W')
                        bomb[dx + i][dy + j].second = ingre[arr[x]][i][j].second;
                }
            }
        }
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (bomb[i][j].first > 9) bomb[i][j].first = 9;
                if (bomb[i][j].first < 0) bomb[i][j].first = 0;
            }
        }
    }
    int sum_R = 0, sum_G = 0, sum_B = 0, sum_Y = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (bomb[i][j].second == 'R') sum_R += bomb[i][j].first;
            else if (bomb[i][j].second == 'G') sum_G += bomb[i][j].first;
            else if (bomb[i][j].second == 'B') sum_B += bomb[i][j].first;
            else if (bomb[i][j].second == 'Y') sum_Y += bomb[i][j].first;
        }
    }
    return 7 * sum_R + 5 * sum_B + 3 * sum_G + 2 * sum_Y;
}
void copy_b() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            bomb[i][j].first = copy_bomb[i][j].first;
            bomb[i][j].second = copy_bomb[i][j].second;
        }
    }
}
void r_l_DFS(int cnt) {
    if (cnt == 6) {
        copy_b();
        max_sum = max(max_sum, calculate());
        return;
    }
    for (int i = 0; i < 4; i++) {
        rot_loc[cnt] = i;
        r_l_DFS(cnt + 1);
    }
}
void DFS(int cnt) {
    if (cnt == 3) {
        r_l_DFS(0);
        return;
    }
    for (int i = 0; i < N; i++) {
        if (visited[i]) continue;
        arr[cnt] = i;
        visited[i] = 1;
        DFS(cnt + 1);
        visited[i] = 0;
    }
}
int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                cin >> ingre[i][j][k].first;
            }
        }
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                cin >> ingre[i][j][k].second;
            }
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            copy_bomb[i][j].first = 0;
            copy_bomb[i][j].second = 'W';
        }
    }
    DFS(0);
    cout << max_sum;
    return 0;
}