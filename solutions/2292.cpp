#include <iostream>

int main() {
    int N;
    std::cin >> N;
    if(N == 1) {
        std::cout << 1 << std::endl;
        return 0;
    }
    
    int i = 0;
    while(++i) {
        int x = 3 * i * i + 3 * i + 1;
        if(N <= x) break;
    }
    std::cout << i + 1 << std::endl;
}