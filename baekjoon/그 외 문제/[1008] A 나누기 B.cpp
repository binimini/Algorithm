#include <iostream>
#include <iomanip>
using namespace std;
int A, B;
int main() {
    cin >> A >> B;
    double result = A;
    result /= B;
    cout << fixed << setprecision(10);
    cout << result << "\n";
    return 0;
}