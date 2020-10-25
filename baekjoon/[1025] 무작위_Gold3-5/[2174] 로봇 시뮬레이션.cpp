#include <iostream>
#include <tuple>
using namespace std;
#define FOR(i,a,b) for (int i = a; i<b; i++)
int A, B, N, M, d[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
tuple<int, int, int> robot[101];
int map[101][101] = { 0 };
int command(int r, char cm,int n) {
    if (cm == 'F') {
        for (int i = 0; i < n; i++) {
            int ny = get<0>(robot[r]);
            int nx = get<1>(robot[r]);
            int nd = get<2>(robot[r]);
            map[ny][nx] = 0;
            ny += d[nd][0];
            nx += d[nd][1];
            if (nx<=0 || ny<=0 || nx>A || ny>B)
                return -1;
            if (map[ny][nx])
                return map[ny][nx];
            map[ny][nx] = r;
            get<0>(robot[r]) = ny;
            get<1>(robot[r]) = nx;
        }
    }
    else if (cm =='R') {
        for (int i = 0; i<n; i++)
            get<2>(robot[r]) = (get<2>(robot[r]) + 1) % 4;
    }
    else if (cm == 'L') {
        for (int i = 0; i < n; i++) {
            get<2>(robot[r]) = get<2>(robot[r]) - 1;
            if (get<2>(robot[r]) == -1)
                get<2>(robot[r]) = 3;
        }
    }
    return 0;
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> A >> B >> N >> M;
    FOR(i, 1, N + 1) {
        char temp;
        cin >> get<1>(robot[i]) >> get<0>(robot[i]) >> temp;
        if (temp == 'N')
            get<2>(robot[i]) = 0;
        else if (temp == 'E')
            get<2>(robot[i]) = 1;
        else if (temp == 'S')
            get<2>(robot[i]) = 2;
        else if (temp == 'W')
            get<2>(robot[i]) = 3;
        map[get<0>(robot[i])][get<1>(robot[i])] = i;
    }
    int r, cnt, result;
    char c;
    bool flag = 0;
    FOR(i, 1, M + 1) {
        cin >> r >> c >> cnt; 
        if (!flag) {
            result = command(r, c, cnt);
            if (result == 0) continue;
            else if (result == -1) {
                cout << "Robot " << r << " crashes into the wall\n";
                flag = 1;
            }
            else {
                cout << "Robot " << r << " crashes into robot " << result << "\n";
                flag = 1;
            }
        }
    }
    if (!flag)
        cout << "OK\n";
    
    return 0;
}