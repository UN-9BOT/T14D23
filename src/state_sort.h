#ifndef STS
#define STS
#include <stdio.h>
#include <stdlib.h>
typedef struct line {
    int year;
    int month;
    int day;
    int hour;
    int min;
    int sec;
    int status;
    int code;
} Line;
void menu(int choice);
char *input(int *flag);
void scanFile(char *path);
void sortFile(char *path);
void addLine(char *path);
void swap(FILE *fp, Line index1, Line index2, int n1, int n2);
void write(FILE *fp, Line *data, int index);
#endif
