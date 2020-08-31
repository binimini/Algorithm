#include <iostream>
using namespace std;

int main() {
    int A, B, V;
    cin >> A >> B >> V;
    if ((V - A) % (A - B) != 0)
        cout << (V - A) / (A - B) + 2 << endl;
    else
        cout << (V - A) / (A - B) + 1 << endl;
    return 0;
}