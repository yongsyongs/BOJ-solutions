#include <iostream>

int main() {
    while(1) {
        int a, b;
        std::cin >> a;
        std::cin >> b;
        if(!a && ! b)
            break;
        std::cout << a + b << std::endl;
    }
}