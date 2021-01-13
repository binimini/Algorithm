#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int T, N;
map<string, int > MapOfKind;
int main() {
    FASTIO;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N;
        MapOfKind.clear();
        string name, kind;
        for (int i = 0; i < N; i++) {
            cin >> name >> kind;
            if (MapOfKind.find(kind) != MapOfKind.end())
                MapOfKind[kind]++;
            else
                MapOfKind[kind] = 1;
        }
        int res = 1;//30개를 잘 쪼개 곱해도 21억 넘을 수 없음
        for (auto iter = MapOfKind.begin(); iter != MapOfKind.end(); iter++) {
            res *= (iter->second + 1);
        }
        cout << res - 1<<"\n";//N==0일때 예외처리 안해도 1-1은 0
    }
    return 0;
}