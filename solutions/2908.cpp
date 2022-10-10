#include <iostream>

int TenPow(int exp) {
    int x = 1;
    for(int i = 0; i < exp; i++) {
        x *= 10;
    }
    return x;
}

int inverse(int x) {
    int maxExp = 0;
    int y = 0;
    while((x % TenPow(maxExp)) != x) {
        maxExp++;
    }
    int o = 0;
    for(int exp = 0; exp < maxExp; exp++) {
        int i = (x % TenPow(exp + 1) - o) / TenPow(exp);
        o = i;
        y += TenPow(maxExp - exp - 1) * i;
    }
    return y;
}

int main() {
    int a, b;
    std::cin >> a;
    std::cin >> b;
    a = inverse(a);
    b = inverse(b);
    if(a > b)
        std::cout << a << std::endl;
    else
        std::cout << b << std::endl;
}