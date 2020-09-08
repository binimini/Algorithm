#include <bits/stdc++.h>
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;
int gate[100001];
int G, P;
int find(int x) {
    if (gate[x] ==x)
        return x;
    return gate[x] = find(gate[x]);
}
void union_gate(int x, int y) {
    x = find(x);
    y = find(y);
    if (x < y)
        gate[y] = x;
    else
        gate[x] = y;
}
int main() {
    FASTIO;
    cin >> G >> P;
    for (int i = 1; i <= G; i++) {
        gate[i] = i;
    }
    int temp, ans = P;
    for (int i = 1; i <= P; i++) {
        cin >> temp;
        temp = find(temp);
        if (!temp) {
            ans = i - 1;
            break;
        }
        else 
            union_gate(temp - 1, temp);
    }
    for (int i = 0; i < P - (ans + 1); i++) {
        cin >> temp;
    }
    cout << ans << '\n';
    return 0;
}