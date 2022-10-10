#include <iostream>

int main() {
    while(1) {
        int A, B, C;
        std::cin >> A;
        std::cin >> B;
        std::cin >> C;
        if((!A && !B) && !C)
            break;
        
        int r, c, s;
        if(A > B && A > C) {
            r = A;
            c = B;
            s = C;
        }
        else if(B > A && B > C) {
            r = B;
            c = A;
            s = C;
        }
        else if(C > A && C > B) {
            r = C;
            c = A;
            s = B;
        }

        bool isRight = r * r == c * c + s * s;
        if(isRight)
            std::cout << "right" << std::endl;
        else
            std::cout << "wrong" << std::endl;
    }
}