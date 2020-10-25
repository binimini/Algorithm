#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
string X, Y, Z;
int dp[100][100][100];
int find_dp(int x, int y, int z) {
    if (x >= X.size() || y >= Y.size() || z >= Z.size())
        return 0;
    if (dp[x][y][z] != -1)
        return dp[x][y][z];
    if (X[x] == Y[y] && Y[y] == Z[z])
        return dp[x][y][z] = max(find_dp(x + 1, y + 1, z + 1) + 1, max(find_dp(x, y, z + 1), max(find_dp(x, y + 1, z), find_dp(x + 1, y, z))));
    else
        return dp[x][y][z] = max(find_dp(x, y, z + 1), max(find_dp(x, y + 1, z), find_dp(x + 1, y, z)));
}
int main() {
    cin >> X >> Y >> Z;
    memset(dp, -1, sizeof(dp));
    cout << find_dp(0, 0, 0);
    return 0;
}