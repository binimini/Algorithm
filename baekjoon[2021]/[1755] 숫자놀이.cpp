#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int N, M;
vector<string> v;
bool ex[100] = { 0 };
string num[10];
map<string, int> m;
int main() {
    FASTIO;
    num[0] = "zero", num[1] = "one";
    num[2] = "two", num[3] = "three";
    num[4] = "four", num[5] = "five";
    num[6] = "six", num[7] = "seven";
    num[8] = "eight", num[9] = "nine";
    cin >> N >> M;
    for (int i = N; i <= M; i++)
        ex[i] = 1;
    for (int i = 0; i < 10; i++)
        m[num[i]] = i;
    int cnt = 0;
    for (auto ii = m.begin(); ii != m.end(); ii++) {
        if (ii->first == "zero") continue;
        if (ex[ii->second]) {
            cnt++;
            cout << ii->second << " ";
            if (cnt % 10 == 0)
                cout << "\n";
        }
        for (auto ij = m.begin(); ij != m.end(); ij++) {
            if (ex[ii->second * 10 + ij->second]) {
                cnt++;
                cout << ii->second * 10 + ij->second << " ";
                if (cnt % 10 == 0)
                    cout << '\n';
            }
        }
    }
    return 0;
}