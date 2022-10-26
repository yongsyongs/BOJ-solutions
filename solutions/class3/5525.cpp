#include <iostream>

using namespace std;

int* MakeP(int n) {
    int *P = new int[2 * n + 1];
    for(int i = 0; i < n; i++) {
        P[2 * i + 1] = 0;
        P[2 * i] = 1;
    }
    P[2 * n] = 1;
    return P;
}

bool IsP(int *A, int *P, int N) {
    bool isP = true;
    for(int i = 0; i < N; i++) {
        if(A[i] != P[i]) {
            isP = false;
            break;
        }
    }
    return isP;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N; cin >> N;
    int M; cin >> M;
    int *A = new int[M];
    for(int i = 0; i < M; i++) {
        char c; cin >> c;
        A[i] = c == 'I';
    }

    int cnt = 0;
    int length = 0;
    int i = 0;
    while(i < M - 2) {
        bool isP = A[i] * A[i + 2] == 1 && A[i + 1] == 0;
        if(isP) {
            i += 2;
            length++;

            if(i >= M - 2 && length >= N) {
                cnt += length - N + 1;
            }
        }
        else {
            i++;
            if(length >= N) {
                cnt += length - N + 1;
            }
            length = 0;
        }
    }
    cout << cnt << endl;
}