#include <stdio.h>
#include <stdlib.h>
char *input(int *flag);

int main(void) {
    int flag = 0;
    char *path = input(&flag);
    FILE *fp;
    if ((fp = fopen(path, "r")) == NULL) {
        flag = 1;
    }
    return (0);
}

char *input(int *flag) {
    char *path = malloc(sizeof(char) * 250);
    (path == NULL) ? *flag = 1 : scanf("%249s", path);
    return (path);
}
