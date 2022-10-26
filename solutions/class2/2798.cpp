#include <iostream>

int main() {
    int N, M;
    std::cin >> N >> M;
    int *cards = new int[N];
    for(int i = 0; i < N; i++) std::cin >> cards[i];

    int minDiff = M;
    int maxSum = 0;

    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            for(int k = j + 1; k < N; k++) {
                int sum = cards[i] + cards[j] + cards[k];
                int diff = M - sum;
                if(diff >= 0 && diff < minDiff) {
                    minDiff = diff;
                    maxSum = sum;
                    if(diff == 0) break;
                }
            }
        }
    }

    std::cout << maxSum << std::endl;
}