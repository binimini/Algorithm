#include <iostream>
#include <queue>
#include <string>
using namespace std;
int T, A, B;
int visited[10000] = { 0 };
queue<pair<int,string>> q;
void BFS() {
    while (!q.empty()) {
        int x = q.front().first;
        string xs = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx;
            string nxs = xs;
            if (i == 0) {
                nx = (x * 2) % 10000;
                nxs += 'D';
            }
            else if (i == 1) {
                nx = x;
                if (nx == 0)//문제 제대로 읽기
                    nx = 9999;
                else
                    nx -= 1;
                nxs += 'S';
            }
            else if (i == 2) {//for문, pow 쓰지않고 됌
                nx = x % 1000;
                nx *= 10;
                nx += x / 1000;
                nxs += 'L';
            }
            else if (i == 3) {
                nx = x / 10;
                nx += (x % 10) * 1000;
                nxs += 'R';
            }
            if (nx < 0 || nx>9999) continue;
            if (visited[nx]) continue;
            if (nx == B) {//q에넣으면서체크
                cout << nxs << "\n";//문자열로 출력
                while (!q.empty()) {
                    q.pop();
                }
                return;
            }
            visited[nx] = visited[x] + 1;
            q.push(make_pair(nx, nxs));
            
        }

    }
}
int main() {//DSLR
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    string s = "";//+로 횟수에 맞게 늘릴 것
    for (int t = 0; t < T; t++) {
        cin >> A >> B;
        for (int i = 0; i < 10000; i++) {//visited 테스트케이스마다 초기화
            visited[i] = 0;
        }
        q.push(make_pair(A,s));
        visited[A] = 1;
        BFS();
    }
    return 0;
}