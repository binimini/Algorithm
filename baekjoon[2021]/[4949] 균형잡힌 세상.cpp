#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool flag = true;
string str;
stack<char> brackets;
bool check(string str) {
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '('|| str[i] == '[')
            brackets.push(str[i]);
        else if (str[i] == ')'|| str[i] == ']') {
            if (brackets.empty()) 
                return false;
            else if (brackets.top() == '[' && str[i] == ')' || brackets.top() == '(' && str[i] == ']') 
                return false;
            else 
                brackets.pop();
        }
    }
    if (brackets.empty())
        return true;
    else
        return false;
}
int main() {
    while (1) {
        while (!brackets.empty())
            brackets.pop();

        getline(cin, str);
        if (str == ".") break;
        
        flag = true;
        if (check(str))
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}