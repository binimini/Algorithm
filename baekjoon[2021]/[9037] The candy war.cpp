#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int T, N;
vector<int> v;
int main() {
    FASTIO;
    cin >> T;
    for (int t = 0; t < T; t++) {
        v.clear();
        cin >> N;
        int temp;
        for (int i = 0; i < N; i++) {
            cin >> temp;
            v.push_back(temp);
        }
        bool flag = 0;
        int prev, cnt = 0;
        while (!flag) {
            prev = -1;
            flag = 1;
            for (int i = 0; i < v.size(); i++) {
                if (v[i] % 2 != 0)
                    v[i]++;
                if (prev == -1)
                    prev = v[i];
                else if (prev != v[i])
                    flag = 0; 
            }
            if (flag)
                break;
            cnt++;
            int half = v[v.size() - 1] / 2, temp;
            for (int i = 0; i < v.size(); i++) {
                v[i] /= 2;
                temp = v[i];
                v[i] += half;
                half = temp;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}