#include <iostream>
#include <algorithm>
using namespace std;
int N, S;
int arr[100000];
int main() {//부분합
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    int start = 0, end = 0, sum = arr[0], cnt = N+1;
    while (start < N) {//투포인터
        if (sum >= S) {//최소길이 갱신
            cnt = min(end - start + 1, cnt);
        }
        if (sum > S || end == N - 1) {//합이 S보다 크거나 e가 끝에 도달한경우
            sum -= arr[start];
            start++;//s++
        }
        else {
            end++;//e++
            sum += arr[end];
        }
    }
    if (cnt == N + 1)
        cout << 0;
    else
        cout << cnt;
    return 0;
}