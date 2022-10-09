#include <iostream>

using namespace::std;

long long GetCutLength(long long N, long long *L, long long H) {
    long long s = 0;
    for(long long i = 0; i < N; i++) {
        if(L[i] > H) s += L[i] - H;
    }

    return s;
}

int main() {
    long long N, M; // N: 나무의 수, M: 원하는 나무 길이
    cin >> N >> M;
    long long *L = new long long[N];
    long long min = 0, max = 0;
    for(long long i = 0; i < N; i++) {
        long long l; cin >> l;
        if(l > max) max = l;
        L[i] = l;
    }

    long long left = min, right = max;
    long long mid = (left + right) / 2;
    long long H;
    while(left <= right) {
        long long cutLength = GetCutLength(N, L, mid);
        if(cutLength >= M) {
            H = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
        mid = (left + right) / 2;
    }
    cout << H << endl;
}