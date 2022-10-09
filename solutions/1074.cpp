#include <iostream>

using namespace::std;

int FindPos(int X, int r, int c) {
    if(X == 2) {
        if(r && c) return 3;
        else if(r && !c) return 2;
        else if(!r && c) return 1;
        else return 0;
    }
    int half = X / 2;
    int cube = half * half;
    int offset;
    if(r < half) offset = c < half ? 0 : cube;
    else offset = c < half ? cube * 2 : cube * 3;

    return offset + FindPos(half, r % half, c % half);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, r, c; cin >> N >> r >> c;
    int X = 1;
    for(int i = 0; i < N; i++) X *= 2;

    cout << FindPos(X, r, c) << endl;
}