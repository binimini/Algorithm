#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int N, C, M, res = 0;
vector<pair<int, int>> v[2001];// v[from] = {{to, boxcnt},..}
vector<pair<int, int>> tmp;
int arr[2001] = { 0 };//현재 트럭 pq - 앞 뒤로 빼기 힘듬, dq - 목적지 순으로 정렬 힘듬
int main() {
    FASTIO;
    cin >> N >> C >> M;
    int f, t, c;//from, to, count
    for (int i = 0; i < M; i++) {
        cin >> f >> t >> c;
        v[f].push_back(make_pair(t, c));
    }
    int cnt = 0, temp;
    bool flag = 0;
    for (int i = 1; i <= N; i++) {
        sort(v[i].begin(), v[i].end());
        //빼기
        res += arr[i];
        cnt -= arr[i];
        arr[i] = 0;

        //넣기
        for (int j = 0; j < v[i].size(); j++) {
            if (cnt+v[i][j].second<=C) {//용량 내
                arr[v[i][j].first] += v[i][j].second;
                cnt += v[i][j].second;
            }
            else {//용량 밖
                temp = v[i][j].second - (C - cnt);//못 넣은 상자 수
                for (int k = N; k > v[i][j].first; k--) {
                    if (temp == 0)
                        break;
                    if (arr[k]) {
                        int temp2 = min(temp, arr[k]);//temp2 사용 안하면 -=로 더 작아져서 결과값 이상해짐
                        temp -= temp2;
                        arr[k] -= temp2;//바꾸기
                    }
                }
                arr[v[i][j].first] += v[i][j].second - temp;
                cnt = C;//용량 밖이므로 무조건 최대 용량
            }
        }
    }
    cout << res;
    return 0;
}