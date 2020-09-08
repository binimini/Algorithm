#include <iostream>
#include <queue>
using namespace std;
pair<int,int> arr[1000001];
queue<int> q;
int N;
void BFS() {
    while (!q.empty()) {
        int x = q.front();
        if (x == N)
            return;
        q.pop();
        int nx = x + 1;
        if (nx <= 1000000 && !arr[nx].first) { 
            arr[nx].first = arr[x].first + 1;
            arr[nx].second = 1;
            if (nx == N)
                return;
            q.push(nx);
        }
        nx = x * 2;
        if (nx <= 1000000 && !arr[nx].first) {
            arr[nx].first = arr[x].first + 1;
            arr[nx].second = 2;
            q.push(nx);
            if (nx == N)
                return;
        }
        nx = x * 3;
        if (nx <= 1000000 && !arr[nx].first) {
            arr[nx].first = arr[x].first + 1;
            arr[nx].second = 3;
            if (nx == N)
                return;
            q.push(nx);
        }
    }
}
int main() {
    cin >> N;
    arr[1].first = 1;
    arr[1].second = -1;
    q.push(1);
    BFS();
    int temp, x = N;
    cout << arr[N].first-1 << "\n";
    temp = arr[N].second;
    cout << N << ' ';
    while (temp != -1) {
        if (temp == 1) {
            x = x - 1;
        }
        else if (temp == 2) {
            x = x / 2;
        }
        else if (temp == 3) {
            x = x / 3;
        }
        cout << x << ' ';
        temp = arr[x].second; 
    }
    cout << '\n';
    return 0;
}