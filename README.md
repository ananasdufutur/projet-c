# projet-c

la premiere fonction ne marche pas et je sais pas pourquoi donc essaye de juste t'inspirer de la structure colonne(elle aussi est peut etre foireusee jsp)et lis bien le texte du projet 


(Mon code commence ligne 116)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLUMNS 100
#define INITIAL_CAPACITY 10
#define ALLOCATION_BLOCK_SIZE 256

typedef struct {
    char title[50];
    int *data;
    int logical_size;
    int physical_size;
} Column;

typedef struct {
    Column *columns[MAX_COLUMNS];
    int num_columns;
} CDataframe;

CDataframe* createCDataframe() {
    CDataframe *df = (CDataframe*)malloc(sizeof(CDataframe));
    if (df == NULL) {
        printf("Error: Memory allocation failed!\n");
        exit(1);
    }
    df->num_columns = 0;
    return df;
}

void addColumn(CDataframe *df, const char *title) {
    if (df->num_columns >= MAX_COLUMNS) {
        printf("Error: Maximum number of columns exceeded!\n");
        exit(1);
    }
    Column *col = (Column*)malloc(sizeof(Column));
    if (col == NULL) {
        printf("Error: Memory allocation failed!\n");
        exit(1);
    }
    strcpy(col->title, title);
    col->logical_size = 0;
    col->physical_size = INITIAL_CAPACITY;
    col->data = (int*)malloc(INITIAL_CAPACITY * sizeof(int));
    if (col->data == NULL) {
        printf("Error: Memory allocation failed!\n");
        exit(1);
    }
    df->columns[df->num_columns++] = col;
}

void displayCDataframe(CDataframe *df) {
    printf("CDataframe Contents:\n");
    for (int i = 0; i < df->num_columns; ++i) {
        printf("%s\t", df->columns[i]->title);
    }
    printf("\n");
    for (int row = 0; row < df->columns[0]->logical_size; ++row) {
        for (int col = 0; col < df->num_columns; ++col) {
            printf("%d\t", df->columns[col]->data[row]);
        }
        printf("\n");
    }
}

void freeCDataframe(CDataframe *df) {
    for (int i = 0; i < df->num_columns; ++i) {
        free(df->columns[i]->data);
        free(df->columns[i]);
    }
    free(df);
}

int main() {
    CDataframe *df = createCDataframe();

    addColumn(df, "Column1");
    addColumn(df, "Column2");
    addColumn(df, "Column3");

    for (int i = 0; i < 5; ++i) {
        df->columns[0]->data[i] = i + 1;
        df->columns[1]->data[i] = (i + 1) * 2;
        df->columns[2]->data[i] = (i + 1) * 3;
        df->columns[0]->logical_size++;
        df->columns[1]->logical_size++;
        df->columns[2]->logical_size++;
    }

    displayCDataframe(df);

    freeCDataframe(df);

    return 0;
}
