#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;
int N;
int tree[1000001] = { 0 };
void update(int i, int diff) {
    while (i < 1000001) {
        tree[i] += diff;
        i += (i & -i);
    }
}
int sum(int i) {
    int ans = 0;
    while (i > 0) {
        ans += tree[i];
        i -= (i & -i);
    }
    return ans;
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    int a, b, c;
    for (int i = 0; i < N; i++) {
        cin >> a;
        if (a == 1) {
            cin >> b;
            int s = 1, e = 1000001, m;
            while (e - s > 0) {
                m = (e + s) / 2;
                if (sum(m) < b)
                    s = m + 1;
                else
                    e = m;
            }
            cout << e << '\n';
            update(e, -1);
        }
        else {
            cin >> b >> c;
            update(b, c);
        }
    }
    return 0;
}