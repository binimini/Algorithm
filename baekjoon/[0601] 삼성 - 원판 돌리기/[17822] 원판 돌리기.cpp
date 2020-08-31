#include <iostream>
#include <deque>
using namespace std;
int N, M, T, check_deq[51][50] = { 0 };
deque<int> deq[51];
void move(int x, int d, int k) {
    if (d == 0) {
        for (int i = 0; i < k; i++) {
            deq[x].push_front(deq[x].back());
            deq[x].pop_back();
        }
    }
    else {
        for (int i = 0; i < k; i++) {
            deq[x].push_back(deq[x].front());
            deq[x].pop_front();
        }
    }
}
void check() {
    int check = 0, check_sum = 0, check_divide = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            int check_temp = 0;
            if (!deq[i][j]) continue;
            else check_sum += deq[i][j], check_divide++;
            if (j == 0) {
                if (deq[i][M - 1] == deq[i][j]) check_temp = 1, check_deq[i][M - 1] = 1;
            }
            else {
                if (deq[i][j] == deq[i][j - 1]) check_temp = 1, check_deq[i][j - 1] = 1;
            }
            if (j == M - 1) {
                if (deq[i][0] == deq[i][j]) check_temp = 1, check_deq[i][0] = 1;
            }
            else {
                if (deq[i][j] == deq[i][j + 1]) check_temp = 1, check_deq[i][j + 1] = 1;
            }
            if (i != N) {
                if (deq[i + 1][j] == deq[i][j]) check_temp = 1, check_deq[i + 1][j] = 1;
            }
            if (i != 1) {
                if (deq[i - 1][j] == deq[i][j]) check_temp = 1, check_deq[i - 1][j] = 1;
            }

            if (check_temp == 1) check = 1, check_deq[i][j] = 1;
        }
    }
    if (check) {
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < M; j++) {
                if (check_deq[i][j]) deq[i][j] = 0, check_deq[i][j] = 0;
            }
        }
    }
    else {
        float e = float(check_sum) / check_divide;
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < M; j++) {
                if (deq[i][j]) {
                    if (deq[i][j] > e) deq[i][j]--;
                    else if (deq[i][j] < e) deq[i][j]++;
                }
            }
        }
    }
}
int main() {
    cin >> N >> M >> T;
    int temp;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> temp;
            deq[i].push_back(temp);
        }
    }
    for (int i = 0; i < T; i++) {
        int x, d, k;
        cin >> x >> d >> k;
        for (int j = 1; j <= N; j++) {
            if (j % x == 0)
                move(j, d, k);
        }
        check();
    }
    int sum = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            sum += deq[i][j];
        }
    }
    cout << sum << '\n';
    return 0;
}