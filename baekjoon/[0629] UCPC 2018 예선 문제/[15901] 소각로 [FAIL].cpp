#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int N, M, K, Q, inci[500001] = { 0 };
queue<int> line;
void c_1() {
    int L, R;
    cin >> L >> R;
    for (int i = L; i <= R; i++) {
        if (line.empty()) inci[i] = 0;
        else {
            inci[i] = line.front();
            line.pop();
        }
    }
}
void c_2() {
    int i;
    cin >> i;
    cout << inci[i] << " ";
}
void c_3() {
    int p, q;
    cin >> p >> q;
    for (int i = 0; i < q; i++) {
        line.push(p);
    }
}
void c_4() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        line.pop();
    }
}
int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> K >> Q;
    int temp;
    for (int i = 1; i <= N; i++) {
        cin >> temp;
        line.push(temp);
    }
    for (int i = 1; i <= min(N, M); i++) {
        inci[i] = line.front();
        line.pop();
    }
    int o;
    for (int i = 0; i < Q; i++) {
        cin >> o;
        if (o == 1) c_1();
        else if (o == 2) c_2();
        else if (o == 3) c_3();
        else if (o == 4) c_4();
    }
    cout << '\n';
    for (int i = 1; i <= M; i++) {
        cout << inci[i] << " ";
    }
    return 0;
}