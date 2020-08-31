#include <iostream>
using namespace std;
int F(int n) {
    if (n <= 1)
        return n;
    else
        return F(n - 1) + F(n - 2);
}
int main() {
    int N;
    cin >> N;
    cout << F(N);
    return 0;
}