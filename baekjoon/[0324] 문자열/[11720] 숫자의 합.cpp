#include <iostream>
using namespace std;

int main() {
    int size;
    cin >> size;
    string temp;
    cin >> temp;
    int sum = 0;
    for (int j = 0; j < size; j++) {
        sum += temp[j] - '0';
    }
    cout << sum << endl;

    return 0;
}