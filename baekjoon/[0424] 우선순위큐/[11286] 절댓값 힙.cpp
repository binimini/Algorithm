#include <iostream>
#include <math.h>
#include <queue>
using namespace std;
int N;
struct cmp {
    bool operator()(int a, int b) {
        if (abs(a) > abs(b))
            return true;
        else if (abs(a) == abs(b))
            if (a > b)
                return true;
            else
                return false;
        return false;
    }

};
int main() {
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    cin >> N;
    priority_queue<int, vector<int>, cmp> pq;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        if (temp == 0) {
            if (pq.empty() == 1)
                cout << 0 << "\n";
            else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else {
            pq.push(temp);
        }
    }
    return 0;
}