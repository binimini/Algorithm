#include <iostream>
#include <queue>
using namespace std;
int N;
int main() {
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    queue<int> q;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string comm;
        cin >> comm;
        if (comm == "push") {
            int temp;
            cin >> temp;
            q.push(temp);
        }
        else if (comm == "pop") {
            if (q.empty() == 1)
                cout << -1 << "\n";
            else {
                cout << q.front() << "\n";
                q.pop();
            }
        }
        else if (comm == "size") {
            cout << q.size() << "\n";
        }
        else if (comm == "empty") {
            cout << q.empty() << '\n';
        }
        else if (comm == "front") {
            if (q.empty() == 1)
                cout << -1 << "\n";
            else
                cout << q.front() << "\n";
        }
        else if (comm == "back") {
            if (q.empty() == 1)
                cout << -1 << "\n";
            else
                cout << q.back() << "\n";
        }
    }
    return 0;
}