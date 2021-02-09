//
// Created by hu on 2021/2/4.
//
#include "sort.h"
#include "fileOperation.h"
#include <time.h>

double bitmapSort(char *sourceFile, int maxFigure, char *outFile) {
    clock_t start, finish;
    start = clock();
    int *map;
    int mapSize = maxFigure / 32 + 1;
    writeMap(sourceFile, maxFigure, &map);
    writeFileWithMap(outFile, map, mapSize);
    finish = clock();
    return finish - start;
}

int getIndex(int *nums, int low, int high) {
    int tmp = nums[low];
    while (low < high) {
        while (low < high && nums[high] > tmp)
            high--;
        nums[low] = nums[high];
        while (low < high && nums[low] < tmp)
            low++;
        nums[high] = nums[low];
    }
    nums[low] = tmp;
    return low;
}

void qsort(int *nums, int low, int high) {
    if (low < high) {
        int index = getIndex(nums, low, high);
        qsort(nums, low, index - 1);
        qsort(nums, index + 1, high);
    }
}

double quicksort(char *sourceFile, int numOfFigure, char *outFile) {
    clock_t start, finish;
    start = clock();
    int *array;
    writeArray(sourceFile, numOfFigure, &array);
    finish = clock();
    return finish - start;
}

















