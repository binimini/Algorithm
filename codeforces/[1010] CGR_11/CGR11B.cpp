#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FOR(i,a,b) for (int i = a; i<b; i++)
int T, N,K;
int main() {
    FASTIO;
    cin >> T;
    FOR(t, 0, T) {
        cin >> N >> K;
        string s;
        cin >> s;
        int l_cnt = 0;
        int cnt = 0, point = 0;
        bool pre = 0;
        bool flag = 0;
        vector<int> v;
        FOR(i, 0, N) {
            if (s[i] == 'L') {
                l_cnt++;
                if (flag) {
                    cnt++;
                }
                pre = 0;
            }
            else if (s[i]=='W'){
                if (pre)
                    point += 2;
                else
                    point += 1;
                if (!flag)
                    flag= 1;
                else {
                    if (cnt != 0)
                        v.push_back(cnt);
                    cnt = 0;
                }
                pre = 1;
            }
        }
        sort(v.begin(), v.end(), greater<int>());
        int temp = K;
        bool solo_flag = 0;
        while (temp != 0) {
            if (l_cnt == 0)
                break;
            if (!solo_flag) {
                if (v.empty())
                    solo_flag = 1;
                while (!v.empty()) {
                    if (v.back() > temp) {
                        solo_flag = 1;
                        break;
                    }
                    else {
                        temp -= v.back();
                        point += 2 * v.back() + 1;
                        l_cnt -= v.back();
                        v.pop_back();
                    }
                }
            }
            else {
                if (l_cnt == N) {
                    point++;
                    l_cnt--;
                    temp--;
                }
                else {
                    point += 2;
                    l_cnt--;
                    temp--;
                }
            }
        }
        cout << point << "\n";
    }
    return 0;
}