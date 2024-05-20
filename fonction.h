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
    char* nom;
} COLUMN;

COLUMN * create_column(char *);
int insert_value(COLUMN* col, int value);

void delete_column(COLUMN **col);

void print_column(COLUMN* col);

void value_added(int x);

int nb_occurrence(COLUMN* col, int x);

int val_x(COLUMN* col, int i);

int sup_x(COLUMN* col, int x);

int inf_x(COLUMN* col, int x);

int egale_x(COLUMN* col, int x);

void ajout_col_data(COLUMN ** T,COLUMN * col);

void renomm_col(COLUMN ** T,char * nom,char * nouveau_nom);

void suppr_col_data(COLUMN ** T,char * nom);

int recherche_val_data(COLUMN ** T,int val);

int return_val_data(COLUMN ** T,int ligne,int colonne);

void replace_val_data(COLUMN ** T,int ligne,int colonne,int val);

void affich_nom_col_data(COLUMN ** T);

void nb_ligne_colonne(COLUMN ** T);

int nb_val_eg_x(COLUMN ** T,int x);

int nb_val_sup_x(COLUMN ** T,int x);

int nb_val_inf_x(COLUMN ** T,int x);
