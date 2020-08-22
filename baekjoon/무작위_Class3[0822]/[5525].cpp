#include <iostream>
#include <vector>
using namespace std;
int N, M;
vector<int> v;
int main() {//IOIOI
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    N = 2 * N + 1;
    string S;
    cin >> S;
    int cnt = 0;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == 'I') {
            if (cnt != 0) {
                if (cnt % 2 == 0)
                    cnt++;
                else {
                    if (cnt >= N) {
                        v.push_back(cnt);
                    }
                    cnt = 1;//cnt 이어나가는 case 외에 모두 cnt 초기화해야함 단 I일때는 1로 초기화
                }
            }
            else cnt = 1;
        }
        else if (S[i] == 'O') {
            if (cnt != 0) {
                if (cnt % 2 != 0) {
                    cnt++;
                }
                else if (cnt >= N) {
                    v.push_back(cnt);
                    cnt = 0;//cnt 이어나가는 case 외에 모두 cnt 초기화해야함
                }
                else cnt = 0;
            }
        }
    }
    if (cnt != 0 && cnt >= N) {
        v.push_back(cnt);
    }
    int result = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == N) result++;
        else if (v[i] > N) {
            result +=(v[i] - N) / 2 + 1;
        }
    }
    cout << result << '\n';
    return 0;
}