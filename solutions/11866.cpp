#include <iostream>

using namespace::std;

int Step(bool *valid, int currIdx, int N, int K) {
    int stepCount = 0;
    while(stepCount < K) {
        currIdx = (currIdx + 1) % N;
        if(valid[currIdx]) stepCount++;
    }
    return currIdx;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, K; cin >> N >> K;
    int idx = K - 1;
    bool *valid = new bool[N];
    fill_n(valid, N, true);
    
    cout << '<';
    for(int i = 0; i < N - 1; i++) {
        cout << idx + 1 << ", ";
        valid[idx] = false;
        idx = Step(valid, idx, N, K);
    }
    cout << idx + 1 << '>' << endl;
}