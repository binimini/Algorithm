#include <bits/stdc++.h>
using namespace std;
int T,N, cnt = 0;
int fibbo[100] = { 0 };
void f() {
    int temp, temp1 = 0, temp2 = 1;
    fibbo[cnt] = temp1;
    cnt++;
    while (temp2 <= 1000000000) {
        fibbo[cnt] = temp2;
        temp = temp2;
        temp2 = temp1 + temp2;
        temp1 = temp;
        cnt++;
    }
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> T;
    f();
    vector<int> v;
    for (int t = 0; t < T; t++) {
        int c = cnt-1;
        cin >> N;
        while (N != 0) {
            while (c != 0) {
                if (N >= fibbo[c]) {
                    N -= fibbo[c];
                    v.push_back(fibbo[c]);
                    break;
                }
                c--;
            }
        }
        while (!v.empty()) {
            cout << v.back() << " ";
            v.pop_back();
        }
        cout << "\n";
    }
    return 0;
}