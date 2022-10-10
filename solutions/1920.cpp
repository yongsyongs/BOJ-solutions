#include <iostream>
#include <algorithm>

int BinarySearch(long int *A, long int x, int N) {
    int left = 0, right = N, mid;
    while(left <= right) {
        mid = (left + right) / 2;
        if(A[mid] == x) break;
        if(A[mid] > x) right = mid - 1;
        else left = mid + 1;
    }
    if(A[mid] == x)
        return 1;
    else 
        return 0;
}

int main() {
    int N;
    std::cin >> N;
    long int *A = new long int [N];
    
    for(int i = 0; i < N; i++)
        std::cin >> A[i];

    std::sort(A, A + N);

    int M;
    std::cin >> M;
    long int *X = new long int[M];
    for(int i = 0; i < M; i++)
        std::cin >> X[i];

    for(int i = 0; i < M; i++)
        std::cout << BinarySearch(A, X[i], N) << '\n';
}