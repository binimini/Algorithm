#include <bits/stdc++.h>
using namespace std;
int X[3];
queue<tuple<int, int, int>> q;
vector<int> v;
bool visited[201][201][201];
void bfs() {
    while (!q.empty()) {
        int x[3];
        x[0] = get<0>(q.front());
        x[1] = get<1>(q.front());
        x[2] = get<2>(q.front());
        q.pop();
        int nx[3];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == j) continue;
                if (x[i] == 0) continue;
                if (x[j] == X[j]) continue;
                nx[0] = x[0], nx[1] = x[1], nx[2] = x[2];
                if (x[j] + x[i] > X[j]) {
                    nx[j] = X[j];
                    nx[i] = x[i] - (X[j]-x[j]);
                }
                else {
                    nx[j] = x[j] + x[i];
                    nx[i] = 0;
                }
                if (visited[nx[0]][nx[1]][nx[2]]) continue;
                visited[nx[0]][nx[1]][nx[2]] = 1;
                if (nx[0] == 0)
                    v.push_back(nx[2]);
                q.push(make_tuple(nx[0], nx[1], nx[2]));

            }
        }
    }
}
int main() {
    cin >> X[0]>> X[1] >> X[2];
    visited[0][0][X[2]] = 1;
    v.push_back(X[2]);
    q.push(make_tuple(0, 0, X[2]));
    bfs();
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << '\n';
    return 0;
}