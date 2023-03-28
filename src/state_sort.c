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
char *input();
void scanFile(char *path);
void sortFile(char *path);
void addLine(char *path);
void swap(FILE *fp, Line index1, Line index2, int n1, int n2);
void write(FILE *fp, Line *data, int index);

int main(void) {
    int n, trash;
    if ((scanf("%d.%d", &n, &trash)) != 1) {
        printf("n/a\n");
    } else {
        menu(n);
    }

    return (0);
}

void menu(int n) {
    char *path = input();
    switch (n) {
        case 0:
            scanFile(path);
            break;
        case 1:
            sortFile(path);
            scanFile(path);
            break;
        case 2:
            addLine(path);
            sortFile(path);
            scanFile(path);
            break;
    }
    free(path);
}

void addLine(char *path) {
    FILE *fp = fopen(path, "a");
    Line value;
    int *ptr = &(value.year);
    for (int i = 0; i < 8; ptr++, i++) {
        scanf("%d", ptr);
    }
    fwrite(&value, sizeof(Line), 1, fp);
    fclose(fp);
}

char *input() {
    char *path = malloc(sizeof(char) * 250);
    scanf("%249s", path);
    return (path);
}

void scanFile(char *path) {
    FILE *fp = fopen(path, "rb");
    Line value;
    while (fread(&value, sizeof(Line), 1, fp)) {
        printf("%d %d %d %d %d %d %d %d\n", value.year, value.month, value.day, value.hour, value.min,
               value.sec, value.status, value.code);
    }
    fclose(fp);
}

int fifle(Line first, Line second) {
    int total = 0;
    int *ptr1 = &(first.year);
    int *ptr2 = &(second.year);
    for (int i = 0; !total && i < 6; i++) {
        if (*ptr1 > *ptr2) {
            total = 1;
        }
        if (*ptr1 < *ptr2) {
            total = -1;
        }
        ptr1++;
        ptr2++;
    }
    return (total);
}

void sortFile(char *path) {
    FILE *fp = fopen(path, "rb+");

    fseek(fp, SEEK_CUR, SEEK_END);
    int size = ftell(fp) / sizeof(Line);
    Line first;
    Line second;
    fseek(fp, SEEK_CUR, SEEK_SET);
    for (int i = 0; i < size; i++) {
        int j = 0;
        while (j < size - 1) {
            fseek(fp, sizeof(Line) * j, SEEK_SET);
            fread(&first, sizeof(Line), 1, fp);
            fread(&second, sizeof(Line), 1, fp);
            int total = fifle(first, second);
            if (total == 1) {
                swap(fp, first, second, j, j + 1);
            }
            j++;
        }
    }
    fclose(fp);
}

void swap(FILE *fp, Line first, Line second, int index1, int index2) {
    fseek(fp, index1 * sizeof(Line), SEEK_SET);
    fwrite(&second, sizeof(Line), 1, fp);
    fseek(fp, index2 * sizeof(Line), SEEK_SET);
    fwrite(&first, sizeof(Line), 1, fp);
}
