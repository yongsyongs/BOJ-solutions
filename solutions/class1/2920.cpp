#include <iostream>

int main() {
    int scales[8];
    for(int i = 0; i < 8; i++)
        std::cin >> scales[i];
    
    bool hasAnyAsc = false;
    bool hasAnyDesc = false;
    for(int i = 0; i < 7; i++) {
        hasAnyAsc = hasAnyAsc || scales[i] < scales[i + 1];
        hasAnyDesc = hasAnyDesc || scales[i] > scales[i + 1];
    }
    
    if(hasAnyAsc && hasAnyDesc)
        std::cout << "mixed" << std::endl;
    else if(hasAnyAsc && !hasAnyDesc)
        std::cout << "ascending" << std::endl;
    else if(hasAnyDesc && !hasAnyAsc)
        std::cout << "descending" << std::endl;
}