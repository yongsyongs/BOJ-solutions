#include <iostream>

using namespace::std;

int GetBuildTime(int N, int M, int **ground, int targetHeight) {
    int sumOfTime = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            int d = targetHeight - ground[i][j];
            if(d > 0)
                sumOfTime += d;
            else
                sumOfTime -= d * 2;
        }
    }
    return sumOfTime;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, M, B; cin >> N >> M >> B;
    int **ground = new int*[N];
    int minHeight = 256, maxHeight = 0;
    int sumOfGround = 0;
    
    for(int i = 0; i < N; i++) {
        ground[i] = new int[M];
        for(int j = 0; j < M; j++) {
            int h; cin >> h;
            ground[i][j] = h;
            sumOfGround += h;
            if(h > maxHeight) maxHeight = h;
            if(h < minHeight) minHeight = h;
        }
    }

    int maxPossibleHeight = (sumOfGround + B) / (N * M); maxPossibleHeight = maxPossibleHeight > 256 ? 256 : maxPossibleHeight;
    int minPossibleHeight = minHeight;
    int targetHeight = sumOfGround / (N * M);
    int minTime = GetBuildTime(N, M, ground, targetHeight);
    for(int h = minPossibleHeight; h <= maxPossibleHeight; h++) {
        int t = GetBuildTime(N, M, ground, h);
        if(t < minTime) {
            minTime = t;
            targetHeight = h;
        }
        else if(t == minTime && h > targetHeight) {
            minTime = t;
            targetHeight = h;
        }
    }
    cout << minTime << ' ' << targetHeight << endl;
}