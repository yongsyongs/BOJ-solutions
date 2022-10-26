#include <iostream>

int main() {
    int T;
    std::cin >> T;

    for(int t = 0; t < T; t++) {
        int R;
        char *S = new char[21];
        std::cin >> R;
        std::cin >> S;
        int L = 0;
        while(S[L] != 0)
            L++;
        
        char *str = new char[L * R];
        for(int i = 0; i < L; i++) {
            for(int j = 0; j < R; j++) {
                std::cout << S[i];
            }
        }
        std::cout << std::endl;
    }
}