#include <iostream>
#include <string>
using namespace std;
int main() {
    int N, count = 0, num;
    cin >> N;
    for (int i = 666; count != N; i++) {
        string s = to_string(i);
        if (s.find("666") != string::npos) {
            count++;
            num = i;
        }
    }
    cout << num << '\n';
    return 0;
}