#include <iostream>

int main() {
    int N;
    std::cin >> N;

    int A[10001] = {};
    int maxVal;
    for(int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        A[x]++;
        if(x > maxVal) maxVal = x;
    }

    for(int i = 1; i <= 10000; i++) {
        int x = A[i];
        if(i > maxVal) break;
        if(x == 0) continue;
        for(int j = 0; j < x; j++) {
            printf("%d\n", i);
        }
    }
}