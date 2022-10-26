#include <iostream>

int main() {
    char S[100] = {};
    int pos[26] = {};
    
    std::fill_n(pos, 26, -1);

    std::cin >> S;

    for(int i = 0; i < 100; i++) {
        char c = S[i];
        if(c == 0)
            continue;

        int a = static_cast<int>(c) - 97;
        if(pos[a] == -1)
            pos[a] = i;
    }
    
    for(int i = 0; i < 26; i++) {
        std::cout << pos[i];
        if(i < 25)
            std::cout << ' ';
    }
}