#include <bits/stdc++.h>
using namespace std;
int N, INF;
vector<int> even, odd;
bool visited[51] = { 0 }, not_prime[2001] = { 0 }, flag;
int sumby[51] = { 0 };
vector<int> can_sum[51];
bool dfs(int me) {
    if (visited[me]) return 0;
    visited[me] = 1;
    for (int i = 0; i < can_sum[me].size(); i++) {
        int target = can_sum[me][i];
        if (target == INF) continue;
        if (sumby[target] == 0 || dfs(sumby[target])) {
            sumby[target] = me;
            return 1;
        }
    }
    return 0;
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    even.push_back(0);
    odd.push_back(0);
    int temp;
    for (int i = 1; i <= N; i++) {
        cin >> temp;
        if (temp % 2 == 0)
            even.push_back(temp);
        else if (temp % 2 == 1)
            odd.push_back(temp);
        if (i == 1)
            (temp % 2==0) ? flag = 0 : flag = 1;
    }
    not_prime[1] = 1;
    for (int i = 2; i*i <= 2000; i++) {
        if (!not_prime[i]) {
            for (int j = 2 * i; j <= 2000; j += i) {
                not_prime[j] = 1;
            }
        }
    }
    for (int i = 1; i <even.size(); i++) {
        for (int j = 1; j <odd.size(); j++) {
            if (!not_prime[even[i] + odd[j]]) {
                if (flag)
                    can_sum[j].push_back(i);
                else
                    can_sum[i].push_back(j);
            }
        }
    }
    vector<int> result;
    for (int x = 0; x < can_sum[1].size(); x++) {
        int res = 0;
        INF = can_sum[1][x];
        res++;
        int r_size = flag ? even.size() : odd.size();
        int size = flag ? odd.size() : even.size();
        for (int i = 1; i < r_size; i++) {
            sumby[i] = 0;
        }
        for (int i = 2; i < size; i++) {
            for (int j = 1; j < size; j++)
                visited[j] = 0;
            if (dfs(i))
                res++;
        }
        if (res == N / 2)
            (flag) ? result.push_back(even[INF]) : result.push_back(odd[INF]);
    }
    sort(result.begin(), result.end());
    for (int i = 0; i < result.size(); i++) {
        cout << result[i]<<" ";
    }
    if (result.empty())
        cout << -1;

    return 0;
}