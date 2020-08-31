#include <iostream>
#include <algorithm>
using namespace std;
int N, arr_num[10], arr_oper[9], temp_num[10], temp_oper[9], arr[5], b[5], OPER_num, num_num, b_num, M = -2147483647;
void copy_arr() {
    for (int i = 0; i < OPER_num; i++) {
        temp_num[i] = arr_num[i];
        temp_oper[i] = arr_oper[i];
    }
    temp_num[OPER_num] = arr_num[OPER_num];
}
bool check() {
    int pre = -1;
    for (int i = 0; i < b_num; i++) {
        if (pre == -1)
            pre = arr[i];
        else {
            if (arr[i] - pre == 1) return false;
        }
        if (arr_oper[arr[i]] == 0)
            b[i] = arr_num[arr[i]] * arr_num[arr[i] + 1];
        else if (arr_oper[arr[i]] == 1)
            b[i] = arr_num[arr[i]] + arr_num[arr[i] + 1];
        else
            b[i] = arr_num[arr[i]] - arr_num[arr[i] + 1];
        pre = arr[i];
        temp_num[arr[i]] = -1, temp_num[arr[i] + 1] = -1, temp_oper[arr[i]] = -1;
    }
    return true;
}
int oper() {
    int result = -99;
    int b_cnt = 0;
    if (temp_num[0] == -1) {
        result = b[0];
        b_cnt++;
    }
    else result = arr_num[0];
    for (int i = 0; i < OPER_num; i++) {
        if (temp_oper[i] == -1) continue;
        if (temp_num[i + 1] == -1) {
            if (temp_oper[i] == 0) result *= b[b_cnt];
            else if (temp_oper[i] == 1) result += b[b_cnt];
            else result -= b[b_cnt];
            b_cnt++;
        }
        else {
            if (temp_oper[i] == 0) result *= temp_num[i + 1];
            else if (temp_oper[i] == 1) result += temp_num[i + 1];
            else result -= temp_num[i + 1];
        }
    }
    return result;
}
void DFS(int node, int cnt) {
    if (cnt == b_num) {
        copy_arr();
        if (!check()) return;
        M = max(M, oper());
        return;
    }
    for (int i = node; i < OPER_num; i++) {
        arr[cnt] = i;
        DFS(i + 1, cnt + 1);
    }
}
int main() {
    cin >> N;
    OPER_num = N / 2;
    num_num = N - OPER_num;
    b_num = OPER_num / 2 + 1;
    string temp;
    int t = 1;
    cin >> temp;
    arr_num[0] = temp[0] - '0';
    for (int i = 0; i < OPER_num; i++) {
        arr_oper[i] = temp[t] - 42;
        t++;
        arr_num[i + 1] = temp[t] - '0';
        t++;
    }
    while (b_num != 0) {
        DFS(0, 0);
        b_num--;
    }
    copy_arr();
    M = max(M, oper());
    cout << M;
    return 0;
}