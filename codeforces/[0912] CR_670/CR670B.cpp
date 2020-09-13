#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,a,b) for(int i=a; i<b; i++)
int T, N;
int arr[100000];
vector<int> pqp;
vector<int> pqm;
int main() {
    cin >> T;
    FOR(t, 0, T) {
        cin >> N;
        pqp.clear();
        pqm.clear();
        int cnt0 = 0, cntp = 0, cntm = 0;
        long long int result = 1;
        FOR(i, 0, N) {
            cin >> arr[i];
            if (arr[i] > 0) {
                cntp++;
                pqp.push_back(arr[i]);
            }
            else if (arr[i] < 0) {
                cntm++;
                pqm.push_back(-arr[i]);
            }
            else if (arr[i] == 0)
                cnt0++;

        }
        if (N == 5) {
            FOR(i, 0, 5) {
                result *= arr[i];
            }
            cout << result << "\n";
        }
        else {
            int cnt = 0;
            if (cntp==0&&cnt0+cntm>=5) {
                if (cnt0 != 0)
                    cout << 0 << "\n";
                else {
                    sort(arr, arr + N);
                    int temp = N - 1;
                    for (int i = 0; i < 5; i++) {
                        result *= arr[temp];
                        temp--;
                    }
                    cout << result << "\n";
                }
            }
            else if ((cntm / 2) * 2 + cntp >= 5) {
                sort(pqp.begin(), pqp.end());
                sort(pqm.begin(), pqm.end());
                result *= pqp.back();
                cnt++;
                pqp.pop_back();
                int tempp = 0, tempm = 0;
                while (pqp.size()>=2 && pqm.size() >= 2) {
                    if (cnt == 5)
                        break;
                    if (tempp == 0) {
                        if (pqp.size()>=2) {
                            tempp = pqp.back()* pqp[pqp.size() - 2];
                        }
                    }
                    if (tempm == 0) {
                        if (pqm.size() >= 2) {
                            tempm = pqm.back() * pqm[pqm.size() - 2];
                        }
                    }
                    if (tempp > tempm) {
                        result *= tempp;
                        tempp = 0;
                        cnt += 2;
                        pqp.pop_back();
                        pqp.pop_back();
                    }
                    else {
                        result *= tempm;
                        tempm = 0;
                        cnt += 2;
                        pqm.pop_back();
                        pqm.pop_back();
                    }
                }
                if (cnt == 5) {
                    cout<< result << '\n';
                }
                else if (cnt == 3) {
                    int t1;
                    if (pqp.size() >= 2) {
                        t1 = pqp.back() * pqp[pqp.size() - 2];
                        result *= t1;
                    }
                    else if (pqm.size() >= 2) {
                        t1 = pqm.back() * pqm[pqm.size() - 2];
                        result *= t1;
                    }
                    cout << result << '\n';
                }
                else if (cnt == 1) {
                    int t1;
                    while (cnt != 5) {
                        if (pqp.size() >= 2) {
                            t1 = pqp.back() * pqp[pqp.size() - 2];
                            result *= t1;
                            cnt += 2;
                            pqp.pop_back();
                            pqp.pop_back();

                        }
                        else if (pqm.size() >= 2) {
                            t1 = pqm.back() * pqm[pqm.size() - 2];
                            result *= t1;
                            cnt += 2;
                            pqm.pop_back();
                            pqm.pop_back();
                        }
                    }
                    cout << result << '\n';
                }
            }
            else if (cntm+cnt0 + cntp >= 5) {
                cout << "0" << '\n';
            }
        }
    }
    return 0;
}