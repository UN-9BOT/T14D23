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
void prFile(char *path);
void sortFile(char *path);
void addLine(char *path);
/* void destroy(Line **data, int counterStruct); */


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

char *input() {
    char *path = malloc(sizeof(char) * 250);
    scanf("%249s", path);
    return (path);
}

void prFile(char *path) {
    FILE *fp = fopen(path, "rb");
    int counterStruct = 0;
    Line *data = (Line *)malloc(sizeof(Line) * 5000);
    /* Line value; */

    while (fread(&data[counterStruct], sizeof(Line), 1, fp)) {
        printf("%d %d %d %d %d %d %d %d\n", data[counterStruct].year, data[counterStruct].month,
               data[counterStruct].day, data[counterStruct].hour, data[counterStruct].min,
               data[counterStruct].sec, data[counterStruct].status, data[counterStruct].code);
    }

    /* while (fread(&value, sizeof(Line), 1, fp)) { */
    /*     data[counterStruct] = malloc(sizeof(Line)); */
    /*     data[counterStruct]->year = value.year; */
    /*     data[counterStruct]->month = value.month; */
    /*     data[counterStruct]->day = value.day; */
    /*     data[counterStruct]->hour = value.hour; */
    /*     data[counterStruct]->min = value.min; */
    /*     data[counterStruct]->sec = value.sec; */
    /*     data[counterStruct]->status = value.status; */
    /*     data[counterStruct]->code = value.code; */
    /*     printf("%d %d %d %d %d %d %d %d\n", data[counterStruct]->year, data[counterStruct]->month, */
    /*            data[counterStruct]->day, data[counterStruct]->hour, data[counterStruct]->min, */
    /*            data[counterStruct]->sec, data[counterStruct]->status, data[counterStruct]->code); */
    /* } */
    fclose(fp);
    free(data);
    /* destroy(data, counterStruct); */
    
}

/* void destroy(Line **data, int counterStruct) { */
/*     while (counterStruct-- != 0) { */
/*         free(data[counterStruct]); */
/*     } */
/*     free(data); */
/* } */

