#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int N, M;
bool moved[10000] = { 0 };
vector<int> crane, box;
int main() {
    FASTIO;
    cin >> N;
    int temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        crane.push_back(temp);
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> temp;
        box.push_back(temp);
    }
    sort(crane.begin(), crane.end(), greater<int>());
    sort(box.begin(), box.end(), greater<int>());
    int t = 0, c = 0, u = 0;
    bool flag = 1;
    while (flag) {
        c = 0;
        t++;
        for (int i = 0; i < box.size(); i++) {
            cout << i << " " << c << "\n";
            if (moved[i]) continue;
            if (crane[c] >= box[i]) {
                c++, u++;
                moved[i] = 1;
                if (c == crane.size())
                    break;
            }
            else if (c == 0) {
                flag = 0;
                break;
            }
        }
        if (u == box.size())
            break;
    }
    if (flag)
        cout << t;
    else
        cout << -1;
    return 0;
}