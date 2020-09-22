#include <bits/stdc++.h>
using namespace std;
struct INFO {
    int x;
    int y;
};
int N;
INFO info[100000];

int ccw(INFO a,INFO b, INFO c) {
    long long int CCW = ((long long int)a.x * b.y + (long long int)b.x * c.y + (long long int)c.x * a.y);
    CCW -= ((long long int)a.y * b.x + (long long int)b.y * c.x + (long long int)c.y * a.x);
    if (CCW == 0)
        return 0;
    else if (CCW < 0)
        return -1;
    else if (CCW > 0)
        return 1;
}
bool cmp(INFO a, INFO b) {
    int CCW = ccw(info[0], a, b);
    if (CCW == 0) {
        if (a.x == b.x)
            return a.y < b.y;
        else
            return a.x < b.x;
    }
    return CCW > 0;
}

int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    int m = 0;
    for (int i = 0; i < N; i++) {
        cin >> info[i].x >> info[i].y;
        if (info[i].x < info[m].x) {
            m = i;
        }
        else if (info[i].x == info[m].x && info[i].y < info[m].y) {
            m = i;
        }
    }
    
    INFO temp;
    temp.x = info[0].x, temp.y = info[0].y;
    info[0].x = info[m].x, info[0].y = info[m].y;
    info[m].x = temp.x, info[m].y = temp.y;
    
    sort(info + 1, info + N, cmp);
    stack<int> s;
    s.push(0);
    s.push(1);
    int next = 2;
    while (next < N) {
        while (s.size() >= 2) {
            int first, second;
            second = s.top();
            s.pop();
            first = s.top();
            if (ccw(info[first], info[second], info[next]) > 0) {
                s.push(second);
                break;
            }
        }
        s.push(next);
        next++;
    }
    cout << s.size() << "\n";
    return 0;
}