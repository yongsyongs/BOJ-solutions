#include <iostream>

int main() {
    int n, k;
    std::cin >> n >> k;

    int x = 1;
    int a = 1;
    int b = 1;
    int c = 1;
    for(int i = 1; i <= n; i++) {
        x *= i;
        if(i == k) {
            b = x;
        }
        if(i == n - k) {
            c = x;
        }
    }
    a = x;

    std::cout << a / (b * c) << std::endl;
}