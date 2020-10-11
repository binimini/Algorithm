#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FOR(i,a,b) for (int i = a; i<b; i++)
int T, N;
int main() {
    FASTIO;
    cin >> T;
    FOR(t, 0, T) {
        cin >> N;
        vector<int> e;
        vector<int> o;
        FOR(i, 1, N + 1) {
            if (i % 2 == 0)
                e.push_back(i);
            else
                o.push_back(i);
        }
        int cnt = 0;
        int x, y;
        cout << 2 << "\n";
        while (cnt != N - 1) {
            cnt++;
            if (e.size() >= 2 && o.size() >= 2) {
                if (e[e.size() - 1] + e[e.size() - 2] < o[o.size() - 1] + o[o.size() - 2]) {
                    x = o.back();
                    o.pop_back();
                    y = o.back();
                    o.pop_back();
                    if (((x + y) / 2) % 2 == 0)
                        e.push_back((x + y) / 2);
                    else
                        o.push_back((x + y) / 2);
                }
                else {
                    x = e.back();
                    e.pop_back();
                    y = e.back();
                    e.pop_back();
                    if (((x + y) / 2) % 2 == 0)
                        e.push_back((x + y) / 2);
                    else
                        o.push_back((x + y) / 2);
                }
            }
            else if (e.size() >= 2) {
                x = e.back();
                e.pop_back();
                y = e.back();
                e.pop_back();
                if (((x + y) / 2) % 2 == 0)
                    e.push_back((x + y) / 2);
                else
                    o.push_back((x + y) / 2);
            }
            else if (o.size() >= 2) {
                x = o.back();
                o.pop_back();
                y = o.back();
                o.pop_back();
                if (((x + y) / 2) % 2 == 0)
                    e.push_back((x + y) / 2);
                else
                    o.push_back((x + y) / 2);
            }
            else {
                x = o.back();
                o.pop_back();
                y = e.back();
                e.pop_back();
                if (((x + y) / 2) % 2 == 0)
                    e.push_back((x + y) / 2);
                else
                    o.push_back((x + y) / 2);
            }
            cout << x << " " << y << "\n";
        }
    }
    return 0;
}