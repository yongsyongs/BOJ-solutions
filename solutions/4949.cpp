#include <iostream>
#include <stack>
#include <cstring>
using namespace std;



int main() {
    while(1) {
        char str[101] = {};
        cin.getline(str, 101);
        if(str[0] == '.' && (str[1] == 0 || str[1] == '\n')) break;
        if (!strcmp(str, ".")) break;
        bool isBalanced = true;
        stack<char> pars;
        
        for(int i = 0; i < 100; i++) {
            char c = str[i];
            if(c == 0) break;
            else if(c == '(') pars.push('(');
            else if(c == '[') pars.push('[');
            else if(c == ')') {
                if(pars.size() > 0 && pars.top() == '(')
                    pars.pop();
                else {
                    isBalanced = false;
                    break;
                }
            }
            else if(c == ']') {
                if(pars.size() > 0 && pars.top() == '[')
                    pars.pop();
                else {
                    isBalanced = false;
                    break;
                }
            }
        }
        if(pars.size() > 0)
            isBalanced = false;

        if(isBalanced)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
}