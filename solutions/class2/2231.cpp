#include <iostream>

int TenPow(int exp) {
    int x = 1;
    for(int i = 0; i < exp; i++) {
        x *= 10;
    }
    return x;
}

int calcDecomposition(int M) {
    int sum = M;
    while(M > 0) {
        sum += M % 10;
        M /= 10;
    }

    return sum;
}

int main() {
    int N;
    int maxExp = 0;
    int minRange;
    int minGenerator = 0;
    std::cin >> N;

    if(N < 10) {
        std::cout << N / 2 << std::endl;
        return 0;
    }

    while((N % TenPow(maxExp)) != N) maxExp++;
    minRange = N - 9 * maxExp;

    for(int M = minRange; M < N; M++) {
        int gen = calcDecomposition(M);
        if(gen == N) {
            minGenerator = M;
            break;
        }
    }

    std::cout << minGenerator << std::endl;
}