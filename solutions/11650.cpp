#include <iostream>
#include <algorithm>

using namespace::std;

bool IsGreater(int *X, int *Y, int i, int j) {
    return (X[i] > X[j]) || (X[i] == X[j] && Y[i] > Y[j]);
}

void Swap(int *X, int *Y, int i, int j) {
    int tmp = X[i]; X[i] = X[j]; X[j] = tmp;
    tmp = Y[i]; Y[i] = Y[j]; Y[j] = tmp;
}

int partition(int *X, int *Y, int left, int right, int pivot) {
    if(left >= right) return left;
    int storeIdx = left;
    Swap(X, Y, right, pivot);

    for(int i = left; i < right; i++) {
        if(IsGreater(X, Y, i, right)) {
            Swap(X, Y, i, storeIdx);
            storeIdx++;
        }
    }
    Swap(X, Y, right, storeIdx);
    return storeIdx;
}

void QuickSort(int *X, int *Y, int left, int right) {
    if(left >= right) return;

    int pivot = (left + right) / 2;
    int newPivot = partition(X, Y, left, right, pivot);
    QuickSort(X, Y, left, newPivot);
    QuickSort(X, Y, newPivot + 1, right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    int *X, *Y;
    cin >> N; X = new int[N]; Y = new int[N];

    for(int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        X[i] = x; Y[i] = y;
    }

    QuickSort(X, Y, 0, N - 1);
    
    for(int i = N - 1; i >= 0; i--)
        cout << X[i] << ' ' << Y[i] << '\n';
}