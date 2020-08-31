#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int T, N, ch_num;
queue<pair<int, int>> Q;
bool check_pri(pair<int, int>a) {
    int check = 1;
    for (int i = 0; i < Q.size(); i++) {
        if (Q.front().second > a.second)
            check = 0;
        pair<int, int> temp;
        temp = Q.front();
        Q.pop();
        Q.push(temp);
    }
    if (check == 0)
        return false;
    else
        return true;
}
int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        queue<pair<int, int>> a;
        Q = a;
        int cnt = 1;
        cin >> N >> ch_num;
        for (int k = 0; k < N; k++) {
            int temp;
            cin >> temp;
            Q.push(make_pair(k, temp));
        }
        while (1) {
            if (check_pri(Q.front())) {
                if (Q.front().first == ch_num) {
                    cout << cnt << "\n";
                    break;
                }
                else {
                    cnt++;
                    Q.pop();
                }
            }
            else {
                pair<int, int> temp = Q.front();
                Q.pop();
                Q.push(temp);
            }
        }
    }
    return 0;
}