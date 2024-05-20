#include <stdio.h>
#include "fonction.h"
#include <string.h>
// Created by pouss on 20/04/2024.

//Guillaume pousse:j'ai fais toutes les fonctions
//fonction qui crée une colonne
COLUMN *create_column(char* title)
{
    COLUMN* col = (COLUMN*)malloc(sizeof(COLUMN));
    col->nom =  (char*)malloc(strlen(title));
    strcpy(col->nom, title);

    //col->titre=strdup(title);
    col -> T = malloc(256 * sizeof(int));
    col -> taille_phy = 256;
    col -> taille_log = 0;
    return col;
}
//fonction qui renvoie un message si une valeur a été ajoutée avec succès a une colonne
void value_added(int x)
{
    if(x)
        printf("\n Value added successfully to my column\n");
    else
        printf("Error adding value to my column\n");
}
//fonction qui rajoute une valeure dans une colonne
int insert_value(COLUMN* col, int value)
{
    if (col->taille_phy>col->taille_log)
    {

        *((col->T)+col->taille_log) =value;
        col->taille_log+=1;
        return 1;
    }
    else
    {
        if (col->taille_phy==0)
        {

            col->T=(int *) malloc(256*sizeof(int ));
            col->taille_phy=256;

            *(col->T+col->taille_log)=value;
            col->taille_log=1;
            return 1;

        }
        else
        {
            col->T= realloc(col->T,col->taille_phy+256);
            col->taille_phy=col->taille_phy+256;

            *(col->T+col->taille_log)=value;
            col->taille_log+=1;
            return 1;
        }
    }
}
//fonction qui print les différentes valeurs d'une colonne
void print_column(COLUMN* col)
{
    for (int i=0;i<col->taille_log;i++)
    {
        printf("%d ",*(col->T+i));
    }
}
//fonction qui print le nombre d'occurrences d'une valeur dns une colonne
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
//fonction qui cherche une valeur dans une colonne
int val_x(COLUMN * col,int x)
{
    return *(col->T+x);
}
//fonction qui compte le nombre de valeurs d'une colonne qui sont supérieures a x
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
//fonction qui compte le nombre de valeurs d'une colonne qui sont inférieures a x
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
//fonction qui compte le nombre de valeurs d'une colonne qui sont égales a x
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


//fonction qui ajoute une colonne a une liste de colonne
void ajout_col_data(COLUMN ** T,COLUMN * col)
{
    if(T==NULL){
        T=&col;
    }
    int i=0;
    while (T[i]!=0)
    {
        i++;
    }
    T[i]=col;
}
//fonction qui renomme une colonne d'une liste de colonne
void renomm_col(COLUMN ** T,char * nom,char * nouveau_nom)
{
    int i=0;
    while (T[i]!=0 )
    {
        if (T[i]->nom!=nom){
            i++;
        }
        else{
            break;
        }

    }
    if(T[i]->nom==nom)
    {
        T[i]->nom=nouveau_nom;
    }
}
//fonction qui delete une colonne
void delete_column(COLUMN ** col) {
    free(*col);
}
//fonction qui delete une colonne d'une liste de colonne et qui avance d'un cran les colonnes suivantes
void suppr_col_data(COLUMN ** T,char * nom)
{
    int i=0;
    while (T[i]->nom!=nom && T[i]!=0)
    {
        i++;
    }
    if (T[i]==0 && T[i+1]==0)
    {
        printf("erreur colonne non trouvée");
    }
    else
    {
        if (T[i+1]==0)
        {
            delete_column(T+i);
        }
        else
        {

            delete_column(T+i);
            while(T[i+1]!=0)
            {
                T[i]=T[i+1];
                i++;
            }
        }
    }
}
//fonction qui recherche une valeur dans une liste de colonnes
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
//fonction qui reourne la valeure a la ligne ligne et la colonne colonne
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
//fonction qui remplace une valeur a un cetain emplacement de notre dataframe(tableau de colonnes)
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
//fonction quifonction qui affiche le nom des colonnes d'un dataframe
void affich_nom_col_data(COLUMN ** T)
{
    int i=0;
    while (T[i]!=0)
    {
        printf("%s",T[i]->nom);
    }
}
//fonction qui affiche le nombre de colonnes d'un dataframe
void nb_ligne_colonne(COLUMN ** T)
{
    int i=0;
    while(T[i]!=0)
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
//fonction qui retourn le nombre de valeurs du dataframe équivalentes a x
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
//fonction qui revoie le nombre de valeurs du dataframe supérieures a x
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
//fonction qui revoie le nombre de valeurs du dataframe inférieures a x
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
