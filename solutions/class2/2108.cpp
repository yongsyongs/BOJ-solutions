#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

double GetMean(double *arr, int N) {
    double sum = 0;
    for(int i = 0; i < N; i++)
        sum += arr[i];
    
    return sum / N;
}

int GetMode(int *count) {
    int mode = -1;
    int dupMode = -1;
    int maxCount = 0;
    bool isDupMode = false;
    for(int i = 8000; i >= 0; i--) {
        if(count[i] > maxCount) {
            maxCount = count[i];
            mode = i - 4000;
            isDupMode = false;
        }
        else if(count[i] == maxCount) {
            isDupMode = true;
            dupMode = mode;
            mode = i - 4000;
        }
    }
    if(isDupMode) return dupMode;
    else return mode;
}

int main() {
    int N;
    std::cin >> N;
    double *arr = new double[N];
    int count[8001] = {};
    
    for(int i = 0; i < N; i++) {
        std::cin >> arr[i];
        count[static_cast<int>(arr[i]) + 4000]++;
    }

    sort(arr, arr + N);

    double mean = GetMean(arr, N);
    int median = static_cast<int>(arr[N / 2]);
    int mode = GetMode(count);
    int range = static_cast<int>(arr[N - 1] - arr[0]);
    printf("%d\n", static_cast<int>(round(mean)));
    printf("%d\n", median);
    printf("%d\n", mode);
    printf("%d\n", range);
}