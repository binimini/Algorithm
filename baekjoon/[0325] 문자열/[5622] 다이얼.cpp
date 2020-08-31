#include <iostream>
using namespace std;

int main() {
    string s;
    int time = 0;
    cin >> s;
    //80 9 84 10 87 11
    for (int i = 0; i < s.size(); i++) {
        int temp = s[i];
        if (temp < 80)
            temp = (temp - 65) / 3 + 3;
        else if (temp >= 87)
            temp = 10;
        else if (temp >= 84)
            temp = 9;
        else
            temp = 8;
        time += temp;
    }
    cout << time << endl;
    return 0;
}