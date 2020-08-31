#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, K, DP[101][100001];
vector<pair<int, int>> v;
int main() {
    cin >> N >> K;
    v.push_back(make_pair(0, 0));
    for (int i = 1; i <= N; i++) {
        int W, V;
        cin >> W >> V;
        v.push_back(make_pair(W, V));
    }
    for (int i = 1; i <= K; i++) {
        if (i >= v[1].first)
            DP[1][i] = v[1].second;
    }
    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            if (j >= v[i].first) {
                DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - v[i].first] + v[i].second);
            }
            else {
                DP[i][j] = DP[i - 1][j];
            }
        }
    }
    cout << DP[N][K] << "\n";
    return 0;
}