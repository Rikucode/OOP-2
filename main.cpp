#include <iostream>
#include <chrono>
#include <cmath>
// мишень 0-5 по х y, 5 выстрелов, баллы от 5 до 0 за единицу от радиуса, меньше 10 очков - написать лузер, до 2 условных оператора и не забыть побитовый. летс гоу

int main() {
    double x, y;
    double maxCoord = 5;
    int numOfShoots = 5;
    int scoreToWin = 10;
    int score = 0;
    double rad;

    srand(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()));

    for (int i = 1; i <= numOfShoots; ++i) {
        std::cout <<"\nAttempt #" << i << ":";
        std::cin >> x >> y;
        //Убедимся что пользователь не ввел число больше 5 по модулю не используя условный оператор
        x = std::min(5.0,x);
        x = std::max(-5.0,x);
        y = std::min(5.0,y);
        y = std::max(-5.0,y);
        //добавим к выстрелу случайное изменение координат от -5 до 5
        x = x + ((-maxCoord) + static_cast <float> (rand()) /( static_cast <float> (((1 << (sizeof(RAND_MAX)*8-1)) - 1)/(maxCoord-(-maxCoord)))));
        y = y + ((-maxCoord) + static_cast <float> (rand()) /( static_cast <float> (((1 << (sizeof(RAND_MAX)*8-1)) - 1)/(maxCoord-(-maxCoord)))));
        //не сохраняем выстрелы, считаем расстояние от попадания до центра и даем очки сразу же;
        rad = sqrt(pow(x,2)+pow(y,2));
        score += std::max(0 ,5 - static_cast<int>(floor(rad)));
        std::cout << "X " << "Y " << "Distance " << "Score" << std::endl;
        std::cout << x << " " << y << " " << rad << " " << std::max(0 ,5 - static_cast<int>(floor(rad))) << std::endl;
    }
    std::cout << "----------------------------------" << std::endl;
    std::cout << "Your score is " << score << "!" << std::endl;
    (score < scoreToWin) ? std::cout << "You Lose! (Better luck next time!)" : std::cout << "You Rock! (Keep it up!)";

    return 0;
}

