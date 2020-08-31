#include <iostream>
#include <vector>
using namespace std;
int N;
int main() {
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    vector<int> v;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string comm;
        cin >> comm;
        if (comm == "push") {
            int temp;
            cin >> temp;
            v.push_back(temp);
        }
        else if (comm == "pop") {
            if (v.empty() == 1)
                cout << -1 << "\n";
            else {
                cout << v.back() << "\n";
                v.pop_back();
            }
        }
        else if (comm == "size") {
            cout << v.size() << "\n";
        }
        else if (comm == "empty") {
            cout << v.empty() << '\n';
        }
        else if (comm == "top") {
            if (v.empty() == 1)
                cout << -1 << "\n";
            else
                cout << v.back() << "\n";
        }
    }
    return 0;
}