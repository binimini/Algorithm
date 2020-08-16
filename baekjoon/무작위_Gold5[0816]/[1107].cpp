#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int N, M, INF = 987654321;
bool broken[10] = { 0 };
int main() {//리모컨
    cin >> N >> M;
    int temp;
    for (int i = 0; i < M; i++) {
        cin >> temp;
        broken[temp] = 1;
    }
    int case1 = abs(N - 100);
    int case2 = INF;
    for (int i = 0; i < 1000000; i++) {
        int temp_i = i, cnt = 0;
        bool CH = 0;
        while (temp_i != 0) {
            cnt++;
            if (broken[temp_i % 10] == 1) { 
                CH = 1;
                break;
            }
            temp_i /= 10;
        }
        if (i == 0) {
            if (broken[0] == 1)
                CH = 1;
            cnt = 1;
        }
        if (CH == 0) {
            case2 = min(abs(N - i) + cnt, case2);
        }
    }
    cout << min(case1, case2);
    return 0;
}