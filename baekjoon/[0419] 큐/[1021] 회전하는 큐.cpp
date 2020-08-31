#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int N, M, arr[51], sum = 0;
queue<int> q, temp;
int left(int num) {
    int cnt = 0;
    while (num != temp.front()) {
        temp.push(temp.front());
        temp.pop();
        cnt++;
    }
    temp.pop();
    return cnt;
}
int right(int num) {
    int cnt = 0;
    while (num != q.front()) {
        for (int i = 0; i < q.size() - 1; i++) {
            q.push(q.front());
            q.pop();
        }
        cnt++;
    }
    q.pop();
    return cnt;
}
int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        q.push(i);
    }
    for (int i = 1; i <= M; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i <= M; i++) {
        temp = q;
        sum += min(right(arr[i]), left(arr[i]));
    }
    cout << sum << '\n';
    return 0;
}