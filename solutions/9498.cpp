#include <iostream>

int main() {
    int X;
    std::cin >> X;
    if(X >= 90)
        std::cout << 'A';
    else if(X >= 80)
        std::cout << 'B';
    else if(X >= 70)
        std::cout << 'C';
    else if(X >= 60)
        std::cout << 'D';
    else
        std::cout << 'F';
}