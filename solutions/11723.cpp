#include <iostream>
#include <cstring>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N; cin >> N;
    int S[20];
    fill_n(S, 20, 0);
    for(int i = 0; i < N; i++) {
        char cmd[10]; cin >> cmd;
        if(strcmp(cmd, "all") == 0) {
            fill_n(S, 20, 1);
            continue;
        }
        else if(strcmp(cmd, "empty") == 0) {
            fill_n(S, 20, 0);
            continue;
        }

        int x; cin >> x;
        if(strcmp(cmd, "add") == 0)
            S[x - 1] = 1;
        else if(strcmp(cmd, "remove") == 0)
            S[x - 1] = 0;
        else if(strcmp(cmd, "check") == 0)
            cout << S[x - 1] << '\n';
        else if(strcmp(cmd, "toggle") == 0)
            S[x - 1] = S[x - 1] ? 0 : 1;
    }
}