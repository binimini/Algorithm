#include <iostream>
#include <vector>
using namespace std;
int N;
long long int D_cnt = 0, G_cnt = 0;
vector<int> child[300001];
pair<int, int> edge[300000];
int main() {
    cin >> N;
    int a, b;
    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b;
        child[a].push_back(b);
        child[b].push_back(a);
        edge[i].first = a, edge[i].second = b;
    }
    int temp;
    for (int i = 1; i <= N; i++) {
        temp = child[i].size();
        if (temp >= 3) {
            G_cnt = G_cnt + (temp * (temp - 1) * (temp - 2) / 6);
        }
    }
    long long int mult;
    for (int i = 0; i < N - 1; i++) {
        mult = child[edge[i].first].size() - 1;
        mult *= child[edge[i].second].size() - 1;
        D_cnt += mult;
    }
    if (D_cnt > G_cnt * 3)
        cout << "D";
    else if (D_cnt < G_cnt * 3)
        cout << "G";
    else if (D_cnt == G_cnt * 3)
        cout << "DUDUDUNGA";
    return 0;
}