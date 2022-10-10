
#include <iostream>

int main() {
    int remainers[10];
    bool exists[42] = {};

    for(int i = 0; i < 10; i++) {
        std::cin >> remainers[i];
        remainers[i] = remainers[i] % 42;
        exists[remainers[i]] |= 1;
    }
    
    int sum = 0;
    for(int i = 0; i < 42; i++) {
        if(exists[i])
            sum++;
    }
    std::cout << sum << std::endl;
}