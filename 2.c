#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define LINE_LENGTH 256
#define RED 12
#define GREEN 13
#define BLUE 14
#define DELIMITER ";"

bool possible_draw(char* draw) {
    return false;
}

int possible_game(char *line){
    char *t = line;
    t += strlen("GAME ");
    int game_num = atoi(t);
    while(*t != ' ') {
        t++;
    }
    char *token = strtok(t, DELIMITER);
    while (token != NULL) {
        // do something with token
    }
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