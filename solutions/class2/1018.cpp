#include <iostream>

using namespace::std;

int B1[8][8] = {
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
};
int B2[8][8] = {
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
};

int** Slice(int **board, int rOffset, int cOffset) {
    int **sliced = new int*[8];

    for(int i = 0; i < 8; i++) {
        sliced[i] = new int[8];
        for(int j = 0; j < 8; j++) {
            sliced[i][j] = board[i + rOffset][j + cOffset];
        }
    }
    return sliced;
}

int Compare1(int **A) {
    int cnt = 0;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(A[i][j] != B1[i][j]) cnt++;
        }
    }
    return cnt;
}

int Compare2(int **A) {
    int cnt = 0;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(A[i][j] != B2[i][j]) cnt++;
        }
    }
    return cnt;
}

int GetMinimumCount(int **X) {
    int a = Compare1(X);
    int b = Compare2(X);
    int x = a < b ? a : b;
    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, M; cin >> N >> M;
    int maxRowStride = N - 8 + 1;
    int maxColStride = M - 8 + 1;
    int **board = new int*[N];

    for(int i = 0; i < N; i++) {
        board[i] = new int[M];
        for(int j = 0; j < M; j++) {
            char c; cin >> c;
            board[i][j] = c == 'W';
        }
    }

    int min = 100000000;
    for(int i = 0; i < maxRowStride; i++) {
        for(int j = 0; j < maxColStride; j++) {
            int **sliced = Slice(board, i, j);
            int cnt = GetMinimumCount(sliced);
            if(cnt < min) min = cnt;
        }
    }
    cout << min << endl;
}