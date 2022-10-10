#include <iostream>

void swap(int *arr, int i, int j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

int* BubbleArgSort(int N, int *A) {
    int *P = new int[N];
    for(int i = 0; i < N; i++)
        P[i] = i;

    for(int i = N - 1; i > 0; i--) {
        for(int j = 0; j < i; j++) {
            if(A[j] > A[j + 1]) {
                swap(A, j, j + 1);
                swap(P, j, j + 1);
            }
        }
    }

    int *Q = new int[N];
    for(int i = 0; i < N; i++)
        Q[P[i]] = i;

    return Q;
}

int main() {
    int N;
    std::cin >> N;
    int *A = new int[N];

    for(int i=0;i<N;i++)
        std::cin >> A[i];

    int *P = BubbleArgSort(N, A);
    for(int i = 0; i < N; i++)
        std::cout << P[i] << ' ';
}

