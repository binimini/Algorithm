#include <iostream>
using namespace std;
int N, result = 0;
int arr[15];
bool prob(int x) {
    for (int i = 1; i < x; i++) {
        if (arr[i] == arr[x])
            return false;
        if (arr[i] + i == arr[x] + x)
            return false;
        if (arr[i] - i == arr[x] - x)
            return false;
    }
    return true;
}

void DFS(int cnt) {
    if (cnt == N) {
        result++;
        return;
    }
    for (int i = 1; i <= N; i++) {
        arr[cnt + 1] = i;
        if (prob(cnt + 1)) {
            DFS(cnt + 1);
        }
    }
}
int main() {
    cin >> N;
    DFS(0);
    cout << result << '\n';
    return 0;
}