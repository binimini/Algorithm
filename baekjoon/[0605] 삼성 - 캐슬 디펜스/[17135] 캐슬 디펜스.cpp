#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int N, M, D, cnt_M = -1, info[3], v_remove[255] = { 0 };
vector<pair<int, int>> v, vec;
pair<int, int> p[3] = { {-1,11},{-1,11},{-1,11} };
int archer() {
    int sum = 0;
    while (!v.empty()) {
        p[0].first = -1, p[1].first = -1, p[2].first = -1;
        p[0].second = 11, p[1].second = 11, p[2].second = 11;

        for (int i = 0; i < v.size(); i++) {
            if (N - v[i].first + abs(info[0] - v[i].second) <= D) {
                if (N - v[i].first + abs(info[0] - v[i].second) < p[0].second) {
                    p[0].first = i, p[0].second = N - v[i].first + abs(info[0] - v[i].second);
                }
                else if (N - v[i].first + abs(info[0] - v[i].second) == p[0].second) {
                    if (v[i].second < v[p[0].first].second) p[0].first = i, p[0].second = N - v[i].first + abs(info[0] - v[i].second);
                }
            }

            if (N - v[i].first + abs(info[1] - v[i].second) <= D) {
                if (N - v[i].first + abs(info[1] - v[i].second) < p[1].second) {
                    p[1].first = i, p[1].second = N - v[i].first + abs(info[1] - v[i].second);
                }
                else if (N - v[i].first + abs(info[1] - v[i].second) == p[1].second) {
                    if (v[i].second < v[p[1].first].second) p[1].first = i, p[1].second = N - v[i].first + abs(info[1] - v[i].second);
                }
            }

            if (N - v[i].first + abs(info[2] - v[i].second) <= D) {
                if (N - v[i].first + abs(info[2] - v[i].second) < p[2].second) {
                    p[2].first = i, p[2].second = N - v[i].first + abs(info[2] - v[i].second);
                }
                else if (N - v[i].first + abs(info[2] - v[i].second) == p[2].second) {
                    if (v[i].second < v[p[2].first].second) p[2].first = i, p[2].second = N - v[i].first + abs(info[2] - v[i].second);
                }
            }
        }

        if (p[0].first != -1) v_remove[p[0].first] = 1;
        if (p[1].first != -1) v_remove[p[1].first] = 1;
        if (p[2].first != -1) v_remove[p[2].first] = 1;

        int temp = 0;
        for (int i = 254; i >= 0; i--) {
            if (temp == 3) break;
            if (v_remove[i]) {
                v.erase(v.begin() + i);
                temp++, sum++;
                v_remove[i] = 0;
            }
        }
        for (int i = v.size() - 1; i >= 0; i--) {
            if (v[i].first == N - 1) v.erase(v.begin() + i);
            else v[i].first += 1;
        }
    }
    return sum;
}
void DFS(int node, int cnt) {
    if (cnt == 3) {
        for (int i = 0; i < vec.size(); i++) {
            v.push_back(vec[i]);
        }
        cnt_M = max(cnt_M, archer());
        return;
    }
    for (int i = node; i < M; i++) {
        info[cnt] = i;
        DFS(node + 1, cnt + 1);
    }
}
int main() {
    cin >> N >> M >> D;
    int temp;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> temp;
            if (temp) vec.push_back(make_pair(i, j));
        }
    }
    DFS(0, 0);
    cout << cnt_M;
    return 0;
}