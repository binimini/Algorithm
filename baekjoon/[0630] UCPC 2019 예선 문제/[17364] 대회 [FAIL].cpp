#include <iostream>
#include <algorithm>
using namespace std;
int CNT, N, K, arr[100000] = { 0 }, visited[100000] = { 0 };
pair<int, int> contest_info[100000];
void cant_p() {
    int end = 0;
    for (int i = 0; i < N; i++) {
        if (visited[i]) {
            end = contest_info[i].second;
        }
        else {
            if (end >= contest_info[i].first)
                visited[i] = 1;
        }
    }
}
void DFS(int end, int cnt) {
    if (cnt == CNT) {
        for (int i = 0; i < N; i++) {
            visited[i] = 0;
        }
        for (int i = 0; i < cnt; i++) {
            visited[arr[i]] = 1;
        }
        cant_p();
        int e = 0;
        for (int j = 0; j < K - 1; j++) {
            for (int k = 0; k < N; k++) {
                if (visited[k]) continue;
                if (e >= contest_info[k].first) continue;
                visited[k] = 1;
                e = contest_info[k].second;
            }
        }
        for (int i = 0; i < N; i++) {
            if (visited[i] != 1) return;
        }
        cout << cnt << '\n';
        exit(100);
    }
    for (int i = 0; i < N; i++) {
        if (end >= contest_info[i].first) continue;
        arr[cnt] = i;
        DFS(contest_info[i].second, cnt + 1);
    }
}
int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int s, e;
        cin >> s >> e;
        contest_info[i].first = s;
        contest_info[i].second = e;
    }
    sort(contest_info, contest_info + N);
    for (int i = 0; i <= N; i++) {
        CNT = i;
        DFS(0, 0);
    }
    return 0;
}