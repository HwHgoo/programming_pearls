#include <stdio.h>
#include "include/fileOperation.h"

int main()
{
  char *filename = "numbers.txt";
  // printf("Hello, World!\n");
  createFile(10000000, 1000000, filename);
  printf("program ended..\n");
  return 0;
}
