//
// Created by hu on 2021/2/3.
//

#include "fileOperation.h"
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
    int mapSize = maxFigure / 5 + 1;
    int *map = (int *)calloc(mapSize, sizeof(int));
    if (!map)
        return;
    FILE *fp = fopen(filename, "w+");
    srand((unsigned)time(NULL));
    while (numberOfFigure)
    {
        // printf("%d\n", numberOfFigure);
        int num = rand() % maxFigure;
        int res = check(num, map);
        if (!res)
        {
            set(num, map);
            fprintf(fp, "%d ", num);
            numberOfFigure--;
        }
    }
    free(map);
    fclose(fp);
}

void writeMap(char *filename, int maxFigure, int **map)
{
    int mapSize = maxFigure / 5 + 1;
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
        fscanf(fp, "%d", &num);
        if (!check(num, *map))
            set(num, *map);
    }
    fclose(fp);
}

void writeArray(char *filename, int numOfFigure, int **array)
{
    *array = (int *)calloc(numOfFigure, sizeof(int));
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
        fscanf(fp, "%d ", array + index);
        index++;
    }
    fclose(fp);
}

void writeFileWithMap(char *filename, int *map, int mapSize)
{
    int mask = 1;
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
            mask = mask << j;
            if (map[i] & mask)
                fprintf(fp, "%d ", i * 32 + j);
        }
        mask = 1;
    }
    fclose(fp);
}
