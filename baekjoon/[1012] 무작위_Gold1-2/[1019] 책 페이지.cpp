#include <iostream>
using namespace std;
int ans[10] = { 0 };
void calcu(int n, int t) {
    while (n > 0) {
        ans[n % 10] += t;
        n /= 10;
    }
}
int main() {
    int start = 1, temp = 1, finish;
    cin >> finish;
    while (start <= finish) {
        while (start % 10 != 0 && start <= finish) {
            calcu(start, temp);
            start++;
        }
        if (start > finish)
            break;
        while (finish % 10 != 9 && start <= finish) {
            calcu(finish, temp);
            finish--;
        }
        start /= 10;
        finish /= 10;
        for (int i = 0; i <= 9; i++) {
            ans[i] += (finish - start + 1) * temp;
        }
        temp *= 10;
    }
    for (int i = 0; i <= 9; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}