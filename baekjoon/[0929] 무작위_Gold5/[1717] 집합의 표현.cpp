#include <iostream>
using namespace std;
int p[1000001];
int N, M;
int find_p(int x) {
    if (p[x] == x)
        return x;
    else
        return p[x] = find_p(p[x]);
}
void union_p(int x, int y) {
    x = find_p(x);
    y = find_p(y);
    p[x] = y;
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i <= N; i++) {
        p[i] = i;
    }
    int a, b, c;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        if (a == 0) {
            union_p(b, c);
        }
        else if (a == 1) {
            if (find_p(b) == find_p(c))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

    return 0;
}