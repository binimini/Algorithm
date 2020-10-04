#include <iostream>
#include <math.h>
using namespace std;
int N;
bool is_prime(int x) {
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0)
            return false;
    }
    return true;
}
void dfs(int x, int cnt) {
    if (cnt == N) {
        cout << x << '\n';
        return;
    }
    for (int i = 1; i <= 9; i++) {
        int nx = x * 10 + i;
        if (is_prime(nx)) {
            dfs(nx, cnt + 1);
        }
    }
}
int main() {
    cin >> N;
    dfs(2, 1);
    dfs(3, 1);
    dfs(5, 1);
    dfs(7, 1);
    return 0;
}