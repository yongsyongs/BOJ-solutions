#include <iostream>

int TenPow(int exp) {
    int x = 1;
    for(int i = 0; i < exp; i++) {
        x *= 10;
    }
    return x;
}

int main() {
    int X = 1;
    int maxExp = 0;
    int exp = 0;
    int counts[10] = {};

    for(int i = 0; i < 3; i++) {
        int x;
        std::cin >> x;
        X *= x;
    }

    while((X % TenPow(maxExp)) != X) {
        maxExp++;
    }
    int o = 0;
    for(int exp = 0; exp < maxExp; exp++) {
        int i = (X % TenPow(exp + 1) - o) / TenPow(exp);
        o = i;
        counts[i]++;
    }
    for(int i = 0; i < 10; i++) {
        std::cout << counts[i] << std::endl;
    }

}