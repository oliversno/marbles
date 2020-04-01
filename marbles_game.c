#include<time.h>
#include<stdio.h>
#include<stdlib.h>

int play_game(int blue, int red, int steps);
void invalid_input();

int main() {
    srand(time(0));
    int init_blue, init_red, num_rounds, num_games;
    printf("%s", "Number of blue marbles to start: ");
    if(!scanf("%i", &init_blue)) {
      invalid_input();
      return 1;
    }
    printf("%s", "Number of red marbles to start: ");
    if(!scanf("%i", &init_red)) {
      invalid_input();
      return 1;
    }
    printf("%s", "Number rounds to play: ");
    if(!scanf("%i", &num_rounds)) {
      invalid_input();
      return 1;
    }
    printf("%s", "Number games to play: ");
    if(!scanf("%i", &num_games)) {
      invalid_input();
      return 1;
    }
    for (int i = 1; i <= num_games; ++i) {
      int num_blue;
      num_blue = play_game(init_blue, init_red, num_rounds);
      printf("%s %i: %i %s %i \n", "Game" , i, num_blue, "blue marbles at round",   num_rounds);
    }
}

int play_game(int blue, int red, int steps) {
  while(steps > 0) {
    int random;
    float threshold;
    random = rand() % 100;
    threshold = (float)blue / (red + blue);
    if(random <= threshold*100) {
      blue = blue + 1;
    }
    else {
      red = red + 1;
    }
    steps = steps - 1;
  }
  return blue;
}

void invalid_input(){
  printf("%s \n", "ERROR: Invalid Input");
}