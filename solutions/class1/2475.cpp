#include <iostream>

int main() {
    int sum = 0;
    for(int i = 0; i < 5; i++) {
        int x;
        std::cin >> x;
        sum += x * x;
    }
    std::cout << sum % 10 << std::endl;

}