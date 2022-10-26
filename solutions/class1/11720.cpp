#include <iostream>

int main() {
    int N;
    std::cin >> N;

    char *numbers = new char[N];
    std::cin >> numbers;

    int sum = 0;
    for(int i = 0; i < N; i++) {
        sum += static_cast<int>(numbers[i]) - 48;
    }
    
    std::cout << sum << std::endl;
}