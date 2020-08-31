#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N, M;
bool CH = 0;
queue<int> q, r;
vector<int> v[1001];
int deg[1001] = { 0 };
void tpsort() {//위상정렬
    for (int i = 1; i <= N; i++) {
        if (!deg[i])
            q.push(i);
    }
    for (int i = 1; i <= N; i++) {
        if (q.empty()) {//사이클 존재할 경우 불가 종료하고 0출력
            CH = 1;
            return;
        }
        int x = q.front();
        q.pop();
        r.push(x);
        for (int j = 0; j < v[x].size(); j++) {
            deg[v[x][j]]--;
            if (!deg[v[x][j]])
                q.push(v[x][j]);
        }
    }
}
int main() {//음악프로그램
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    int temp;
    for (int i = 0; i < M; i++) {
        cin >> temp;
        int con, pre = -1;
        for (int j = 0; j < temp; j++) {
            cin >> con;
            if (pre != -1) {
                v[pre].push_back(con);
                deg[con]++;
            }
            pre = con;
        }
    }
    tpsort();
    if (CH == 1)
        cout << '0';
    else {
        while (!r.empty()) {
            cout << r.front() << "\n";
            r.pop();
        }
    }
    return 0;
}