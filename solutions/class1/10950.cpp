#include <iostream>

int main() {
    int T;
    std::cin >> T;
    while(T--) {
        int a, b;
        std::cin >> a;
        std::cin >> b;
        std::cout << a + b << std::endl;
        std::cout << a - b << std::endl;
        std::cout << a * b << std::endl;
        std::cout << a / b << std::endl;
        std::cout << a % b << std::endl;
    }
}