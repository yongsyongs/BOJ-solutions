#include <iostream>

int pow(int n, int x) {
    int s = 1;
    for(int i = 0; i < x; i++) {
        s *= n;
    }
    return s;
}

int main() {
    int N;
    std::cin >> N;
    while(N) {
        bool isPalindrome;
        int maxExp = 1;
        if(N % pow(10, maxExp) == N) {
            isPalindrome = true;
        }
        else {
            while(N % pow(10, maxExp) != N) {
                maxExp++;
            }
            maxExp--;
            int exp = 0;
            while(exp < maxExp) {
                int mn = (N / pow(10, exp)) % 10;
                int mx = (N / pow(10, maxExp)) % 10;
                isPalindrome = mn == mx;
                if(!isPalindrome) {
                    break;
                }
                maxExp--;
                exp++;
            }
        }
        if(isPalindrome)
            std::cout << "yes" << std::endl;
        else
            std::cout << "no" << std::endl;
        std::cin >> N;
    }
}