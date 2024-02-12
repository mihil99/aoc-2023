#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define LINE_LENGTH 256
#define RED 12
#define GREEN 13
#define BLUE 14
#define GAME_DELIMITER ";"
#define DRAW_DELIMITER ","

bool possible_draw(char* draw) {
  draw++;
  int amount = atoi(draw);
  while (*draw != ' ') draw ++;
  draw++;
  if (strcmp("red", draw) == 0) {
    return amount <= RED;
  }
  if (strcmp("green", draw) == 0) {
    return amount <= GREEN;
  }
  if (strcmp("blue", draw) == 0) {
    return amount <= BLUE;
  }
  return false;
}

int possible_game(char *line){
    char *t = line;
    t += strlen("GAME ");
    int game_num = atoi(t);
    printf("GAME: %d\n", game_num);
    while(*t != ' ') {
        t++;
    }
    // LOOP OVER GAMES WITHIN LINE
    char *game_info = strtok(t, GAME_DELIMITER);
    while (game_info != NULL) {
      char *cur_game = strdup(game_info);
      printf("%s\n", cur_game);
      game_info = strtok(NULL, GAME_DELIMITER);
    }
    return game_num;
}


int main(int argc, char** argv)
{
  char filename[LINE_LENGTH];
  (void)argc; //Cast to get rid of compiler warning
  strcpy(filename, argv[1]);
  // PART 1
  FILE *fp = fopen(filename, "r");
  char line[LINE_LENGTH];
  int sum = 0;

  while(fgets(line, LINE_LENGTH, fp) != NULL) {
    sum += possible_game(line);
  }
  fclose(fp);

  printf("Part 1: %d\n", sum);
  return 0;
}