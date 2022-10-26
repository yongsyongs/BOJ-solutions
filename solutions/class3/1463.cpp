#include <iostream>

int pow(int x, int n) {
    int s = 1;
    for(int i = 0; i < n; i++)
        s *= x;
    
    return s;
}

int min2(int a, int b) {
    if(a < b)
        return a;
    else
        return b;
}

int main() {
    int X;
    std::cin >> X;

    int N = 1000001;
    int *A = new int[N];
    A[0] = 0;
    A[1] = 0;
    A[2] = 1;
    A[3] = 1;

    for(int i = 4; i < N; i++) {
        bool a = i % 2 == 0;
        bool b = i % 3 == 0;
        int s;
        if(a && b)
            s = min2(A[i / 2], A[i / 3]) + 1;
        else if(a)
            s = min2(A[i / 2] , A[i - 1]) + 1;
        else if(b)
            s = min2(A[i / 3] , A[i - 1]) + 1;
        else
            s = A[i - 1] + 1;
        A[i] = s;
    }
    std::cout << A[X] << std::endl;
}

