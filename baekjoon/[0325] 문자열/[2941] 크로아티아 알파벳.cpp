#include <iostream>
using namespace std;

int main() {
    // z 122
    string s;
    int count = 0;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        count++;
        int temp = s[i];
        if (temp < 65) {
            count--;
            if (i > 1 && s[i - 1] == 'z')
                if (s[i - 2] == 'd')
                    count--;
        }
        if (s[i] == 'j')
            if (i != 0)
                if (s[i - 1] == 'l' || s[i - 1] == 'n')
                    count--;
    }
    cout << count << endl;
    return 0;
}