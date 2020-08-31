#include <iostream>
#include <queue>
using namespace std;
int N, K, cnt = 1;
queue<int> q;
int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        q.push(i + 1);
    }
    cout << "<";
    while (q.empty() != 1) {
        if (q.size() == 1) {
            cout << q.front();
            q.pop();
        }
        else {
            if (cnt == K) {
                cout << q.front() << ", ";
                q.pop();
                cnt = 1;
            }
            else {
                int temp1 = q.front();
                q.pop();
                q.push(temp1);
                cnt++;
            }
        }
    }
    cout << ">\n";
    return 0;
}