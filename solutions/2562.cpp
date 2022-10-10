#include <iostream>

int main() {
    int maxVal = -1;
    int maxArg = 0;
    for(int i = 0; i < 9; i++) {
        int x;
        std::cin >> x;
        if(x > maxVal) {
            maxVal = x;
            maxArg = i;
        }
    }
    std::cout << maxVal << std::endl;
    std::cout << maxArg + 1 << std::endl;
}