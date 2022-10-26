#include <iostream>
int main() {
    int T;
    std::cin >> T;
    while(T--) {
        int k, n;
        int **P = new int*[k];
        std::cin >> k >> n;
        for(int i = 0; i <= k; i++) {
            int x = n + 1;
            P[i] = new int[x];
            P[i][0] = 0;
            P[i][1] = 1;
            for(int j = 1; j <= n; j++) {
                if(i) {
                    P[i][j] = P[i][j - 1] + P[i - 1][j];
                }
                else {
                    P[i][j] = j;
                }
            }
        }
        std::cout << P[k][n] << std::endl;
    }

}