#include <iostream>
#include <string>
using namespace std;
int check = 0;
int main() {
    string s;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++) {
        if (check == 0 && s[i] == 'U')
            check = 1;
        if (check == 1 && s[i] == 'C')
            check = 2;
        if (check == 2 && s[i] == 'P')
            check = 3;
        if (check == 3 && s[i] == 'C') {
            cout << "I love UCPC";
            check = 4;
            break;
        }
    }
    if (check != 4)
        cout << "I hate UCPC";
    return 0;
}