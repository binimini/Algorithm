#include <iostream>
using namespace std;
int main() {
    int x1, x2, x3, y1, y2, y3;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;
    if (x1 == x2)
        cout << x3;
    else if (x1 == x3)
        cout << x2;
    else
        cout << x1;
    cout << " ";
    if (y1 == y2)
        cout << y3 << endl;
    else if (y1 == y3)
        cout << y2 << endl;
    else
        cout << y1 << endl;
    return 0;
}