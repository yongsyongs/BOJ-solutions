#include <iostream>

using namespace::std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    int *P = new int[N];
    for(int i = 0; i < N; i++) cin >> P[i];
    int totalSum = 0;
    int cumSum = 0;

    for(int i = 0; i < N; i++) {
        int minArg = -1;
        int minVal = 1001;
        for(int j = 0; j < N; j++) {
            if(P[j] > 0 && P[j] < minVal) {
                minVal = P[j];
                minArg = j;
            }
        }
        P[minArg] = -1;
        cumSum += minVal;
        totalSum += cumSum;
    }

    cout << totalSum << endl;
}