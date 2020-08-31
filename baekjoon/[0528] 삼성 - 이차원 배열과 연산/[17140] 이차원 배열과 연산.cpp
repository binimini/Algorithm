#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int A[100][100] = { 0 }, r, c, k, R_cnt = 3, C_cnt = 3, oper[101] = { 0 }, time = 0, temp_R_cnt = 0, temp_C_cnt = 0;
vector<pair<int, int>> v;
bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first)
        return a.second > b.second;
    return a.first > b.first;
}
bool R_oper(int i) {
    for (int j = 0; j < C_cnt; j++) {
        if (A[i][j]) oper[A[i][j]]++;
        A[i][j] = 0;
    }
    int temp = 0;
    for (int i = 1; i <= 100; i++) {
        if (oper[i]) {
            temp++;
            pair<int, int> temp = make_pair(oper[i], i);
            v.push_back(temp);
            oper[i] = 0;
        }
    }
    sort(v.begin(), v.end(), compare);
    temp_C_cnt = max(temp_C_cnt, temp * 2);
    temp = 0;
    while (!v.empty()) {
        A[i][temp] = v.back().second;
        A[i][temp + 1] = v.back().first;
        temp += 2;
        v.pop_back();
    }
    return true;
}
bool C_oper(int j) {
    for (int i = 0; i < R_cnt; i++) {
        if (A[i][j]) oper[A[i][j]]++;
        A[i][j] = 0;
    }
    int temp = 0;
    for (int i = 1; i <= 100; i++) {
        if (oper[i]) {
            temp++;
            pair<int, int> temp = make_pair(oper[i], i);
            v.push_back(temp);
            oper[i] = 0;
        }
    }
    sort(v.begin(), v.end(), compare);
    temp_R_cnt = max(temp_R_cnt, temp * 2);
    temp = 0;
    while (!v.empty()) {
        A[temp][j] = v.back().second;
        A[temp + 1][j] = v.back().first;
        temp += 2;
        v.pop_back();
    }
    return true;
}
int main() {
    cin >> r >> c >> k;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> A[i][j];
        }
    }
    while (A[r - 1][c - 1] != k) {
        if (time > 100) {
            cout << -1 << "\n";
            return 0;
        }
        time++;
        if (R_cnt >= C_cnt) {
            for (int i = 0; i < R_cnt; i++) {
                if (!R_oper(i)) { cout << -1 << '\n'; return 0; }
            }
            if (temp_C_cnt > 100) temp_C_cnt = 100;
            C_cnt = temp_C_cnt;
            temp_C_cnt = 0;
        }
        else if (R_cnt < C_cnt) {
            for (int i = 0; i < C_cnt; i++) {
                if (!C_oper(i)) { cout << -1 << "\n";  return 0; }
            }
            if (temp_R_cnt > 100) temp_R_cnt = 0;
            R_cnt = temp_R_cnt;
            temp_R_cnt = 0;
        }
    }
    cout << time << '\n';
    return 0;
}