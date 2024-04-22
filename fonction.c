#include <stdio.h>
#include "fonction.h"
// Created by pouss on 20/04/2024.
//
COLUMN *create_column(char* title)
{
    COLUMN C={NULL,0,0,title};
    COLUMN * a = &C;
    return a;
}

int insert_value(COLUMN* col, int value)
{
    if (col->taille_phy>col->taille_log)
    {
        col->taille_log+=1;
        *((col->T)+col->taille_log) =value;
        return 1;
    }
    else
    {
        if (col->taille_phy==0)
        {

            col->T=(int *) malloc(256*sizeof(int ));
            col->taille_phy=256;
            col->taille_log=1;
            *(col->T+col->taille_log)=value;
            return 1;

        }
        else
        {
            col->T= realloc(col->T,col->taille_phy+256);
            col->taille_phy=col->taille_phy+256;
            col->taille_log+=1;
            *(col->T+col->taille_log)=value;
            return 1;
        }
    }
}

void delete_column(COLUMN **col);

void print_column(COLUMN* col)
{
    for (int i=0;i<col->taille_log;i++)
    {
        printf("%d",col->T+i);
    }
}

int nb_occurrence(COLUMN * col,int x)
{
    int a=0;
    for (int i=0;i<col->taille_log;i++)
    {
        if (*(col->T+i)==x)
        {
            a+=1;
        }
    }
    return a;
}

int val_x(COLUMN * col,int x)
{
    return *(col->T+x);
}

int sup_x(COLUMN * col,int x)
{
    int a=0;
    for (int i=0;i<col->taille_log;i++)
    {
        if (*(col->T+i)>x)
        {
            a+=1;
        }
    }
    return a;
}

int inf_x(COLUMN * col,int x)
{
    int a=0;
    for (int i=0;i<col->taille_log;i++)
    {
        if (*(col->T+i)<x)
        {
            a+=1;
        }
    }
    return a;
}

int egale_x(COLUMN * col,int x)
{
    int a=0;
    for (int i=0;i<col->taille_log;i++)
    {
        if (*(col->T+i)==x)
        {
            a+=1;
        }
    }
    return a;
}

CDataframe* createCDataframe() 
{ 
    CDataframe *df = (CDataframe*)malloc(sizeof(CDataframe));
    if (df == NULL)
    {
        printf("Error: Memory allocation failed!\n");
        exit(1); 
    }
    df->num_columns = 0;
    return df;
} 

void addColumn(CDataframe *df, const char *title) 
{
    if (df->num_columns >= MAX_COLUMNS)
    {
        printf("Error: Maximum number of columns exceeded!\n");
        exit(1);
    }
    Column *col = (Column*)malloc(sizeof(Column));
    if (col == NULL)
    {
        printf("Error: Memory allocation failed!\n");
        exit(1);
    }
    strcpy(col->title, title);
    col->logical_size = 0;
    col->physical_size = INITIAL_CAPACITY; col->data = (int*)malloc(INITIAL_CAPACITY * sizeof(int));
    if (col->data == NULL) 
    {
        printf("Error: Memory allocation failed!\n");
        exit(1); } df->columns[df->num_columns++] = col; 
    }
void displayCDataframe(CDataframe *df) 
    {
        printf("CDataframe Contents:\n");
        for (int i = 0; i < df->num_columns; ++i)
            {
                printf("%s\t", df->columns[i]->title);
            }
        printf("\n");
        for (int row = 0; row < df->columns[0]->logical_size; ++row)
            {
                for (int col = 0; col < df->num_columns; ++col) 
                {
                    printf("%d\t", df->columns[col]->data[row]);
                }
                printf("\n");
            }
    }
void freeCDataframe(CDataframe *df) 
{
    for (int i = 0; i < df->num_columns; ++i)
        {
            free(df->columns[i]->data); free(df->columns[i]);
        }
    free(df);
}

void ajout_col_data(COLUMN ** T,COLUMN * col)
{
    int i=0;
    while (T[i]!=0)
    {
        i++;
    }
    T[i+1]=col;
}

void renomm_col(COLUMN ** T,char * nom,char * nouveau_nom)
{
    int i=0;
    while (T[i]!=0 && T[i]->nom!=nom)
    {
        i++;
    }
    if(T[i]->nom==nom)
    {
        T[i]->nom=nouveau_nom;
    }
}

void suppr_col_data(COLUMN ** T,char * nom)
{
    int i=0;
    while (T[i]->nom!=nom)
    {
        i++;
    }
    if (T[i]==NULL && T[i+1]==NULL)
    {
        printf("erreur colonne non trouvée");
    }
    else
    {
        if (T[i+1]==NULL)
        {
            delete_column(T[i]);
        }
        else
        {
            delete_column(T[i]);
            while(T[i+1]!=NULL)
            {
                T[i+1]=T[i];
            }
        }
    }
}

int recherche_val_data(COLUMN ** T,int val)
{
    int i=0;
    while (T[i]!=0)
    {
        i++;
    }
    for (int j=0;j<i;j++)
    {
        for (int k=0;k<T[j]->taille_log;k++)
        {
            if (*(T[j]->T+k)==val)
            {
                return 1;
            }
        }
    }
    return 0;
}

int return_val_data(COLUMN ** T,int ligne,int colonne)
{
    if (T[colonne]==NULL || ligne>T[colonne]->taille_log)
    {
        printf("index out of range");
        return 0;
    }
    else
    {

        return *(T[colonne]->T+ligne);
    }
}

void replace_val_data(COLUMN ** T,int ligne,int colonne,int val)
{
    if (T[colonne]==NULL || ligne>T[colonne]->taille_log)
    {
        printf("index out of range");
    }
    else
    {
        *(T[colonne]->T+ligne)=val;
    }
}

void affich_nom_col_data(COLUMN ** T)
{
    int i=0;
    while (T[i]!=NULL)
    {
        printf("%s",T[i]->nom);
    }
}

void nb_ligne_colonne(COLUMN ** T)
{
    int i=0;
    while(T[i]!=NULL)
    {
        i++;
    }
    if (T[0]->taille_log==0)
    {
        printf("%d,%d",0,i-1);
    }
    else
    {
        int j=0;
        while(*(T[0]->T+j)!=0)
        {
            j++;
        }
        printf("%d,%d",j-1,i-1);
    }
}

int nb_val_eg_x(COLUMN ** T,int x)
{
    int i=0;
    int a=0;
    while (T[i]!=0)
    {
        i++;
    }
    for (int j=0;j<i;j++)
    {
        for (int k=0;k<T[j]->taille_log;k++)
        {
            if (*(T[j]->T+k)==x)
            {
                a+=1;
            }
        }
    }
    return a;
}

int nb_val_sup_x(COLUMN ** T,int x)
{
    int i=0;
    int a=0;
    while (T[i]!=0)
    {
        i++;
    }
    for (int j=0;j<i;j++)
    {
        for (int k=0;k<T[j]->taille_log;k++)
        {
            if (*(T[j]->T+k)>x)
            {
                a+=1;
            }
        }
    }
    return a;
}

int nb_val_inf_x(COLUMN ** T,int x)
{
    int i=0;
    int a=0;
    while (T[i]!=0)
    {
        i++;
    }
    for (int j=0;j<i;j++)
    {
        for (int k=0;k<T[j]->taille_log;k++)
        {
            if (*(T[j]->T+k)<x)
            {
                a+=1;
            }
        }
    }
    return a;
}
