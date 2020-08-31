#include <iostream>
#include <algorithm>
using namespace std;
int N, M = -1000000000, m = 1000000000, result;
int arr[12], oper[11], oper_count[4], oper_check[4];
int op(int x, int a, int b) {
    if (x == 0)
        return a + b;
    else if (x == 1)
        return a - b;
    else if (x == 2)
        return a * b;
    else
        return a / b;
}
bool prob(int x) {
    for (int i = 0; i < 4; i++) {
        oper_check[i] = 0;
    }
    for (int i = 1; i <= x; i++) {
        oper_check[oper[i]]++;
    }
    for (int i = 0; i < 4; i++) {
        if (oper_count[i] < oper_check[i])
            return false;
    }
    return true;
}
void DFS(int cnt) {
    if (cnt == N - 1) {
        result = arr[1];
        for (int i = 1; i <= N - 1; i++) {
            result = op(oper[i], result, arr[i + 1]);
        }
        m = min(result, m);
        M = max(result, M);
        return;
    }
    for (int i = 0; i < 4; i++) {
        oper[cnt + 1] = i;
        if (prob(cnt + 1)) {
            DFS(cnt + 1);
        }
    }
}
int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    for (int j = 0; j < 4; j++) {
        cin >> oper_count[j];
    }
    DFS(0);
    cout << M << '\n';
    cout << m << '\n';
    return 0;
}