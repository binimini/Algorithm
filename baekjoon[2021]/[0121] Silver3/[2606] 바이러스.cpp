#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int N,M, p[101] = { 0 };
int find_p(int x) {
    if (x == p[x])
        return x;
    return p[x] = find_p(p[x]);
}
void union_p(int x, int y) {
    x = find_p(x);
    y = find_p(y);
    if (x <= y)
        p[y] = x;
    else
        p[x] = y;
}
int main() {
    FASTIO;
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        p[i] = i;
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        union_p(a, b);
    }
    int res = 0;
    for (int i = 1; i <= N; i++) {
        if (find_p(i) == 1)
            res++;
    }
    cout << res-1;
    return 0;
}