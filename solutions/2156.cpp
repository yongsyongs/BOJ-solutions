#include <iostream>

int max(int a, int b, int c) {
    int max = a;
    if(b > max)
        max = b;
    if(c > max)
        max = c;
    return max;
}

int main() {
    int N;
    int *amounts;
    int *maxAmountDrunk;
    int X;

    std::cin >> N;
    
    amounts = new int[N];
    maxAmountDrunk = new int[N];
    for(int i = 0; i < N; i++) {
        std::cin >> amounts[i];
    }
    if(N == 1) {
        X = amounts[0];
    }
    else if(N == 2) {
        X = amounts[0] + amounts[1];
    }
    else if(N == 3) {
        X = max(
            amounts[0] + amounts[1],
            amounts[0] + amounts[2],
            amounts[1] + amounts[2]
        );
    }
    else {
        maxAmountDrunk[0] = amounts[0];
        maxAmountDrunk[1] = amounts[0] + amounts[1];
        maxAmountDrunk[2] = max(amounts[0] + amounts[2], amounts[1] + amounts[2], amounts[0] + amounts[1]);
        maxAmountDrunk[3] = max(amounts[3] + amounts[2] + amounts[0], amounts[3] + amounts[1] + amounts[0], amounts[2] + amounts[1]);
        for(int i = 4; i < N; i++){
            maxAmountDrunk[i] = max(
                amounts[i] + amounts[i - 1] + maxAmountDrunk[i - 3],
                amounts[i] + maxAmountDrunk[i - 2],
                amounts[i - 1] + amounts[i - 2] + maxAmountDrunk[i - 4]
            );
        }

        X = max(maxAmountDrunk[N - 1], maxAmountDrunk[N - 2], maxAmountDrunk[N - 3]);
    }
    std::cout << X << std::endl;
}