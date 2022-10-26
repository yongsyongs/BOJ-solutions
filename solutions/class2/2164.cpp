#include <iostream>
#include <queue>
using namespace std;

int main() {
    int N;
    std::cin >> N;
    queue<int> cards;
    for(int i = 1; i <= N; i++) {
        cards.push(i);
    }

    while(cards.size() > 1) {
        cards.pop();
        int x = cards.front();
        cards.pop();
        cards.push(x);
    }

    cout << cards.front() << endl;
}