#include <iostream>
using namespace std;
int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;
        string S, P;
        cin >> S;
        for (int j = 0; j < S.size(); j++) {
            for (int k = 0; k < N; k++) {
                P += S[j];
            }
        }
        cout << P << endl;
    }

    return 0;
}