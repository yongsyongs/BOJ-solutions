#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main() {
    int N;
    cin >> N;
    queue<char> result;
    stack<int> stack;
    int *series = new int[N];
    int lastPushed = 0;
    bool isValid = true;

    for(int i = 0; i < N; i++) {
        cin >> series[i];
    }
    
    for(int i = 1; i <= N && i <= series[0]; i++) {
        stack.push(i);
        result.push('+');
        lastPushed = i;
    }
    stack.pop();
    result.push('-');

    for(int i = 1; i < N; i++) {
        int X = series[i];


        if(stack.size() > 0 && stack.top() == X) {
            stack.pop();
            result.push('-');
        }
        else {
            if(stack.size() > 0 && stack.top() > X) {
                isValid = false;
                break;
            }

            while(lastPushed < X) {
                lastPushed++;
                stack.push(lastPushed);
                result.push('+');
            }
            stack.pop();
            result.push('-');
        }
    }
    
    if(isValid) {
        int L = result.size();
        for(int i = 0; i < L; i++) {
            cout << result.front() << '\n';
            result.pop();
        }
    }
    else {
        cout << "NO" << endl;
    }
}