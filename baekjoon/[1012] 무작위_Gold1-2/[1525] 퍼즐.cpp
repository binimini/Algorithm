#include <bits/stdc++.h>
using namespace std;
int d[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
queue<int> q;
map<int, int> m;
void BFS() {
    while (!q.empty()) {
        int s = q.front();
        q.pop();
        if (s == 123456789)
            return;
        string ss = to_string(s);
        int position = ss.find('9');
        int x = position / 3;
        int y = position % 3;
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i][0];
            int ny = y + d[i][1];
            if (nx < 0 || nx>2 || ny < 0 || ny>2) continue;
            int idx = nx * 3 + ny;
            string nss = ss;
            nss[position] = ss[idx];
            nss[idx] = '9';
            int ns = stoi(nss);
            if (m.count(ns) != 0) continue;
            m[ns] = m[s] + 1;
            if (ns == 123456789)
                return;
            q.push(ns);
        }
    }
}
int main() {
    string s = "";
    char num;
    int start;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> num;
            if (num=='0')
                num = '9';
            s += num;
        }
    }
    start = stoi(s);
    m[start] = 0;
    q.push(start);
    BFS();
    if (m.count(123456789) == 0)
        cout << -1;
    else
        cout << m[123456789];
    return 0;
}