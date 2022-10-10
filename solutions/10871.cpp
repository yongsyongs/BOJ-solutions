#include <iostream>

int main() {
    int N, X;
    std::cin >> N;
    std::cin >> X;
    for(int i = 0; i < N; i++) {
        int a;
        std::cin >> a;
        if(a < X){
            std::cout << a << ' ';
        }
    }
}