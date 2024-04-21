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
int main()
{
    CDataframe *df = createCDataframe();
    addColumn(df, "Column1");
    addColumn(df, "Column2");
    addColumn(df, "Column3");
    for (int i = 0; i < 5; ++i)
        {
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
