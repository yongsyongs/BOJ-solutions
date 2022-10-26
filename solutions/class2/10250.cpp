#include <iostream>

int main() {
    int T;
    std::cin >> T;

    while(T--) {
        int H, W, N;
        int floor = 0;
        int room = 0;
        std::cin >> H >> W >> N;
        if(H == 1) {
            floor = 1;
            room = N;
        }
        else if(W == 1) {
            floor = N;
            room = 1;
        }
        else {
            floor = N % H;
            room = N / H + 1;
            room = floor ? room : room - 1;
            floor = floor ? floor : H;
        }
        std::cout << floor * 100 + room << std::endl;
    }
}