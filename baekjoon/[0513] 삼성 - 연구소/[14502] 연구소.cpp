#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int N, M, cnt = 0, max_cnt = 0, d[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int visited_0[8][8] = { 0 }, visited_2[8][8] = { 0 }, map[8][8] = { 0 };
queue<pair<int, int>> q;
vector<pair<int, int>> start_v;
vector<vector<pair<int, int>>> check_list;
pair<int, int> arr[3];
void DFS(int cnt) {
    if (cnt == 3) {
        vector<pair<int, int>> temp;
        for (int i = 0; i < 3; i++) {
            temp.push_back(arr[i]);
        }
        check_list.push_back(temp);
        return;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j]) continue;
            if (!visited_0[i][j]) continue;
            visited_0[i][j] = 0;
            arr[cnt] = make_pair(i, j);
            DFS(cnt + 1);
            visited_0[i][j] = 1;

        }
    }
}
int BFS() {
    int count = cnt;
    while (!q.empty()) {
        if (count < max_cnt) {
            while (!q.empty())
                q.pop();
            break;
        }
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i][0], ny = y + d[i][1];
            if (nx<0 || ny<0 || nx>N - 1 || ny>M - 1) continue;
            if (visited_2[nx][ny]) continue;
            if (!map[nx][ny]) {
                q.push(make_pair(nx, ny));
                visited_2[nx][ny] = 1;
                count--;
            }
        }
    }
    return count;
}
int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (!map[i][j]) {
                cnt++;
                visited_0[i][j] = 1;
            }
            if (map[i][j] == 2)
                start_v.push_back(make_pair(i, j));
        }
    }
    DFS(0);
    for (int i = 0; i < check_list.size(); i++) {
        int c;
        map[check_list[i][0].first][check_list[i][0].second] = 1;
        map[check_list[i][1].first][check_list[i][1].second] = 1;
        map[check_list[i][2].first][check_list[i][2].second] = 1;
        for (int x = 0; x < N; x++) {
            for (int y = 0; y < M; y++) {
                visited_2[x][y] = 0;
            }
        }
        for (int x = 0; x < start_v.size(); x++) {
            visited_2[start_v[x].first][start_v[x].second] = 1;
            q.push(make_pair(start_v[x].first, start_v[x].second));
        }
        c = BFS();
        max_cnt = max(c, max_cnt);
        map[check_list[i][0].first][check_list[i][0].second] = 0;
        map[check_list[i][1].first][check_list[i][1].second] = 0;
        map[check_list[i][2].first][check_list[i][2].second] = 0;
    }
    cout << max_cnt - 3 << "\n";

    return 0;
}