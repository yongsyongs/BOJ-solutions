#include <iostream>

int gcd(int a, int b) {
    int r = a % b;
    return r ? gcd(b, r) : b;
}

int main() {
    int a, b;
    std::cin >> a >> b;
    int x = gcd(a, b);
    std::cout << x << ' ' << a * b / x;
}