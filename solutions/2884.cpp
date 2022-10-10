#include <iostream>

int main() {
    int H, M;
    std::cin >> H;
    std::cin >> M;
    
    if(M >= 45)
        M -= 45;
    else {
        M = 60 - (45 - M);
        H--;
        if(H == -1)
            H = 23;
    }
    std::cout << H << ' ' << M << std::endl;
}