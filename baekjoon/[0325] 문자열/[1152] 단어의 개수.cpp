#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    int count = 0;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++) {
        int temp = s[i];
        if (i == 0 && temp >= 65)
            count++;
        if (temp < 65) {
            int check = s[i + 1];
            if (check >= 65)
                count++;
        }
    }
    cout << count << endl;

    return 0;
}