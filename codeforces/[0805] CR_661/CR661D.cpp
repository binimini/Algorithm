#include <bits/stdc++.h>
using namespace std;
int T, N;
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N;
        int k = 0, result[200000];
        vector<int> need_0, need_1;
        char temp;
        for (int i = 0; i < N; i++) {
            cin >> temp;
            if (k == 0) {
                k++;
                if (temp == '1')
                    need_0.push_back(k);
                else if (temp == '0')
                    need_1.push_back(k);
                result[i] = k;
            }
            else {
                if (temp == '0') {
                    if (need_0.size() == 0) {
                        k++;
                        need_1.push_back(k);
                        result[i] = k;
                    }
                    else {
                        need_1.push_back(need_0.back());
                        result[i] = need_0.back();
                        need_0.pop_back();
                    }
                }
                else if (temp == '1') {
                    if (need_1.size() == 0) {
                        k++;
                        need_0.push_back(k);
                        result[i] = k;
                    }
                    else {
                        need_0.push_back(need_1.back());
                        result[i] = need_1.back();
                        need_1.pop_back();
                    }
                }
            }
        }
        cout << k << '\n';
        for (int i = 0; i < N; i++) {
            cout << result[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}