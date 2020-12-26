#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int N, arr[1500][1500], idx[1500];
int main() {
    FASTIO;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        idx[i] = N - 1;
    }
    pair<int, int> m = { -100000001, 0 };
    for (int i = 0; i < N; i++) {
        m.first = -100000001;
        for (int j = 0; j < N; j++) {
            if (arr[idx[j]][j] > m.first)
                m.first = arr[idx[j]][j], m.second = j;
        }
        idx[m.second]--;
    }
    cout << m.first;
    return 0;
}