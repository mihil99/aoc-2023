#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// extract number inspired by https://github.com/janiorca/advent-of-code-2023/blob/main/aoc1.c
#define LINE_LENGTH 256

const char nums[9][6] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

int char_to_num(char* c, bool check_words) {
  if ( isdigit(*c) ) return *c - '0';
  if ( !check_words ) return -1;
  for (size_t i = 0; i < 9; i++)
  {
    if (strncmp(c, nums[i], strlen(nums[i])) == 0) return i+1;
  }
  return -1;
}

int extract_num_from_line(char *line, bool check_words) {
  char *first = line;
  while (char_to_num(first, check_words) == -1) first++;
  char *last = line+strlen(line);
  while (char_to_num(last, check_words) == -1) last--;
  return 10*(char_to_num(first, check_words)) + char_to_num(last, check_words);
}

int main()
{
  // PART 1
  const char *filename = "./1.input";
  FILE *fp = fopen(filename, "r");
  char line[LINE_LENGTH];
  int sum = 0;
  while( fgets(line, LINE_LENGTH, fp) != NULL) {
    sum += extract_num_from_line(line, false);
  }
  printf("Part 1: %d\n", sum);
  fclose(fp);
  // PART 2
  fp = fopen(filename, "r");
  sum = 0;
  while( fgets(line, LINE_LENGTH, fp) != NULL) {
    int n = extract_num_from_line(line, true);
    sum += n;
  }
  printf("Part 1: %d\n", sum);
  fclose(fp);
  return 0;
}
