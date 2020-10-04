#include <iostream>
using namespace std;
int N, M;
int p[201];
int find_p(int x) {
    if (x == p[x])
        return x;
    else return p[x] = find_p(p[x]);
}
void union_p(int x, int y) {
    x = find_p(x);
    y = find_p(y);

    p[y] = x;
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        p[i] = i;
    }
    bool y;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> y;
            if (y) {
                union_p(i, j);
            }
        }
    }
    bool flag = 1;
    int pre = -1, temp;
    for (int i = 0; i < M; i++) {
        cin >> temp;
        if (pre != -1) {
            if (find_p(temp) != find_p(pre)) {
                flag = 0;
                break;
            }
        }
        pre = temp;
    }
    if (flag)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}