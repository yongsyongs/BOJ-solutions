#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N; cin >> N;
    stack<int> stack;

    for(int i = 0; i < N; i++) {
        string cmd; cin >> cmd;
        if(cmd == "push") {
            int x; cin >> x;
            stack.push(x);
        }
        else if(cmd == "pop") {
            if(stack.size() == 0)
                cout << -1 << '\n';
            else {
                cout << stack.top() << '\n';
                stack.pop();
            }
        }
        else if(cmd == "size") {
            cout << stack.size() << '\n';
        }
        else if(cmd == "empty") {
            cout << static_cast<int>(stack.empty()) << '\n';
        }
        else if(cmd == "top") {
            if(stack.size() == 0)
                cout << -1 << '\n';
            else 
                cout << stack.top() << '\n';
        }
    }
}