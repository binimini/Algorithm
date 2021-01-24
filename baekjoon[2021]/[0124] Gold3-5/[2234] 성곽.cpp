#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int N, M, d[4][2] = { {0,-1},{-1,0},{0,1},{1,0} }, visited[50][50] = { 0 };
short int mapp[50][50];
bool v[50][50] = { 0 };
int area = 0, area_break = 0;//result

queue<pair<int, int>> q;
vector<int> room;
int bfs(int x, int y, bool check) {//check is after grouping, breaks wall
    int cnt = 1;
    q.push(make_pair(x, y));
    if (check)
        v[x][y] = 1;
    else
        visited[x][y] = room.size()+1;
    
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + d[i][0];
            int ny = y + d[i][1];

            if (nx<0 || ny<0 || nx>N - 1 || ny>M - 1) continue;
            if ((mapp[x][y] & (1 << i))) {//can't go in that direction
                if (check&&(visited[nx][ny]!=visited[x][y])) 
                    area_break = max(area_break, room[visited[nx][ny] - 1] + room[visited[x][y] - 1]);
                else 
                    continue;
            } 
            if (check && v[nx][ny]) continue;
            if (!check&& visited[nx][ny]) continue;
            

            if (check) 
                v[nx][ny] = 1;
            else 
                visited[nx][ny] = room.size() + 1;
            cnt++;
            q.push(make_pair(nx, ny));
        }
    }
    return cnt;//returns visited room area
}

int main() {
    FASTIO;
    cin >> M>> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> mapp[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {//room grouping
            if (!visited[i][j]) {
                room.push_back(bfs(i, j, 0));
                area = max(area, room.back());
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {//checking maximum room area if wall breaks
            if (!v[i][j])//v[][] : visited arr after grouping
                bfs(i, j, 1);
        }
    }
    cout << room.size() << "\n" << area << "\n" << area_break << "\n";
    return 0;
}