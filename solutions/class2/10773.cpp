#include <iostream>
#include <stack>
using namespace std;

int main() {
    int N; cin >> N;
    stack<int> stack;
    for(int i = 0; i < N; i++) {
        int x; cin >> x;
        if(x)
            stack.push(x);
        else
            stack.pop();
    }

    uint sum = 0;
    while(stack.size() > 0) {
        sum += stack.top();
        stack.pop();
    }

    cout << sum << endl;
}