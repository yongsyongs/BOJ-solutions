#include <iostream>

void swap(char *arr, int i, int j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void BubbleSort(int N, char *A) {
    for(char i = N - 1; i > 0; i--) {
        for(char j = 0; j < i; j++) {
            if(A[j] > A[j + 1]) {
                swap(A, j, j + 1);
            }
        }
    }
}

int main() {
    int len = 0;
    int counts[26];
    char input[1000000];
    for(int i = 0; i < 26; i++)
        counts[i] = 0;

    std::cin >> input;

    for(int i = 0; i < 1000000; i ++) {
        if(input[i] == 0)
            break;
        
        if(input[i] >= 97)
            input[i] -= 32;


        counts[input[i] - 65]++;        
        len++;
    }

    if(len == 1) {
        std::cout << input[0] << std::endl;
    }
    else if(len == 2) {
        if(input[0] == input[1])
            std::cout << input[0] << std::endl;
        else
            std::cout << '?' << std::endl;
    }
    else {
        int maxVal = 0;
        int maxArg = -1;
        for(int i = 0; i < 26; i++) {
            if(counts[i] > maxVal) {
                maxVal = counts[i];
                maxArg = i;
            }
        }
        for(int i = 0; i < 26; i++) {
            if(maxArg != i && counts[i] == maxVal) {
                maxArg = -1;
            }
        }
        if(maxArg == -1) {
            std::cout << '?' << std::endl;
        }
        else {
            std::cout << static_cast<char>(maxArg + 65) << std::endl;
        }
    }
}