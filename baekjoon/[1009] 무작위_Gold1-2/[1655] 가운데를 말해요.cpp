#include <iostream>
#include <queue>
using namespace std;
int N, middle = 10001;
priority_queue<int> g;
priority_queue<int> l;
int check(int i) {
    if (i % 2 == 0) {
        if (l.size() + 1 == g.size())
            return 1;
        else if (l.size() + 1 > g.size())
            return 0;
        else if (l.size() + 1 < g.size())
            return -1;
    }
    else {
        if (l.size() == g.size())
            return 1;
        else if (l.size() > g.size())
            return 0;
        else if (l.size() < g.size())
            return -1;
    }

}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    int temp;
    for (int i = 1; i <= N; i++) {
        cin >> temp;
        if (middle == 10001)
            middle = temp;
        else {
            if (temp == middle) {
                if (g.size() <= l.size())
                    g.push(-temp);
                else
                    l.push(temp);
            }
            else if (temp > middle)
                g.push(-temp);
            else
                l.push(temp);
            int flag = check(i);
            if (flag == 0) {
                g.push(-middle);
                middle = l.top();
                l.pop();
            }
            else if (flag == -1) {
                l.push(middle);
                middle = -g.top();
                g.pop();
            }
        }
        cout << middle << "\n";
    }
    return 0;
}