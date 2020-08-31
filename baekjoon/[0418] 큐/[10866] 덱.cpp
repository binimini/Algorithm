#include <iostream>
#include <deque>
using namespace std;
int N;
int main() {
    cin >> N;
    deque<int> dq;
    for (int i = 0; i < N; i++) {
        string comm;
        cin >> comm;
        if (comm == "push_front") {
            int X;
            cin >> X;
            dq.push_front(X);
        }
        else if (comm == "push_back") {
            int X;
            cin >> X;
            dq.push_back(X);
        }
        else if (comm == "pop_front") {
            if (dq.empty() == 1)
                cout << -1 << "\n";
            else {
                cout << dq.front() << "\n";
                dq.pop_front();
            }
        }
        else if (comm == "pop_back") {
            if (dq.empty() == 1)
                cout << -1 << "\n";
            else {
                cout << dq.back() << "\n";
                dq.pop_back();
            }
        }
        else if (comm == "size") {
            cout << dq.size() << "\n";
        }
        else if (comm == "front") {
            if (dq.empty() == 1)
                cout << -1 << "\n";
            else
                cout << dq.front() << "\n";
        }
        else if (comm == "back") {
            if (dq.empty() == 1)
                cout << -1 << "\n";
            else
                cout << dq.back() << "\n";
        }
        else
            cout << dq.empty() << "\n";
    }
    return 0;
}