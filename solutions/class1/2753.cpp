#include <iostream>

int main() {
    int N;
    std::cin >> N;
    
    if(N % 4 == 0) {
        if(N % 100 != 0 || N % 400 == 0)
            std::cout << 1 << std::endl;
        else
            std::cout << 0 << std::endl;
    }
    else
        std::cout << 0 << std::endl;
}