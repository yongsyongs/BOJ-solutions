#include <iostream>
#include <algorithm>

using namespace::std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    int cards[500000];
    cin >> N;
    for(int i = 0; i < N; i++) cin >> cards[i];
    sort(cards, cards + N);
    
    cin >> M;
    int x, c;
    while(M--) {
        cin >> x;
        c = upper_bound(cards, cards + N, x) - lower_bound(cards, cards + N, x);
        cout << c << ' ';
    }
}