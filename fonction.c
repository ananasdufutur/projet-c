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
