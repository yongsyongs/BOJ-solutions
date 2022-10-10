#include <iostream>
#include <queue>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T; cin >> T;
    while(T--) {
        int N, M; cin >> N >> M;
        int rank = 0;
        queue<int> queue;
        for(int i = 0; i < N; i++) {
            int x; cin >> x;
            queue.push(x);
        }

        if(N == 1) {
            cout << 1 << endl;
            continue;
        }

        while(queue.size() > 0) {
            int maxPriority = -1;
            for(int i = 0; i < queue.size(); i++) {
                int x = queue.front();
                if(x > maxPriority)
                    maxPriority = x;
                
                queue.pop();
                queue.push(x);
            }

            while(queue.front() < maxPriority) {
                queue.push(queue.front());
                queue.pop();
                M--;
                if(M == -1)
                    M = queue.size() - 1;
            }
            queue.pop();
            rank++;
            if(M == 0) break;
        }
        cout << rank - 1 << endl;
    }
}