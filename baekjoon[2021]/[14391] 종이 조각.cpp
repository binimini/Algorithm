#include <bits/stdc++.h>
using namespace std;
int N, M, res = 0;
char arr[5][5];
int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }
    int sum = 0;
    string tempstr;
    int temp[5][5] = { 0 };
    for (int i = 0; i < (1 << (N*M+1)) - 1; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                temp[j][k] = 0;
            }
        }
        sum = 0;
        for (int j = 0; j < 16; j++) {
            if ((1 << j) & i) 
                temp[j / M][j - (j / M) * M] = 1;
        }
        for (int j = 0; j < N; j++) {
            tempstr = "";
            for (int k = 0; k < M; k++) {
                if (temp[j][k] == 0)
                    tempstr += arr[j][k];
                else if (tempstr != "") {
                    sum += stoi(tempstr);
                    tempstr = "";   
                }
            }
            if (tempstr!="")
                sum += stoi(tempstr);
        }
        for (int j = 0; j < M; j++) {
            tempstr = "";
            for (int k = 0; k < N; k++) {
                if (temp[k][j] == 1)
                    tempstr += arr[k][j];
                else if (tempstr != "") {
                    sum += stoi(tempstr);
                    tempstr = "";               
                }
            }
            if (tempstr!="")
                sum += stoi(tempstr);
        }
        res = max(res, sum);
    }
    cout << res;
    return 0;
}