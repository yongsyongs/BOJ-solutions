#include <iostream>
#include <queue>

using namespace::std;

int GetMaxPriority(int N, int *priorities) {
    int max = 0;
    for(int i = 0; i < N; i++) {
        int x = priorities[i];
        if(x > max) max = x;
    }
    return max;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    
    while(T--) {
        int N, M; cin >> N >> M;
        int *P = new int[N];
        queue<int> docs;
        queue<int> priorities;

        for(int i = 0; i < N; i++) {
            cin >> P[i];
            docs.push(i);
            priorities.push(P[i]);
        }

        while(docs.size()) {
            int maxPriority = GetMaxPriority(N, P);
            int doc = docs.front(); docs.pop();
            int priority = priorities.front(); priorities.pop();
            if(maxPriority > priority) {
                docs.push(doc);
                priorities.push(priority);
            }
            else {
                P[doc] = -1;
                if(doc == M) {
                    cout << N - docs.size() << '\n';
                    break;
                }
            }
        }
    }
}