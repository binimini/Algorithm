#include <bits/stdc++.h>
using namespace std;
int N, M;
int p[500000];
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int find_p(int x) {
    if (p[x] == x)
        return x;
    return find_p(p[x]);
}
void union_p(int x, int y) {
    x = find_p(x);
    y = find_p(y);
    if (x < y)
        p[y] = x;
    else
        p[x] = y;
}
int main() {
    FASTIO;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        p[i] = i;
    }
    int a, b;
    int flag = 0;
    for (int i = 1; i <= M; i++) {
        cin >> a >> b;
        if (find_p(a) == find_p(b)) {
            flag = i;
            break;
        }
        else
            union_p(a, b);

    }
    cout << flag;
    return 0;
}