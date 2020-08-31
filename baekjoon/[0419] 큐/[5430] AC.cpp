#include <iostream>
#include <deque>
using namespace std;
int T, N, n, arr[100000], head;
deque<int> q;
string comm, temp;
void R() {
    head *= -1;
}
bool D() {
    if (q.empty() == 1)
        return true;
    else {
        if (head == 1)
            q.pop_front();
        else {
            q.pop_back();
        }
    }
    return false;
}
int main() {
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    cin >> T;
    for (int i = 0; i < T; i++) {
        deque<int> t;
        q = t;
        cin >> comm >> N >> temp;
        int x = 0, y = 0, num = 0, check = 0;
        head = 1;
        while (1) {
            if (temp[x] == ']') {
                if (num != 0)
                    q.push_back(num);
                break;
            }
            if (temp[x] == ',') {
                if (num != 0)
                    q.push_back(num);
                y = 0, num = 0;
            }
            if (temp[x] <= 57 && temp[x] >= 48) {
                num = (temp[x] - '0') + num * 10;
                y++;
            }
            x++;
        }
        for (int k = 0; k < comm.size(); k++) {
            if (comm[k] == 'D') {
                if (D()) {
                    check = 1;
                    break;
                }
            }
            else
                R();
        }
        if (check)
            cout << "error" << "\n";
        else {
            cout << "[";
            if (q.empty() != 1) {
                int sz = q.size();
                if (head == 1) {
                    for (int i = 0; i < sz - 1; i++) {
                        cout << q.front() << ",";
                        q.pop_front();
                    }
                    cout << q.front();
                }
                else {
                    for (int i = 0; i < sz - 1; i++) {
                        cout << q.back() << ",";
                        q.pop_back();
                    }
                    cout << q.back();
                }
            }
            cout << "]" << "\n";
        }
    }
}