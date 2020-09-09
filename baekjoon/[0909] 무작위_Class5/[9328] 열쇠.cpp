#include <iostream>
#include <queue>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,a,b) for (int i = a; i<b; i++)
int T, H, W, cnt = 0, status = 0;
int d[4][2] = { {0,-1},{-1,0},{0,1},{1,0} };
string S;
char map[101][101];
bool visited[100][100] = { 0 };
queue <pair<int, int>> q;
vector<pair<int,int>> prob[26];
void BFS() {
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i][0];
            int ny = y + d[i][1];
            
            if (nx<0 || nx>H - 1 || ny<0 || ny>W - 1) continue;
            if (map[nx][ny] == '*') continue;
            if (visited[nx][ny]) continue;
            visited[nx][ny] = 1;
            
            if (map[nx][ny] >= 'A' && map[nx][ny] <= 'Z') {//문
                if (!(status & 1<<(map[nx][ny] - 'A'))) {//문
                    prob[map[nx][ny] - 'A'].push_back(make_pair(nx, ny));
                    continue;
                }
            }
            else if (map[nx][ny] == '$') {//문서
                cnt++;
                map[nx][ny] = '.';
            }
            else if (map[nx][ny] >= 'a' && map[nx][ny] <= 'z') {//열쇠
                if (!(status & 1<<(map[nx][ny] - 'a'))) {
                    status |= 1 << (map[nx][ny] - 'a');
                    while (!prob[map[nx][ny] - 'a'].empty()) {
                        q.push(prob[map[nx][ny] - 'a'].back());
                        prob[map[nx][ny] - 'a'].pop_back();
                    }
                }
            }
            
            q.push(make_pair(nx, ny));
        }
    }
}
int main() {
    FASTIO;
    cin >> T;
    FOR(t, 0, T) {
        FOR(i, 0, 100) {
            FOR(j, 0, 100)
                visited[i][j] = 0;
        }
        FOR(i, 0, 26) {
            prob[i].clear();
        }
        status = 0;
        cnt = 0;
        cin >> H >> W;
        FOR(i, 0, H) {
            FOR(j, 0, W) {
                cin >> map[i][j];
                if (map[i][j] == '.' && (i == 0 || i == H - 1 || j == 0 || j == W - 1))//기본
                    q.push(make_pair(i, j));
                else if ((i == 0 || i == H - 1 || j == 0 || j == W - 1) && map[i][j] <= 'Z' && map[i][j] >= 'A') {//문
                    prob[map[i][j] - 'A'].push_back(make_pair(i, j));
                }
                else if ((i == 0 || i == H - 1 || j == 0 || j == W - 1) && map[i][j] == '$') {//문서
                    cnt++;
                    map[i][j] = '.';
                    q.push(make_pair(i, j));
                }
                else if ((i == 0 || i == H - 1 || j == 0 || j == W - 1) && map[i][j] >= 'a' && map[i][j] <= 'z') {//열쇠
                    status |= 1 << (map[i][j] - 'a');
                    map[i][j] = '.';
                    q.push(make_pair(i, j));
                }
            }
        }
        cin >> S;
        if (S != "0") {
            FOR(s, 0, S.size()) {
                status |= 1 << (S[s] - 'a');
            }
        }
        FOR(i, 0, 27) {
            if (status & 1 << i) {
                while (!prob[i].empty()) {
                    q.push(prob[i].back());
                    prob[i].pop_back();
                }
            }
        }
        BFS();
        cout << cnt << '\n';
    }
    return 0;
}