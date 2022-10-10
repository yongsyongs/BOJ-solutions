#include <iostream>

int main() {
    int N;
    std::cin >> N;
    for(int i = 1; i <= N; i++) {
        for(int j = N - i; j > 0; j--) {
            std::cout << ' ';
        }
        for(int j = 0; j < i; j++) {
            std::cout << '*';
        }
        std::cout << std::endl;
    }
}