#include <iostream>
#include <math.h>
using namespace std;
void Hanoi(int n, int start, int end) {
    if (n == 1) {
        cout << start << " " << end << '\n';
    }
    else {
        Hanoi(n - 1, start, 6 - start - end);
        cout << start << " " << end << '\n';
        Hanoi(n - 1, 6 - start - end, end);
    }

}
int main() {
    int N;
    cin >> N;
    cout << int(pow(2, N)) - 1 << '\n';
    Hanoi(N, 1, 3);
    return 0;
}