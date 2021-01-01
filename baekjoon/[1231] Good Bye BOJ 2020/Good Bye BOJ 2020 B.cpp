#include <bits/stdc++.h>
using namespace  std;
string mbti[16] = { "ISTJ", "ISFJ", "INFJ", "INTJ", "ISTP", "ISFP", "INFP", "INTP", "ESTP", "ESFP", "ENFP", "ENTP", "ESTJ", "ESFJ", "ENFJ", "ENTJ" };
int c[16][16][16], arr[3], T, N;
int have[16] = { 0 };
priority_queue<pair<int, vector<int>>> pq, temp_pq;
int calcu(string a, string b) {
    int res = 0;
    for (int i = 0; i < 4; i++) {
        if (a[i] != b[i])
            res++;
    }
    return res;
}
void dfs(int node, int cnt) {
    if (cnt == 3) {
        c[arr[0]][arr[1]][arr[2]] = calcu(mbti[arr[0]], mbti[arr[1]]) + calcu(mbti[arr[1]], mbti[arr[2]]) + calcu(mbti[arr[0]], mbti[arr[2]]);
        return;
    }
    for (int i = node; i < 16; i++) {
        arr[cnt] = i;
        dfs(i, cnt + 1);
    }
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(c, -1, sizeof(c));
    dfs(0,0);
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            for (int k = 0; k < 16; k++) {
                if (c[i][j][k] != -1) {
                    vector<int> v;
                    v.push_back(i);
                    v.push_back(j);
                    v.push_back(k);
                    pq.push({ -c[i][j][k], v });
                }
            }
        }
    }
    cin >> T;
    for (int t = 0; t < T; t++) {
        temp_pq = pq;
        cin >> N;
        string m;
        for (int i = 0; i < 16; i++)
            have[i] = 0;
        for (int i = 0; i < N; i++) {
            cin >> m;
            for (int j = 0; j < 16; j++) {
                if (m == mbti[j]) {
                    have[j]++;
                    break;
                }
            }
            
        }
        while (!temp_pq.empty()) {
            int ori_i, ori_j, ori_k;
            ori_i = have[temp_pq.top().second[0]];
            ori_j = have[temp_pq.top().second[1]];
            ori_k = have[temp_pq.top().second[2]];
            have[temp_pq.top().second[0]]--, have[temp_pq.top().second[1]]--, have[temp_pq.top().second[2]]--;
            if (have[temp_pq.top().second[0]]>=0&& have[temp_pq.top().second[1]]>=0&& have[temp_pq.top().second[2]]>=0){
                cout << -temp_pq.top().first << "\n";
                break;
            }
            else {
                have[temp_pq.top().second[0]] = ori_i;
                have[temp_pq.top().second[1]] = ori_j;
                have[temp_pq.top().second[2]] = ori_k;
                temp_pq.pop();
            }
        }
    }
    return 0;
}