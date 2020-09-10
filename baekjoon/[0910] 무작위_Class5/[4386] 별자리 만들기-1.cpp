#include <iostream>
#include <math.h>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;
int N, cnt = 0;
double R;
int u[101] = { 0 };
pair<double, double> info[101];
vector<tuple<double, int, int>> v;
int find_u(int x) {
    if (u[x] == x)
        return x;
    return u[x] = find_u(u[x]);
}
bool same_u(int x, int y) {
    x = find_u(x);
    y = find_u(y);
    return x == y;
}
void uni(int x, int y) {
    x = find_u(x);
    y = find_u(y);
    if (x < y)
        u[y] = x;
    else
        u[x] = y;
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        u[i] = i;
    }
    for (int i = 1; i <= N; i++)
        cin >> info[i].first >> info[i].second;
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            double temp = sqrt(pow((info[i].first - info[j].first), 2) + pow((info[i].second - info[j].second), 2));
            v.push_back(make_tuple(temp, i, j));
        }
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        if (cnt == N - 1)
            break;
        if (!same_u(get<1>(v[i]), get<2>(v[i]))) {
            R += get<0>(v[i]);
            cnt++;
            uni(get<1>(v[i]), get<2>(v[i]));
        }
    }
    cout << R << '\n';
    return 0;
}