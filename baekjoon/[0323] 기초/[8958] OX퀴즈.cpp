#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int result = 0, count = 0;
        string temp;
        cin >> temp;
        for (int j = 0; j < temp.size(); j++) {
            if (temp.at(j) == 'O')
                count = count + 1;
            else
                count = 0;
            result += count;
        }
        cout << result << endl;
    }
    return 0;
}