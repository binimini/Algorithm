#include <iostream>
#include <vector>
using namespace std;
int T;
int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        vector<int> v;
        int C = 0;
        string temp;
        cin >> temp;
        for (int j = 0; j < temp.size(); j++) {
            if (temp[j] == ')') {
                if (v.empty() == 1) {
                    cout << "NO" << "\n";
                    C = 1;
                    break;
                }
                v.pop_back();
            }
            else {
                v.push_back(1);
            }
        }
        if (C != 1 && v.empty() == 1)
            cout << "YES" << "\n";
        else if (C != 1)
            cout << "NO" << "\n";
    }
}