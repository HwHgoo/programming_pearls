//
// Created by hu on 2021/2/3.
//

#ifndef CHAPTER_1_FILEOPERATION_H
#define CHAPTER_1_FILEOPERATION_H
void createFile(int maxFigure, int numOfFigure, char *filename);
//read file into bitmap
void writeMap(char *filename, int mapFigure, int **map);
//read file into an array
void writeArray(char *filename, int arraySize, int **array);
//write file with data of bitmap
void writeFileWithMap(char *outFile, int *map, int mapSize);
//wirte file wite data of array
void writeFileWithArray(char *outFile, int *array, int arraySize);
#endif //CHAPTER_1_FILEOPERATION_H
