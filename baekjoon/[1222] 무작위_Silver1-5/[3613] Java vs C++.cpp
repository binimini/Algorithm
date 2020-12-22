#include<bits/stdc++.h>
using namespace std;
string S;
bool flag1 = 0, flag2 = 0, error = 0;
int main() {
    cin >> S;
    if (!(S[0] >= 'a' && S[0] <= 'z'))
        error = 1;

    for (int i = 0; i < S.size(); i++) {
        if (S[i] >= 'A' && S[i] <= 'Z')
            flag1 = 1;
        else if (S[i] == '_') {
            if (i + 1 >= S.size() || !(S[i + 1] >= 'a' && S[i + 1] <= 'z'))
                error = 1;
            flag2 = 1;
        }
    }

    if (flag1 && flag2)
        error = 1;
    if (!error) {
        if (flag1) {
            for (int i = 0; i < S.size(); i++) {
                if (S[i] >= 'A' && S[i] <= 'Z') {
                    cout << "_" << (char)(S[i] + 32);
                }
                else
                    cout << S[i];
            }
        }
        else {
            for (int i = 0; i < S.size(); i++) {
                if (S[i] == '_') {
                    cout << (char)(S[i + 1] - 32);
                    i++;
                }
                else
                    cout << S[i];
            }
        }
    }
    else
        cout << "Error!\n";
        
    
    return 0;
}