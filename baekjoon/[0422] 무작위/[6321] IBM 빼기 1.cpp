#include <iostream>
using namespace std;
int N;
int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        if (i != 1)
            cout << '\n';
        cout << "String #" << i << "\n";
        string temp;
        cin >> temp;
        for (int j = 0; j < temp.size(); j++) {
            if (temp[j] == 'Z')
                cout << 'A';
            else
                cout << char(temp[j] + 1);
        }
        cout << '\n';
    }
    return 0;
}