#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int main() {
    int T;
    cin >> T;
    bool *result = new bool[T];
    for(int a = 0; a < T; a++) {
        char str[51] = {};
        cin >> str;
        bool isBalanced = true;
        stack<char> stack;
        
        for(int i = 0; i < 50; i++) {
            char c = str[i];
            if(c == 0) break;
            else if(c == '(') stack.push('(');
            else if(c == ')') {
                if(stack.size() > 0)
                    stack.pop();
                else {
                    isBalanced = false;
                    break;
                }
            }
            else {
                isBalanced = false;
                break;
            }
        }
        if(stack.size() > 0)
            isBalanced = false;

        result[a] = isBalanced;
    }

    for(int i = 0; i < T; i++) {
        if(result[i])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}