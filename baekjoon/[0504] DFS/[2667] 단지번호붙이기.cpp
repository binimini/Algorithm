#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, map[25][25] = { 0 }, d[4][2] = { {0,1},{1,0},{0,-1},{-1,0} }, visited[25][25] = { 0 }, G_cnt = 0, cnt = 0;
vector<int> G_area;
void DFS(int x, int y) {
    visited[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + d[i][0];
        int ny = y + d[i][1];
        if (nx<0 || nx>N - 1 || ny<0 || ny>N - 1) continue;
        if (map[nx][ny] == 0) continue;
        if (visited[nx][ny] == 1) continue;
        DFS(nx, ny);
        cnt++;
    }
}
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        string temp;
        cin >> temp;
        for (int j = 0; j < N; j++) {
            map[i][j] = temp[j] - '0';
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 0 || visited[i][j] == 1) continue;
            G_cnt++;
            cnt = 1;
            DFS(i, j);
            G_area.push_back(cnt);
        }
    }
    cout << G_cnt << "\n";
    sort(G_area.begin(), G_area.end());
    for (int i = 0; i < G_area.size(); i++) {
        cout << G_area[i] << "\n";
    }
    return 0;
}