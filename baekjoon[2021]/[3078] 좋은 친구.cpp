#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int N, K;
long long int res = 0;      //3*10^5C2 == 3*10^5 * (3*10^5-1) / 2 > int
vector<int> studentLen[21];
string temp;
int ub(int idx, int key) {
    int s = 0, e = studentLen[idx].size(), m;
    while (e - s > 0) {
        m = (s + e) / 2;
        if (studentLen[idx][m] > key)
            e = m;
        else
            s = m + 1;
    }
    return e;
}
int main() {
    FASTIO;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        studentLen[temp.size()].push_back(i);
    }
    for (int i = 0; i <= 20; i++) {
        sort(studentLen[i].begin(), studentLen[i].end());
    }
    int size, t;
    for (int i = 0; i <= 20; i++) {
        size = studentLen[i].size();
        for (int j = 0; j < size; j++) {
            t = ub(i, studentLen[i][j] + K) - 1 - j;
            res += t;
        }
    }
    cout << res;
    return 0;
}