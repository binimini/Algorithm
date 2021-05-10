#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int T,N;
vector<int> v;
int main() {
    FASTIO;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N;
        v.clear();
        int cnt = 0;
        bool flag = 0;
        if (N == 1)
            v.push_back(1);
        while (N != 1) {
            flag = 0;
            for (int i = 9; i >= 2; i--) {
                if (N % i == 0) {
                    v.push_back(i);
                    cnt++;
                    flag = 1;
                    N /= i;
                    break;
                }
            }
            if (!flag) {
                v.clear();
                break;
            }
        }
        if (v.empty())
            cout << -1<<"\n";
        else
            cout << v.size()<<"\n";
    }
    return 0;
}