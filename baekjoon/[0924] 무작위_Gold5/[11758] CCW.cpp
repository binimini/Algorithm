#include <iostream>
using namespace std;
pair<int, int> A, B, C;
int CCW(pair<int, int> A, pair<int, int> B, pair<int, int> C) {
    int ccw = A.first * B.second + B.first * C.second + C.first * A.second - (A.second * B.first + B.second * C.first + C.second * A.first);
    if (ccw == 0)
        return 0;
    else if (ccw > 0)
        return 1;
    else if (ccw < 0)
        return -1;
}
int main() {
    cin >> A.first >> A.second;
    cin >> B.first >> B.second;
    cin >> C.first >> C.second;
    cout << CCW(A, B, C) << "\n";
    return 0;
}