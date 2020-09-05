#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,a,b) for (int i = a; i<b; i++)
int T;
string n;
int s;
int main() {
    FASTIO;
    cin >> T;
    FOR(t, 0, T) {
        cin >> n >> s;
        int sum = 0;
        int min_idx;
        for (int i = 0; i < n.size(); i++) {
            sum += n[i] - '0';
        }
        if (sum - s <= 0)
            cout << 0 << '\n';
        else {
            min_idx = sum - s;
            sum = 0;
            int idx;
            for (int i = n.size() - 1; i >= 0; i--) {
                sum += n[i] - '0';
                if (sum >= min_idx) {
                    if (i - 1 >= 0 && n[i - 1] == '9') {
                        idx = i;
                        break;
                    }
                    else {
                        if (sum > min_idx) {
                            idx = i;
                            break;
                            idx = i - 1;
                        }
                    }
                }
            }
            vector<int> v;
            string result = "";
            bool CH = 0;
            queue<int> q;
            if (n[n.size() - 1]-'0' == 0) {
                CH = 1;
                v.push_back(0);
            }
            else v.push_back(10 - (n[n.size() - 1] - '0'));
            for (int i = n.size()-2; i >= idx; i--) {
                int temp;
                temp = 9 - (n[i] - '0');
                if (CH == 1) {
                    temp++;
                    if (temp == 10) {
                        temp = 0;
                    }
                    else CH = 0;
                }
                v.push_back(temp);
            }
            while (!v.empty()) {
                q.push(v.back());
                v.pop_back();
            }
            int CC = 0;
            while (!q.empty()) {
                if (q.front() != 0)
                    CC = 1;
                if (q.front() == 0 && CC == 0) {
                    q.pop();
                    continue;
                }
                cout << q.front();
                q.pop();
            }
            cout << '\n';
        }
    }

    return 0;
}