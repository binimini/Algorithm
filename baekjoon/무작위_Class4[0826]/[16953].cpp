#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int A, B, C = 100;
queue<pair<int,int>> q;
void BFS() {
    while(!q.empty()) {
        int x = q.front().first;
        int xc = q.front().second;
        if (x == B)
            C = min(C, xc);
        q.pop();
        long long int nx = x;//x는 int 범위여도 1000000000*10은 int 범위 초과
        nx *= 2;
        if (nx <= B)
            q.push(make_pair(nx, xc + 1));
        nx = x;
        nx *= 10;
        nx += 1;
        if (nx <= B)
            q.push(make_pair(nx, xc + 1));
    }
}
int main() {//A → B
    cin >> A >> B;
    q.push(make_pair(A,0));
    BFS();
    if (C == 100)
        cout << -1;
    else cout << C+1;
    return 0;
}