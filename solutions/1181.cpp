#include <iostream>

int compare(char *A, char *B, int lenA, int lenB) {
    if(lenA > lenB)
        return 1;
    else if(lenA < lenB)
        return -1;

    for(int i = 0; i < lenA; i++) {
        if(A[i] > B[i])
            return 1;
        else if(A[i] < B[i])
            return -1;
    }

    return 0;
}

void swap(int *A, int a, int b) {
    int t = A[a];
    A[a] = A[b];
    A[b] = t;
}

int insert(char **words, int newArg, int *args, int *lens, int N) {
    char *newWord = words[newArg];
    int newLength = lens[newArg];

    if(N == 0) {
        args[0] = newArg;
        return 1;
    }
    
    for(int i = 0; i < N; i++) {
        int compareResult = compare(newWord, words[args[i]], newLength, lens[args[i]]);
        if(compareResult == 0)
            return N;
        else if(compareResult == -1) {
            for(int j = N - 1; j >= i; j--)
                swap(args, j, j + 1);
            args[i] = newArg;
            return N + 1;
        }
    }

    args[N] = newArg;
    return N + 1;
}

int main() {
    int N;
    std::cin >> N;

    char **words = new char*[N];
    int *lens = new int[N];
    int *args = new int[N];
    for(int i = 0; i < N; i++) {
        args[i] = -1;
    }

    int argLen = 0;

    for(int i = 0; i < N; i++) {
        int length = 0;
        words[i] = new char[51];
        std::cin >> words[i];

        while(words[i][length] != 0) length++;
        lens[i] = length;

        argLen = insert(words, i, args, lens, argLen);
    }

    for(int i = 0; i < argLen; i++) {
        std::cout << words[args[i]] << std::endl;
    }
}