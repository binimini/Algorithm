#include <bits/stdc++.h>
using namespace std;
int N, arr[1001];
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main() {
    FASTIO;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    int sum = 0;
    for (int i = 0; i < N; i++) {
        //if sum <= X(==arr[i]), 0-sum -> 0-sum+X 까지 만들 수 있다.
        //if sum+1 == X, X = sum+1 -> 0-sum+X.
        //if sum+1 < X , sum+1 만들기 불가능!!          -> (sum+1<=X) or (sum+1<X)
        if (sum + 1 < arr[i]) {
            break;//여기서 출력 시 arr[N-1]까지 다 만들수있는 경우 출력 안하게됨!!!
        }
        else if (sum + 1 >= arr[i])
            sum += arr[i];
    }
    cout << sum + 1;//모든 케이스 처리할 수 있는 범위에서 출력
    return 0;
}