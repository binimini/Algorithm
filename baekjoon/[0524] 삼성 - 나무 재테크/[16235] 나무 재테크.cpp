#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, M, K, A[11][101], map[11][101], die = 0;
vector<vector<vector<int>>> tree_age;
void spring(int i, int j) {
    int die = 0, check = 0;
    int s = tree_age[i][j].size();
    sort(tree_age[i][j].begin(), tree_age[i][j].end());
    for (int x = 0; x < s; x++) {
        if (map[i][j] >= tree_age[i][j][x]) {
            map[i][j] -= tree_age[i][j][x];
            tree_age[i][j][x]++;
        }
        else {
            die += tree_age[i][j][x] / 2;
            check++;
        }
    }
    for (int y = 0; y < check; y++) {
        tree_age[i][j].pop_back();
    }
    map[i][j] += die;
}
void fall(int i, int j) {
    for (int k = 0; k < tree_age[i][j].size(); k++) {
        if (tree_age[i][j][k] > 0) {
            if (tree_age[i][j][k] % 5 == 0) {
                if (i - 1 > 0) {
                    tree_age[i - 1][j].push_back(1);
                    if (j - 1 > 0) tree_age[i - 1][j - 1].push_back(1);
                    if (j + 1 <= N) tree_age[i - 1][j + 1].push_back(1);
                }
                if (i + 1 <= N) {
                    tree_age[i + 1][j].push_back(1);
                    if (j - 1 > 0) tree_age[i + 1][j - 1].push_back(1);
                    if (j + 1 <= N) tree_age[i + 1][j + 1].push_back(1);
                }
                if (j - 1 > 0) tree_age[i][j - 1].push_back(1);
                if (j + 1 <= N) tree_age[i][j + 1].push_back(1);
            }
        }
    }
}
int main() {
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            map[i][j] = 5;
            cin >> A[i][j];
        }
    }
    tree_age.assign(11, vector < vector <int> >(101, vector <int>()));
    for (int i = 0; i < M; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        tree_age[x][y].push_back(z);
    }
    for (int k = 0; k < K; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                spring(i, j);
            }
        }
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                fall(i, j);
                map[i][j] += A[i][j];
            }
        }
    }
    int sum = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            sum += tree_age[i][j].size();
        }
    }
    cout << sum << "\n";
    return 0;
}