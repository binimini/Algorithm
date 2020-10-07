#include <iostream>
#include <map>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,a,b) for (int i = a; i<b; i++)
map<string, int> m;
int T, F;
int p[100000];
int find_p(int x) {
    if (p[x] < 0)
        return x;
    else
        return p[x] = find_p(p[x]);
}
void union_p(int x, int y) {
    x = find_p(x);
    y = find_p(y);
    if (x == y)
        return;
    p[x] += p[y];
    p[y] = x;
}
int main() {
    FASTIO;
    cin >> T;
    FOR(t, 0, T) {
        cin >> F;
        FOR(i, 0, 100000) {
            p[i] = -1;
        }
        string a, b;
        int aidx, bidx;
        FOR(f, 0, F) {
            cin >> a >> b;
            if (m.find(a) == m.end())
                m[a] = m.size();
            if (m.find(b) == m.end())
                m[b] = m.size();
            aidx = m[a], bidx = m[b];
            union_p(aidx, bidx);
            cout << -p[find_p(aidx)] << "\n";
        }
    }
    return 0;
}