#include <iostream>
#include <tuple>
#include <vector>
using namespace std;
int d[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };//+i -i +j -j
int neig[6][4] = { {3,5,2,4},{2,5,3,4},{0,5,1,4},{1,5,0,4},{3,0,2,1},{3,1,2,0} };//시계 방향 기준 이웃 면 정보
int cube[6][3][3];
int pre[3];
vector<tuple<int, int, int>> info[6];
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,a,b) for(int i =a; i<b; i++)
int T, N;
void swap(int n, int x, int y) {//바꿀 면 두 개 세 자표
    int d1 = get<2>(info[n][x]);
    int d2 = get<2>(info[n][y]);
    int xx = get<0>(info[n][x]);
    int yx = get<0>(info[n][y]);
    int xy = get<1>(info[n][x]);
    int yy = get<1>(info[n][y]);
    int temp;
    FOR(i,0,3) {
        if (pre[i] == -1) {
            pre[i] = cube[neig[n][y]][yx][yy];
            cube[neig[n][y]][yx][yy] = cube[neig[n][x]][xx][xy];
        }
        else {
            temp = cube[neig[n][y]][yx][yy];
            cube[neig[n][y]][yx][yy] = pre[i];
            pre[i] = temp;
        }
        xx += d[d1][0];
        xy += d[d1][1];
        yx += d[d2][0];
        yy += d[d2][1];
    }
}
void rotate(int side, bool dir) {
    int rt[3][3];
    FOR(i,0,3) {
        FOR(j,0,3) {
            rt[i][j] = cube[side][i][j];
        }
    }
    if (dir) {
        FOR(i,0,3) {
            FOR(j,0,3){
                cube[side][i][j] = rt[2 - j][i];
            }
        }
        swap(side, 3, 0);
        FOR(i,0,3) {
            swap(side, i, (i + 1) % 4);
        }
    }
    else {
        FOR(i,0,3) {
            FOR(j,0,3) {
                cube[side][i][j] = rt[j][2 - i];
            }
        }
        for (int i = 3; i >= 0; i--) {
            if (i == 0)
                swap(side,0, 3);
            else
                swap(side, i, i - 1);
        }
    }
}
int main() {
    info[0] = { {2,0,2},{0,0,0},{0,2,3},{2,2,1} };//ok
    info[1] = { {2,0,2},{2,2,1},{0,2,3},{0,0,0} };//ok
    info[2] = { {2,0,2},{2,0,2},{0,2,3},{2,0,2} };//ok
    info[3] = { {2,0,2},{0,2,3},{0,2,3},{0,2,3} };//ok
    info[4] = { {0,0,0},{0,0,0},{0,0,0},{0,0,0} };
    info[5] = { {2,2,1},{2,2,1},{2,2,1},{2,2,1} };
    cin >> T;
    FOR(t, 0, T) {
        FOR(i, 0, 6) {
            FOR(j, 0, 3) {
                FOR(k, 0, 4) {
                    cube[i][j][k] = i;
                }
            }
        }

        cin >> N;
        char s, d;
        int side;
        bool dir;
        FOR(i, 0, N) {
            cin >> s >> d;
            if (s == 'U') side = 0;
            else if (s == 'D') side = 1;
            else if (s == 'F') side = 2;
            else if (s == 'B') side = 3;
            else if (s == 'L') side = 4;
            else side = 5;
            if (d == '+') dir = 1;
            else dir = 0;
            pre[0] = -1, pre[1] = -1, pre[2] = -1;
            rotate(side, dir);
        }
        int color;
        FOR(r, 0, 3) {
            FOR(c, 0, 3) {
                color = cube[0][r][c];
                if (color == 0)
                    cout << 'w';
                else if (color == 1)
                    cout << 'y';
                else if (color == 2)
                    cout << 'r';
                else if (color == 3)
                    cout << 'o';
                else if (color == 4)
                    cout << 'g';
                else if (color == 5)
                    cout << 'b';
            }
            cout << '\n';
        }
    }
    return 0;
}
