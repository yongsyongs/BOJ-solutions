#include <iostream>

int GetCount(uint *lens, int length, int K) {
    int count = 0;
    for(int i = 0; i < K; i++)
        count += lens[i] / length;

    return count;
}

int UpdateLength(uint minLength, uint maxLength) {
    uint length = (minLength + maxLength) / 2;
    if(maxLength - minLength == 1)
        length++;

    return length;
}

int main() {
    int K, N;
    std::cin >> K >> N;

    uint answer;
    uint length;
    uint minLength = 1;
    uint maxLength = 0;
    uint *lens = new uint[K];

    for(int i = 0; i < K; i++) {
        std::cin >> lens[i];
        if(lens[i] > maxLength)
            maxLength = lens[i];
    }

    while(minLength <= maxLength) {
        length = (maxLength + minLength) / 2;
        int count = GetCount(lens, length, K);

        if(count >= N) {
            minLength = length + 1;
            answer = length;
        }
        else if(count < N) {
            maxLength = length - 1;
        }

    }

    std::cout << answer << std::endl;
}