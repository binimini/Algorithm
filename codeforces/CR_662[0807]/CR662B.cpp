#include <iostream>
using namespace std;
int N, Q;
int cnt[100001] = { 0 };
int main() {
    std::ios_base::sync_with_stdio(0);
    cin >> N;
    int temp;
    int cnt_8 = 0, cnt_6 = 0, cnt_4 = 0, cnt_2 = 0;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        cnt[temp]++;
    }
    for (int i = 1; i <= 100000; i++) {
        if (cnt[i] >= 8)
            cnt_8++;
        else if (cnt[i] >= 6)
            cnt_6++;
        else if (cnt[i] >= 4)
            cnt_4++;
        else if (cnt[i] >= 2)
            cnt_2++;
    }
    cin >> Q;
    char c;
    int te;
    for (int j = 0; j < Q; j++) {
        cin >> c;
        if (c == '+') {
            cin >> te;
            cnt[te]++;
            if (cnt[te] == 8)
                cnt_8++, cnt_6--;
            else if (cnt[te] == 6)
                cnt_6++, cnt_4--;
            else if (cnt[te] == 4)
                cnt_4++, cnt_2--;
            else if (cnt[te] == 2)
                cnt_2++;
        }
        else if (c == '-') {
            cin >> te;
            cnt[te]--;
            if (cnt[te] == 7)
                cnt_8--, cnt_6++;
            else if (cnt[te] == 5)
                cnt_6--, cnt_4++;
            else if (cnt[te] == 3)
                cnt_4--, cnt_2++;
            else if (cnt[te] == 1)
                cnt_2--;
        }
        if (cnt_8 >= 1)// 주석 코드 대회 이후 추가(cnt_x 에서 x이상의 cnt_y도 고려해야함)
            cout << "YES" << "\n";
        else if (cnt_6 >= 2)//추가
            cout << "YES" << "\n";
        else if (cnt_6 >= 1 && cnt_4 >= 1)//추가
            cout << "YES" << "\n";
        else if (cnt_4 >= 2)
            cout << "YES" << "\n";
        else if (cnt_6 >= 1 && (cnt_2 >= 1||cnt_4>=1))// cnt_4가 2일 때 무조건 YES, 그러나 1일 때 남아있음
            cout << "YES" << '\n';
        else if (cnt_4 >= 1 && cnt_2 >= 2)
            cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
    return 0;
}