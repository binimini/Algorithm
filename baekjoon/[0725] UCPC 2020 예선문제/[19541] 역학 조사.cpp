#include <iostream>
#include <vector>
using namespace std;
int N, M;
int result[100001];
pair<int, int> info[100001];
vector<int> meeting[100000];
//비트마스크 개념 이용해서
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    int temp, temp2;
    for (int i = 0; i < M; i++) {
        cin >> temp;
        for (int j = 0; j < temp; j++) {
            cin >> temp2;
            meeting[i].push_back(temp2);
        }
    }
    for (int i = 1; i <= N; i++) {
        cin >> info[i].second;
        info[i].first = info[i].second;//first 변함 second 고정
    }
    int CH = 0;
    for (int i = M - 1; i >= 0; i--) {
        CH = 0;
        for (int j = 0; j < meeting[i].size(); j++) {
            if (info[meeting[i][j]].first ^ 1)//XOR 1과다를때==0일때
                CH = 1;
        }
        if (CH == 1) {
            for (int j = 0; j < meeting[i].size(); j++) {
                info[meeting[i][j]].first &= 0;//0으로
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        result[i] = info[i].first;
    }
    for (int i = 0; i < M; i++) {
        CH = 0;
        for (int j = 0; j < meeting[i].size(); j++) {
            if (info[meeting[i][j]].first & 1)//1일때
                CH = 1;
        }
        if (CH == 1) {
            for (int j = 0; j < meeting[i].size(); j++) {
                info[meeting[i][j]].first |= 1; //1으로
            }
        }
    }
    CH = 0;
    for (int i = 1; i <= N; i++) {
        if (info[i].first ^ info[i].second) {//두 비트가 다를 때
            CH = 1;
            break;
        }
    }
    if (CH == 1)
        cout << "NO";
    else if (CH == 0) {
        cout << "YES" << "\n";
        for (int i = 1; i <= N; i++) {
            cout << result[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}