#include <iostream>

bool IsDevil(int x) {
    int maxExp = 0;
    int pow = 1;
    while(x % pow != x)  {
        pow *= 10;
        maxExp++;
    }
    int *numbers = new int[maxExp]; 
    
    for(int i = maxExp - 1; i >= 0; i--) {
        pow /= 10;
        numbers[i] = (x / pow) % 10;
    }

    for(int i = 0; i < maxExp - 2; i++) {
        if((numbers[i] == 6 && numbers[i + 1] == 6) && numbers[i + 2] == 6) {
            return true;
        }
    }
    return false;
}

int main() {
    int N;
    int devilNumber;
    std::cin >> N;

    int i = 0;
    int x = 665;
    while(++x) {
        if(IsDevil(x)) {
            i++;
            if(i == N) break;
        }
    }

    std::cout << x << std::endl;
}