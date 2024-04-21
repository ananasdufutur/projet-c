#include "stdio.h"
#include "stdlib.h"
#ifndef UNTITLED5_FONCTION_H
#define UNTITLED5_FONCTION_H
#define REALOC_SIZE 256
#endif //UNTITLED5_FONCTION_H

typedef struct {
    int * T;
    int taille_phy;
    int taille_log;
    char* nom[30];
} COLUMN;

COLUMN * create_column(char *);
