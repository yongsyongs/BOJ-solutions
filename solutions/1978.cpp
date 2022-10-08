#include <iostream>

using namespace::std;

bool IsPrimeNumber(int M, int *primeNumbers, int x) {
    bool isPrime = true;
    for(int i = 0; i < M; i++) {
        int p = primeNumbers[i];
        if(x == p) break;
        if(x < p || x % p == 0) {
            isPrime = false;
            break;
        }
    }
    return isPrime;
}

int Append(int M, int *primeNumbers, int x) {
    primeNumbers[M] = x;
    return M + 1;
}

int main() {
    int N;
    int max = 0;
    int primeCount = 0;

    cin >> N;
    int *A = new int[N];

    for(int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if(x > max) max = x;
        A[i] = x;
    }

    int M = 5; // primeNumbers의 길이
    int *primeNumbers = new int[max];
    primeNumbers[0] = 2;
    primeNumbers[1] = 3;
    primeNumbers[2] = 5;
    primeNumbers[3] = 7;
    primeNumbers[4] = 11;


    for(int i = 0; i < N; i++) {
        int X = A[i];
        if(primeNumbers[M - 1] <= X / 2) {
            for(int p = primeNumbers[M - 1] + 1; p <= X / 2; p++) {
                if(IsPrimeNumber(M, primeNumbers, p)) {
                    M = Append(M, primeNumbers, p);
                    if(X % p == 0) break;
                }
            }
        }
        bool isPrime = IsPrimeNumber(M, primeNumbers, X);

        if(isPrime)
            primeCount++;
    }

    cout << primeCount << endl;
}