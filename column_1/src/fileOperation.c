//
// Created by hu on 2021/2/3.
//
#include "../include/fileOperation.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SHIFT 5
#define MASK 0x1F

void set(int num, int *map) { map[num >> SHIFT] |= (1 << (num & MASK)); }

// return 0 if the num is not in the map
int check(int num, int *map)
{
    int result = map[num >> SHIFT] & (1 << (num & MASK));
    return result;
}

void createFile(int maxFigure, int numberOfFigure, char *filename)
{
    int mapSize = maxFigure / 32 + 1;
    int *map = (int *)calloc(mapSize, sizeof(int));
    if (!map)
        return;
    FILE *fp = fopen(filename, "w+");
    srand((unsigned)time(NULL));
    //do loop until genrate enough numbers
    while (numberOfFigure)
    {
        int num = rand() % maxFigure;
        //check if num is in map
        int res = check(num, map);
        if (!res) // if num is not in map
        {
            set(num, map); // add num into map
            fprintf(fp, "%d ", num);
            numberOfFigure--;
        }
    }
    free(map);
    fclose(fp);
}

void writeMap(char *filename, int maxFigure, int **map)
{
    int mapSize = maxFigure / 32 + 1;
    *map = (int *)calloc(mapSize, sizeof(int));
    FILE *fp = fopen(filename, "r");
    if (!fp)
    {
        puts("write map error: file cannot be read\n");
        return;
    }
    int num;
    while (!feof(fp))
    {
        fscanf(fp, "%d ", &num);
        if (!check(num, *map))
            set(num, *map);
    }
    fclose(fp);
}

void writeArray(char *filename, int arraySize, int **array)
{
    *array = (int *)calloc(arraySize, sizeof(int));
    if (!array)
    {
        puts("write array error: array cannot be allocated\n");
        return;
    }
    FILE *fp = fopen(filename, "r");
    if (!fp)
    {
        puts("write array error: file cannot be read\n");
        return;
    }
    int index = 0;
    while (!feof(fp))
    {
        fscanf(fp, "%d ", *array + index);
        index++;
    }
    fclose(fp);
}

void writeFileWithMap(char *filename, int *map, int mapSize)
{
    FILE *fp = fopen(filename, "w+");
    if (!fp)
    {
        puts("write file with map error: cannot open file\n");
        return;
    }
    for (int i = 0; i < mapSize; i++)
    {
        for (int j = 0; j < 32; j++)
        {
            if (map[i] & (1 << j))
                fprintf(fp, "%d ", i * 32 + j);
        }
    }
    fclose(fp);
}

void writeFileWithArray(char *outFile, int *array, int arraySize)
{
    FILE *fp = fopen(outFile, "w+");
    if (!fp)
    {
        puts("write file with array error: cannot open file\n");
        return;
    }

    for (int i = 0; i < arraySize; i++)
    {
        fprintf(fp, "%d ", array[i]);
    }
    fclose(fp);
}