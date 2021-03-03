#include <bits/stdc++.h>
using namespace std;
set<int> s[100001];//x일때 y값
//x y 될 수 있는 값 0-100000 전부 아님 x-ky 식으로 한정된 값이므로 
//안쓰는 값이 낭비되는 배열 대신 사용할 값만 넣는 map이나 set 통해 메모리 줄임
queue<pair<int,pair<int, int>>> q;
int A, B, N, M;
int bfs() {
    q.push({ 0,{ 0,0 } });
    s[0].insert(0);
    if (!N && !M)
        return 0;
    while (!q.empty()) {
        int c = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();
        //empty
        if (!s[0].count(y)) {
            s[0].insert(y);
            q.push({ c + 1,{0,y} });
            if (N == 0 && M == y)
                return c + 1;
        }
        if (!s[x].count(0)) {
            s[x].insert(0);
            q.push({ c + 1,{x,0} });
            if (N == x && M == 0)
                return c + 1;
        }
        //fill
        if (!s[A].count(y)) {
            s[A].insert(y);
            q.push({ c + 1,{A,y} });
            if (N == A && M == y)
                return c + 1;
        }
        if (!s[x].count(B)) {
            s[x].insert(B);
            q.push({ c + 1, {x,B} });
            if (N == x && M == B)
                return c + 1;
        }
        //move
        if (!s[max(0, x - (B - y))].count(min(y + x, B))) {
            s[max(0, x - (B - y))].insert(min(y + x, B));
            q.push({ c + 1,{max(0, x - (B - y)),min(y + x, B)} });
            if (N == max(0, x - (B - y)) && M == min(y + x, B))
                return c + 1;
        }
        if (!s[min(x+y,A)].count(max(y-(A-x),0))) {
            s[min(x+y,A)].insert(max(y - (A - x), 0));
            q.push({ c + 1,{min(x + y,A),max(y - (A - x), 0)} });
            if (N == min(x + y, A) && M == max(y - (A - x), 0))
                return c + 1;
        }
    }
    return -1;
}
int main() {
    cin >> A >> B >> N >> M;
    cout <<bfs();
    return 0;
}