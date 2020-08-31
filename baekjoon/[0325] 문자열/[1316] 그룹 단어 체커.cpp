#include <iostream>
using namespace std;
int main() {
    int T, pre;
    cin >> T;
    int count = T;
    for (int i = 0; i < T; i++) {
        string s;
        int check = 0;
        cin >> s;
        int* arr = new int[s.size()]{ 0 };
        for (int i = 0; i < s.size(); i++) {
            if (i != 0)
                arr[i] = pre;
            int temp = s[i];
            for (int j = 0; j < i; j++) {
                if (temp == arr[j])
                    if (arr[j] != pre) {
                        check = -1;
                    }
            }
            pre = temp;
        }
        count += check;
    }
    cout << count << endl;
    return 0;
}