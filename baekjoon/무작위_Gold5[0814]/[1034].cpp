#include <iostream>
#include <algorithm>
using namespace std;
#define FOR(x,a,b) for (int x = a; x<b; x++)

int N, M,K, arr[50][50];
pair<int, int> info[50];

int main() {//램프
    cin >> N >> M;

    char temp;
    FOR(i, 0, N) {
        info[i].first = 0, info[i].second = 1;
        FOR(j, 0, M) {
            cin >> temp;
            arr[i][j] = temp - '0';
            if (arr[i][j] == 0)
                info[i].first++;
        }
    }
    cin >> K;
    
    FOR(i, 0, N) {
        if (info[i].first == -1) continue;
        FOR(j, i+1, N) {
            if (info[j].first == -1) continue;
            int CH = 1;
            FOR(k, 0, M) {
                if (arr[i][k] != arr[j][k]) {
                    CH = 0;
                    break;
                }
            }
    
            if (CH) {
                info[i].second++;
                info[j].first = -1;
            }
        }
    }
    int result = 0;
    for (int i = 0; i < N; i++) {
        if (info[i].first == -1) continue;
     
        if ((K - info[i].first) % 2 == 0 && info[i].first <= K)
            result = max(result, info[i].second);
    }
    cout << result;
    return 0;
}