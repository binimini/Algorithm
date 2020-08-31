#include <iostream>
#include <vector>
using namespace std;

int main() {//후위 표기식
    string str, result = "";
    cin >> str;
    vector<char> v;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            result += str[i];
        else {
            if (str[i] == '(') {
                v.push_back(str[i]);
            }
            else if (str[i] == '*' || str[i] == '/') {
                while (!v.empty() && (v.back() == '*' || v.back() == '/') ){
                    result += v.back();
                    v.pop_back();
                }
                v.push_back(str[i]);
            }
            else if (str[i] == '+' || str[i] == '-') {
                while (!v.empty() && v.back() != '(') {
                    result += v.back();
                    v.pop_back();
                }
                v.push_back(str[i]);
            }
            else if (str[i] == ')') {
                while (!v.empty() && v.back() != '(') {
                    result += v.back();
                    v.pop_back();
                }
                v.pop_back();
            }
        }
    }
    while (!v.empty()) {
        result += v.back();
        v.pop_back();
    }
    cout << result;
    return 0;
}