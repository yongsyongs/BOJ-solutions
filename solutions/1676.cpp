#include <iostream>
#define int long long

using namespace std;

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N; cin >> N;
    if(N < 5) {
        cout << 0 << endl;
        return 0;
    }
    
    int stack[2] = {0, 0};

    for(int i = 2; i <= N; i++) {
        int x = i;
        while(x > 0 && x % 2 == 0) {
            stack[0]++;
            x /= 2;
        }
        while(x > 0 && x % 5 == 0) {
            stack[1]++;
            x /= 5;
        }
    }
    
    int zeroCount = stack[0] > stack[1] ? stack[1] : stack[0];
    cout << zeroCount << endl;
}