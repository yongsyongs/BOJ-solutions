#include <iostream>

int main() {
    int x, y, w, h;
    std::cin >> x;
    std::cin >> y;
    std::cin >> w;
    std::cin >> h;
    int dx, dy, d;
    if(x <= (w / 2)) dx = x;
    else dx = w - x;
    
    if(y <= (h / 2)) dy = y;
    else dy = h - y;

    if(dx < dy) d = dx;
    else d = dy;

    std::cout << d;
}