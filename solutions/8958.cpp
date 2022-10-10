
#include <iostream>

int main() {
    int T;
    std::cin >> T;

    while(T--) {
        char S[80];
        std::cin >> S;

        int len = 0;
        while(S[len] != 0)
            len++;

        int cumSum = 0;
        int currSum = 0;
        for(int i = 0; i < len; i++) {
            char c = S[i];
            if(c == 'O') {
                currSum++;
                cumSum += currSum;
            }
            else {
                currSum = 0;
            }
        }
        
        std::cout << cumSum << std::endl;
    }
}