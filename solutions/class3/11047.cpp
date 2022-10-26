#include <iostream>

using namespace::std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, K; cin >> N >> K;
    int *coins = new int[N];
    int cnt = 0;
    for(int i = 0; i < N; i++) cin >> coins[i];

    for(int i = N - 1; i >= 0; i--) {
        int x = coins[i];
        cnt += K / x;
        K = K % x;
    }
    cout << cnt << endl;
}