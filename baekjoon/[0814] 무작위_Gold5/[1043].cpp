#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define FOR(i,a,b) for(int i = a; i<b; i++)
int N, M, T;
vector<int> t_people;
vector<int> p_info[50];
vector<int>pp_info[51];
bool party[50] = { 0 }, people[51] = { 0 };

int main() {//거짓말
    cin >> N >> M;
    cin >> T;
    int temp;
    FOR(i, 0, T) {
        cin >> temp;
        t_people.push_back(temp);
    }
    FOR(i, 0, M) {
        cin >> temp;
        int t;
        FOR(j, 0, temp) {
            cin >> t;
            p_info[i].push_back(t);
            pp_info[t].push_back(i);
        }
    }
    queue<int> q;
    FOR(i, 0, t_people.size()) {
        q.push(t_people[i]);
    }
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        people[x] = 1;
        FOR(i, 0, pp_info[x].size()) {
            if (party[pp_info[x][i]] == 1) continue;
            party[pp_info[x][i]] = 1;
            FOR(j, 0, p_info[pp_info[x][i]].size()) {
                if (people[p_info[pp_info[x][i]][j]] == 1) continue;
                q.push(p_info[pp_info[x][i]][j]);
            }
        }
    }
    int cnt = 0;
    FOR(i, 0, M) {
        if (party[i] == 0) cnt++;
    }
    cout << cnt;
    return 0;
}