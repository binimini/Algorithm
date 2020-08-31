#include <iostream>
#include <algorithm>
using namespace std;
string A, B;
int cnt = 0, m = 51;
int main() {
    cin >> A >> B;
    for (int i = 0; i <= B.size() - A.size(); i++) {
        cnt = 0;
        for (int j = 0; j < A.size(); j++) {
            if (A[j] != B[j + i])
                cnt++;
        }
        m = min(cnt, m);
    }
    cout << m << "\n";

    return 0;
}