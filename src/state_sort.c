#include <stdio.h>
#include <stdlib.h>

void menu(int choice);
char* input();
void prFile(char *path);
void sortFile(char *path);
void addLine(char *path);

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
            prFile(path);
            break;
        case 1:

            break;
        case 2:

            break;
    }
    free(path);
}

char* input() {
    char* path = malloc(sizeof(char) * 250);
    scanf("%249s", path);
    return (path);
}

void prFile(char *path) {
    FILE * fp = fopen(path, "rb");
    /* int counterFields = 0; */
    int counterStruct = 0;
    Line* value = malloc(sizeof(Line));;
    Line* data = malloc(sizeof(Line*) * 5000);

    while (fread(&value, sizeof(int), 1, fp)) {
        /* if (counterFields == 8) { */
        /*     counterStruct++; */
        /*     counterFields = 0; */
        /* } */ 
        data[counterStruct].year = value.year;
        data[counterStruct].month = value.month;
        data[counterStruct].day = value.day;
        data[counterStruct].hour = value.hour;
        data[counterStruct].min = value.min;
        data[counterStruct].sec = value.sec;
        data[counterStruct].status = value.status;
        data[counterStruct].code = value.code;
        /* counterFields++; */
        printf("%5d %5d %5d %5d %5d %5d %5d %5d\n", data[counterStruct].year, data[counterStruct].month, data[counterStruct].day, data[counterStruct].hour, data[counterStruct].min, data[counterStruct].sec, data[counterStruct].status, data[counterStruct].code);
        counterStruct++;
        }

            /* switch (counterFields++) { */
            /*     case 0: */
            /*         data[counterStruct].year = value.year; */
            /*         break; */
            /*     case 1: */
            /*         data[counterStruct].month = value.month; */
            /*         break; */
            /*     case 2: */
            /*         data[counterStruct].day = value.day; */
            /*         break; */
            /*     case 3: */
            /*         data[counterStruct].hour = value.hour; */
            /*         break; */
            /*     case 4: */
            /*         data[counterStruct].min = value.min; */
            /*         break; */
            /*     case 5: */
            /*         data[counterStruct].sec = value.sec; */
            /*         break; */
            /*     case 6: */
            /*         data[counterStruct].status = value.status; */
            /*         break; */
            /*     case 7: */
            /*         data[counterStruct].code = value.code; */
            /*         break; */
            /* } */
    fclose(fp);
}




