#include <iostream>
#include <vector>
using namespace std;
int N, M, K;
bool a[4000001] = { 0 };
int p[4000001];
vector<int> v;
int find(int x) {
    if (p[x] == x)
        return x;
    return p[x] = find(p[x]);
}
void uni(int x,int y) {
    x = find(x);//!!!!!!parent 쓰지말고 find() 쓰라고!!!!!!!!
    y = find(y);
    if (x < y)
        p[x] = y;
    else p[y] = x;
}
int upper_bound(int x) {
    int s = 0, e = N+1;
    int m;
    while (e - s > 0) {
        m = (s + e) / 2;
        if (m <= x)
            s = m + 1;
        else
            e = m;
    }
    if (a[e] == 0) {
        int ne = find(e);
        a[ne] = 0;
        uni(ne, ne + 1);
        return ne;
    }
    else {
        a[e] = 0;
        uni(e, e + 1);
        return e;
    }
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        p[i] = i;
    }
    int temp;
    for (int i = 0; i < M; i++) {
        cin >> temp;
        a[temp] = 1;
    }
    int pa = -1;
    for (int i = N; i >= 1; i--) {
        if (!a[i]&&pa != -1) {
            uni(i, pa);
        }
        if (a[i])
            pa = i;
    }
    int t;
    for (int i = 0; i < K; i++) {
       cin >> t;       
       cout << upper_bound(t) << "\n";
    }
    return 0;
}