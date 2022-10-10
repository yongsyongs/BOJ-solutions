#include <iostream>

int main() {
    int N;
    std::cin >> N;

    double *scores = new double[N];
    double *newScores = new double[N];
    for(int i = 0; i < N; i++)
        std::cin >> scores[i];

    double maxScore = 0;
    for(int i = 0; i < N; i++) {
        if(scores[i] > maxScore)
            maxScore = scores[i];
    }

    double avgScore = 0;
    for(int i = 0; i < N; i++) {
        newScores[i] = scores[i] / maxScore * 100;
        avgScore += newScores[i];
    }
    
    avgScore /= static_cast<double>(N);

    printf("%.3f\n", avgScore);
}