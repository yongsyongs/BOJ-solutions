#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N; cin >> N;
    deque<int> deque;

    for(int i = 0; i < N; i++) {
        string cmd; cin >> cmd;
        if(cmd == "push_front") {
            int x; cin >> x;
            deque.push_front(x);
        }
        else if(cmd == "push_back") {
            int x; cin >> x;
            deque.push_back(x);
        }
        else if(cmd == "pop_front") {
            if(deque.size() == 0)
                cout << -1 << '\n';
            else {
                cout << deque.front() << '\n';
                deque.pop_front();
            }
        }
        else if(cmd == "pop_back") {
            if(deque.size() == 0)
                cout << -1 << '\n';
            else {
                cout << deque.back() << '\n';
                deque.pop_back();
            }
        }
        else if(cmd == "size") {
            cout << deque.size() << '\n';
        }
        else if(cmd == "empty") {
            cout << static_cast<int>(deque.empty()) << '\n';
        }
        else if(cmd == "front") {
            if(deque.size() == 0)
                cout << -1 << '\n';
            else 
                cout << deque.front() << '\n';
        }
        else if(cmd == "back") {
            if(deque.size() == 0)
                cout << -1 << '\n';
            else
                cout << deque.back() << '\n';
        }
    }
}