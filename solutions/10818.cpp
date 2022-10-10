#include <iostream>

int main() {
    int N;
    std::cin >> N;
    
    int min = 1000000;
    int max = -1000000;
    for(int i = 0; i < N; i++) { 
        int x;
        std::cin >> x;
        if(x < min)
            min = x;
        if(x > max)
            max = x;
    }

    std::cout << min << ' ' << max << std::endl;
}