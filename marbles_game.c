#include<time.h>
#include<stdio.h>

int play_game(int blue, int red, int steps);

main() {
    srand(time(0));

    int blue;
    blue = play_game(6, 3, 0);
    print_f('%i', blue);
}

int play_game(int blue, int red, int steps) {
    if (steps == 0) {
        return blue;
    }
    int random;
    float threshold;
    random = rand() % 100; //get a random number 0 to 100
    threshold = blue / (red + blue);
    if (random <= threshold) {
        return play_game(blue + 1, red, steps - 1);
    }
    else {
        return play_game(blue, red + 1, steps - 1);
    }
}
