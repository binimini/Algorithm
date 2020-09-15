#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,a,b) for (int i = a; i<b; i++)
int N, Q;
set<int> s;
set<int>::iterator g_idx() {
    pair<int, set<int>::iterator> M = { 0,s.end() };
    int pre = -1;
    int cnt = 0;
    for (set<int>::iterator i = s.begin(); i !=s.end(); i++) {
        if (pre != -1) {
            if (*i - pre > M.first) {
                M.first = *i - pre;
                M.second = i;
            }
        }
        pre = *i;
        cnt++;
    }
    return M.second;
}
int main() {
    FASTIO;
    cin >> N >> Q;
    int temp;
    FOR(i, 0, N) {
        cin >> temp;
        s.insert(temp);
    }
    set<int>::iterator idx = g_idx();
    int cnt = 0;
    if (idx != s.end()) {
        idx--;
        cnt += *idx - *s.begin();
        idx++;
        cnt += *(--s.end()) - *idx;
    }
    cout << cnt << '\n';
    cout << cnt << "\n";
    int t, x;
    FOR(i, 0, Q) {
        cin >> t >> x;
        if (t == 0) {
            s.erase(s.find(x));
        }
        else {
            s.insert(x);
        }
        set<int>::iterator idx = g_idx();
        int cnt = 0;
        if (idx != s.end()) {
            idx--;
            cnt += *idx - *s.begin();
            idx++;
            cnt += *(--s.end()) - *idx;
        }
        cout << cnt << '\n';
    }
    return 0;
}