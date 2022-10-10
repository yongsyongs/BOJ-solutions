#include <iostream>

int *fibs;

int main() {
    int T;
    std::cin >> T;

    int *numbers = new int[T];
    int maxN = 0;
    for(int i = 0; i < T; i++) {
        std::cin >> numbers[i];
        if(maxN < numbers[i])
            maxN = numbers[i];
    }

    maxN++;
    fibs = new int[maxN];
    fibs[0] = 0;
    fibs[1] = 1;
    for(int i = 2; i < maxN; i++) {
        fibs[i] = fibs[i - 1] + fibs[i - 2];
    }
    

    for(int i = 0; i < T; i++) {
        int a, b;
        if(numbers[i] == 0) {
            a = 1;
            b = 0;
        }
        else if(numbers[i] == 1) {
            a = 0;
            b = 1;
        }
        else {
            a = fibs[numbers[i] - 1];
            b = fibs[numbers[i]];
        }
        std::cout << a << ' ' << b << std::endl;
    }
    return 0;
}