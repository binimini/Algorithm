#include <iostream>
#include <map>
using namespace std;
int N, M;
map<string, string> m;
int main() {//비밀번호 찾기
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    string site, password;
    for (int i = 0; i < N; i++) {
        cin >> site >> password;
        m.insert(make_pair(site, password));
    }
    for (int i = 0; i < M; i++) {
        cin >> site;
        cout << m.find(site)->second << "\n";
    }
    return 0;
}