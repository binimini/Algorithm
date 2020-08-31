#include <iostream>
using namespace std;

int main() {
    int F, C, P;
    int N;
    cin >> F >> C >> P;
    //F < (P - C)n
    if (P <= C)
        cout << -1 << endl;
    else {
        N = F / (P - C);
        N++;
        cout << N << endl;
    }
    return 0;
}