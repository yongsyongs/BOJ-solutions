#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int M, N;
    cin >> M >> N;

    int max = static_cast<int>(sqrt(N));
    bool *isPrime = new bool[N + 1];
    fill_n(isPrime, N + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;

    for(int i = 1; i <= max; i++) {
        if(isPrime[i]) {
            int j = 2;
            while(i * j <= N) {
                isPrime[i * j] = false;
                j++;
            }
        }
    }
    for(int i = M; i <= N; i++) {
        if(isPrime[i])
            cout << i << '\n';
    }
}