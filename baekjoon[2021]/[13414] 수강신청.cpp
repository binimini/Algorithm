#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int K, L;
map <string, int> m;
queue<pair<string, int>> q;
int main() {
    FASTIO;
    cin >> K >> L;
    string s;
    for (int i = 0; i < L; i++) {
        cin >> s;
        m[s] = q.size();
        q.push(make_pair(s,q.size()));
    }
    vector<string> v;
    while (!q.empty()) {//v 다 차기 전에 q 빌 수도 있다?
        if (m[q.front().first] == q.front().second)
            v.push_back(q.front().first);
        q.pop();
    }
    for (int i = 0; i < v.size(); i++) {
        if (i > K - 1)//K개만 출력
            break;
        cout << v[i] << "\n";
    }
    return 0;
}