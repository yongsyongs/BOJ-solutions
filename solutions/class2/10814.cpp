#include <iostream>

using namespace::std;

void CopyArray(int *A, int *B, int start, int end) {
    for(int i = start; i <= end; i++) B[i] = A[i];
}

void Swap(int *A, int i, int j) {
    int tmp = A[i];
    A[i] = A[j];
    A[j] = tmp;
}

// Stable 정렬 필요
void ArgMergeSort(int *A, int *P, int *Q, int left, int right) {
    if(left >= right) return;
    
    int mid = (left + right) / 2;

    ArgMergeSort(A, P, Q, left, mid);
    ArgMergeSort(A, P, Q, mid + 1, right);

    int iLeft = left, iRight = mid + 1, iMerged = left;
    while(iMerged <= right) {
        if(iLeft >= mid + 1) Q[iMerged++] = P[iRight++];
        else if(iRight > right) Q[iMerged++] = P[iLeft++];
        else if(A[P[iLeft]] > A[P[iRight]]) Q[iMerged++] = P[iRight++];
        else Q[iMerged++] = P[iLeft++];
    }

    CopyArray(Q, P, left, right);
}

int main() {
    int N;
    cin >> N;
    int *A = new int[N];
    int *P = new int[N];
    int *Q = new int[N]; 
    char **C = new char*[N];
    for(int i = 0; i < N; i++) {
        C[i] = new char[101];
        cin >> A[i];
        cin >> C[i];
        P[i] = i;
        Q[i] = i;
    }

    ArgMergeSort(A, P, Q, 0, N - 1);
    for(int i = 0; i < N; i++){
        printf("%d %s\n", A[P[i]], C[P[i]]); 
    }
}