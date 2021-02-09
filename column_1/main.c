#include <stdio.h>
#include "include/sort.h"
#include "include/fileOperation.h"

int main()
{
  char *sourceFile = "numbers.txt";
  char *mapOutFile = "mapOut.txt";
  char *qsortOutFile = "qsortOut.txt";
  int maxFigure = 10000000;
  int numOfFigure = 1000000;
  createFile(maxFigure, numOfFigure, sourceFile);

  double bitmapTime = bitmapSort(sourceFile, maxFigure, mapOutFile);
  double qsortTime = quickSort(sourceFile, numOfFigure, qsortOutFile);
  printf("time bitmap consumed: %f ms\n", bitmapTime);
  printf("time qsort consumed: %f ms\n", qsortTime);
  printf("program ended..\n");
  return 0;
}
