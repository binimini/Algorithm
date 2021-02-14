#include <bits/stdc++.h>
using namespace std;
int N, dp[51][500001], h[51];
int main() {
    //dp[i][j] = i번째까지의 블럭(쓸수있는 범위가) h1>h2일 떄 h1-h2=j 에서 최대 h1 값
    //dp[N][0] -> N번째까지의 블럭으로 h1-h2=0 즉 h1=h2일떄 최대 h1 값
    //문제에서 원하는 바를 메모리 제한 내에 배열로 표현할수 있게 생각 해보고 // 점화식 상황에 따라 구해내는 방식????
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> h[i];
    }
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= 500000; j++) {
            //i번째 블록 사용X
            if (dp[i - 1][j] != -1)
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            //h2에 블록 사용해 차이 줄이는 경우
            if (dp[i - 1][j + h[i]] != -1)
                dp[i][j] = max(dp[i][j], dp[i - 1][j + h[i]]);
            //h1에 블록 사용하는 경우
            if (h[i] <= j) {//사용 블록보다 차이가 크면 -> 차이가 늘어나고 높이도 늘어난다
                if (dp[i - 1][j - h[i]] != -1) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - h[i]] + h[i]);
                }
            }
            else if (h[i] > j) {//사용 블록이 차이보다 크면 -> dp[i][j]에서의 h2가 h1이었던 차이가 h[i]-j인 최대 높이에 j를 더한다
                //dp[i-1][h[i]-j](과거h1==현재h2) - (h[i]-j)(차이, 과거h2==현재h1의 과거 높이)  + h[i](현재 h1 높이)
                if (dp[i - 1][h[i] - j] != -1) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][h[i] - j] + j);
                }
            }
        }
    }

    if (dp[N][0] <= 0)//0(<-dp[0][0])이거나 최고높이 있거나
        cout << -1;
    else
        cout << dp[N][0];
    return 0;
}