#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int N, map[101][101] = { 0 }, d[4][2] = { {0,1},{-1,0},{0,-1},{1,0} }, cnt = 0, x, y, arr[1025], min_x = 100, max_x = 0, min_y = 100, max_y = 0;
void DFS(int node, int direc, int g) {
    if (g <= 1) {
        if (g == 0) {
            arr[node] = direc;
            return;
        }
        else {
            arr[node] = direc;
            arr[node + 1] = (direc + 1) % 4;
            return;
        }
    }
    int num = pow(2, g);
    for (int i = 0; i < 2; i++) {
        DFS(node + (num / 2) * i, direc, g - 1);
    }
    for (int i = node + num / 2; i < node + num / 2 + num / 4; i++) {
        arr[i] = (arr[i] + 2) % 4;
    }


}
void move(int g) {
    int num = pow(2, g);
    map[y][x] = 1;
    min_x = min(x, min_x);
    min_y = min(y, min_y);
    max_x = max(x, max_x);
    max_y = max(y, max_y);
    for (int i = 1; i <= num; i++) {
        x += d[arr[i]][1], y += d[arr[i]][0];
        map[y][x] = 1;
        min_x = min(x, min_x);
        min_y = min(y, min_y);
        max_x = max(x, max_x);
        max_y = max(y, max_y);
    }
}
bool check(int y, int x) {
    if (y + 1 > 100 || x + 1 > 100) return false;
    if (map[y][x] == 1 && map[y + 1][x] == 1 && map[y][x + 1] == 1 && map[y + 1][x + 1] == 1)
        return true;
    else return false;
}
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int d, g;
        cin >> x >> y >> d >> g;
        DFS(1, d, g);
        int num = pow(2, g);
        move(g);
    }
    for (int i = min_y; i <= max_y; i++) {
        for (int j = min_x; j <= max_x; j++) {
            if (check(i, j)) cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}