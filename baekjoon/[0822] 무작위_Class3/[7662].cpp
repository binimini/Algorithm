#include <iostream>
#include <map>
using namespace std;
int T, K;
map<int, int> m;//삽입 삭제 탐색 O(logN) 
//deq 앞 뒤 아닌 곳에 삽입하는 경우 성능 떨어짐(O(N)?)
int main() {//이중 우선순위 큐
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> K;
        m.clear();//전역변수로 선언했으므로 테케마다 초기화해야함
        char o;
        int n;
        for (int i = 0; i < K; i++) {
            cin >> o >> n;
            if (o == 'I') {
                if (m.empty())
                    m.insert(make_pair(n, 1));
                else if (m.find(n) == m.end()) {
                    m.insert(make_pair(n,1));
                }
                else {
                    m.find(n)->second++;
                }
            }
            else if (o == 'D') {
                if (m.empty()) continue;
                if (n == 1) {
                    if (m.rbegin()->second != 1) {
                        m.rbegin()->second--;
                    }
                    else m.erase(--m.end());
                }
                else if (n == -1) {
                    if (m.begin()->second != 1) {
                        m.begin()->second--;
                    }
                    else m.erase(m.begin());
                }
            }
        }
        if (m.empty()) cout << "EMPTY" << '\n';
        else {
            cout << m.rbegin()->first << " " << m.begin()->first << "\n";
        }
    }
    return 0;
}