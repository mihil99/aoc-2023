#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define LINE_LENGTH 256

// one, two, three, four, five, six, seven, eight, nine
const char nums[9][6] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

int extract_num(char* c) {
  if (isdigit(*c)) return *c - '0';
  for (size_t i = 0; i < 9; i++)
  {
    if (strncmp(c, nums[i], strlen(nums[i])) == 0) return i+1;
  }
  return -1;
}

int extract_number(char *line) {
  char *first = line;
  while( !isdigit(*first)) first++;
  char *last = line + strlen(line);
  while( !isdigit(*last)) last--;
  return 10*(*first - '0') + (*last - '0');
}

int extract_number2(char *line) {
  char *first = line;
  while (extract_num(first) == -1) first++;
  char *last = line+strlen(line);
  while (extract_num(last) == -1) last--;
  return 10*(extract_num(first)) + extract_num(last);
}

int main()
{
  // PART 1
  const char *filename = "./1.input";
  FILE *fp = fopen(filename, "r");

  char line[LINE_LENGTH];
  int sum = 0;

  while( fgets(line, LINE_LENGTH, fp) != NULL) {
    sum += extract_number(line);
  }

  printf("Part 1: %d\n", sum);
  fclose(fp);

  // PART 2
  fp = fopen(filename, "r");
  sum = 0;

  while( fgets(line, LINE_LENGTH, fp) != NULL) {
    int n = extract_number2(line);
    sum += n;
    // printf("%s => %d\n", line, n);
  }

  printf("Part 1: %d\n", sum);
  fclose(fp);

  return 0;
}
