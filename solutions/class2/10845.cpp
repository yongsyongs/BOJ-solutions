#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N; cin >> N;
    queue<int> queue;

    for(int i = 0; i < N; i++) {
        string cmd; cin >> cmd;
        if(cmd == "push") {
            int x; cin >> x;
            queue.push(x);
        }
        else if(cmd == "pop") {
            if(queue.size() == 0)
                cout << -1 << '\n';
            else {
                cout << queue.front() << '\n';
                queue.pop();
            }
        }
        else if(cmd == "size") {
            cout << queue.size() << '\n';
        }
        else if(cmd == "empty") {
            cout << static_cast<int>(queue.empty()) << '\n';
        }
        else if(cmd == "front") {
            if(queue.size() == 0)
                cout << -1 << '\n';
            else 
                cout << queue.front() << '\n';
        }
        else if(cmd == "back") {
            if(queue.size() == 0)
                cout << -1 << '\n';
            else
                cout << queue.back() << '\n';
        }
    }
}