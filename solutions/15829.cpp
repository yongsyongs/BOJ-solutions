#include <iostream>

int main() {
    long int r = 31;
    long int M = 1234567891;
    long int L;
    std::cin >> L;

    char *S = new char[L];
    int a;
    long int *h = new long int[L]; // r^i 에 대한 나머지
    long int *H = new long int[L]; // a_i*r^i에 대한 나머지

    std::cin >> S;

    a = static_cast<long int>(S[0]) - 96;
    h[0] = 1;
    H[0] = a;

    long int hashVal = a % M;
    long int pow = 1;
    for(int i = 1; i < L; i++) {
        pow *= 31;
        a = static_cast<int>(S[i]) - 96;
        h[i] = (r * h[i - 1]) % M;
        H[i] = (a * r * h[i - 1]) % M;
        hashVal += H[i];
    }
    hashVal %= M;
    std::cout << hashVal << std::endl;
}