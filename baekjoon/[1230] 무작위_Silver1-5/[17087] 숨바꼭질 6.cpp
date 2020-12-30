#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int N, S;
vector<int> v;
int main() {
    FASTIO;
    cin >> N >> S;
    int dist;
    for (int i = 0; i < N; i++) {
        cin >> dist;
        dist = abs(dist - S);
        v.push_back(dist);
    }
    int a, b, temp;
    while (v.size() != 1) {
        a = max(v.back(), v[v.size()-2]);
        b = min(v.back(), v[v.size() - 2]);
        temp;
        while (b) {
            temp= a % b;
            a = b;
            b = temp;
        }
        v.pop_back();
        v.pop_back();
        v.push_back(a);
    }
    cout << v[0];
    return 0;
}