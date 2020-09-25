#include <bits/stdc++.h>
using namespace std;
queue<int> q;
int T, A, B;
bool not_prime[10000] = { 0 };
int minimum[10000] = { 0 };
vector<int> prime[10000];
void BFS() {
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (x == B) {
            while (!q.empty())
                q.pop();
            return;
        }
        for (unsigned int i = 0; i < prime[x].size(); i++) {
            if (minimum[prime[x][i]]) continue;
            minimum[prime[x][i]] = minimum[x] + 1;
            if (prime[x][i] == B) {
                while (!q.empty())
                    q.pop();
                return;
            }
            q.push(prime[x][i]);
        }
    }
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    not_prime[1] = 1;
    for (int i = 2; i <= 9999; i++) {
        if (not_prime[i]) continue;
        for (int j = 2 * i; j <= 9999; j += i) {
            not_prime[j] = 1;
        }
    }
    for (int i = 1000; i <= 9999; i++) {
        if (!not_prime[i]) {
            for (int x = 0; x < 4; x++) {//x번째 자리 대신 y로 변경
                for (int y = 0; y <= 9; y++) {//단 0은 맨 첫 번째 자리로 안됌
                    if (x == 3 && y == 0) continue;
                    int temp = y* int(pow(10, x)) + i % int(pow(10, x)) + (i/ int(pow(10, x + 1))) * int(pow(10, x + 1));
                    if (temp == i) continue;
                    if (!not_prime[temp]) {
                        prime[i].push_back(temp);
                    }
                }
            }
        }
    }
    cin >> T;
    for (int t = 0; t < T; t++) {
        for (int i = 1000; i <= 9999; i++) {
            minimum[i] = 0;
        }
        cin >> A >> B;
        minimum[A] = 1;
        q.push(A);
        BFS();
        if (minimum[B] != 0)
            cout << minimum[B]-1 << '\n';
        else
            cout << "Impossible\n";
    }
    return 0;
}