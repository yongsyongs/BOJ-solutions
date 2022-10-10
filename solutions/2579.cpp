#include <iostream>

int max(int a, int b) {
    if(a > b)
        return a;
    else
        return b;
}

int main() {
    int N;
    int *scores;
    int *maxCumulativeSum;

    std::cin >> N;
    
    scores = new int[N];
    maxCumulativeSum = new int[N];
    for(int i = 0; i < N; i++) {
        std::cin >> scores[i];
    }

    maxCumulativeSum[0] = scores[0];
    maxCumulativeSum[1] = max(scores[0] + scores[1], scores[1]);
    maxCumulativeSum[2] = max(scores[0] + scores[2], scores[1] + scores[2]);
    for(int i = 3; i < N; i++) { 
        maxCumulativeSum[i] = max(
            scores[i] + scores[i - 1] + maxCumulativeSum[i - 3],
            scores[i] + maxCumulativeSum[i - 2]
        );
    }

    std::cout << maxCumulativeSum[N - 1] << std::endl;
}

