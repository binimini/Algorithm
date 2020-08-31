#include <iostream>
#include <algorithm>
using namespace std;
int arr[10], arr_2_move[10], sum = 0, M_sum = 0;
int route[22] = { 0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,-1 }, f_route[9] = { 0,13,16,19,25,30,35,40,-1 }, s_route[9] = { 0, 0,22,24,25,30,35,40,-1 }, t_route[9] = { 0,28,27,26,25,30,35,40,-1 };
pair<int, int> lo[4] = { {-2,0},{-2,0},{-2,0},{-2,0} };
bool check(int x) {
    int d = lo[arr[x]].first, l = lo[arr[x]].second + arr_2_move[x];
    for (int i = 0; i < 4; i++) {
        if (i == x) continue;
        if (d == 0 && l == 20) {
            if (lo[i].first > 0 && lo[i].second == 7) return false;
        }
        if (d > 0) {
            if (lo[i].first == 0 && lo[i].second == 20 && l == 7) return false;
            else if (lo[i].first > 0 && l > 3 && lo[i].second == l) return false;
        }
        if (lo[i].first == d && lo[i].second == l) return false;
    }
    return true;
}
int move() {
    sum = 0;
    for (int i = 0; i < 10; i++) {
        int d = lo[arr[i]].first;
        int n_l = lo[arr[i]].second + arr_2_move[i];
        if ((d == 0 && n_l >= 21) || (d > 0 && n_l > 7)) { lo[arr[i]].first = -1; continue; }
        if (d == -1) return -1;
        if (d == -2) lo[arr[i]].first = 0;
        if (!check(i)) return -1;

        if (lo[arr[i]].first == 0) sum += route[n_l];
        else if (lo[arr[i]].first == 1) sum += f_route[n_l];
        else if (lo[arr[i]].first == 2) sum += s_route[n_l];
        else if (lo[arr[i]].first == 3) sum += t_route[n_l];

        d = lo[arr[i]].first;
        lo[arr[i]].second = n_l;
        if (d == 0 && n_l == 5) { lo[arr[i]].first = 1, lo[arr[i]].second = 0; }
        else if (d == 0 && n_l == 10) lo[arr[i]].first = 2, lo[arr[i]].second = 1;
        else if (d == 0 && n_l == 15) lo[arr[i]].first = 3, lo[arr[i]].second = 0;
        for (int k = 0; k < 4; k++) {
            if (k != arr[i]) {
                if (lo[arr[i]].first == lo[k].first && lo[arr[i]].second == lo[k].second) return -1;
            }
        }
    }

    return sum;
}
void DFS(int cnt) {
    if (cnt == 10) {
        M_sum = max(M_sum, move());
        for (int i = 0; i < 4; i++) {
            lo[i].first = -2;
            lo[i].second = 0;
        }
        return;
    }
    for (int i = 0; i < 4; i++) {
        arr[cnt] = i;
        DFS(cnt + 1);
    }
}
int main() {
    for (int i = 0; i < 10; i++) {
        cin >> arr_2_move[i];
    }
    DFS(0);
    cout << M_sum;
    return 0;
}