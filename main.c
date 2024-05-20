#include <stdio.h>
//#include "fonction.c"
#include "fonction.h"

//J'ai(guillaume pousse) tout fait et ait été plus ou moins seul,mon binome ne faisant rien

int main() {
//on teste les dierses fonctions du column.c
    COLUMN *mycol = create_column("My column");
    printf("\nColonne : %s \n", mycol->nom);

    value_added(insert_value(mycol, 2));
    value_added(insert_value(mycol, 4));
    value_added(insert_value(mycol, 9));
    value_added(insert_value(mycol, 10));
    value_added(insert_value(mycol, 15));
    value_added(insert_value(mycol, 19));
    value_added (insert_value(mycol, 23));
    value_added (insert_value(mycol, 25));
    value_added (insert_value(mycol, 29));
    value_added (insert_value(mycol, 32));
    value_added (insert_value(mycol, 36));

    print_column(mycol);

    printf("\nLe nombre d'occurences du nombre %d est : %d fois\n", 5, nb_occurrence(mycol,5));

    int i = 1;
    int val = val_x(mycol, i);
    printf("\nLa valeur situee a la position %d est %d\n\n", i, val);


    int x = 17;

    int sup = sup_x(mycol, x);
    printf("\nIl y a %d valeurs superieures a %d  :  ", sup, x);

    int inf = inf_x(mycol, x);
    printf("\nIl y a %d valeurs inferieures a %d  :  ", inf, x);

    int égale = egale_x(mycol, x);
    printf("\nIl y a %d valeurs egales a %d  :  ", égale, x);

    printf("\n");
    print_column(mycol);
    COLUMN** T = (COLUMN**)malloc(20*sizeof(COLUMN*));
    for (int i=0;i<20;i++){
        T[i]=0;
        //printf("%d\n",T[i]);
    }
    ajout_col_data( T,mycol);
    printf("\n1\n");
    print_column((T[0]));
    printf("%s",T[0]->nom);
    char * nom1="colonnetest";
    //renomm_col( T, "My column",nom1);
    printf("%s",(T[0])->nom);
    COLUMN * col2 = create_column("colonne2");
    value_added(insert_value(col2, 2));
    value_added(insert_value(col2, 4));
    value_added(insert_value(col2, 9));
    value_added(insert_value(col2, 10));
    value_added(insert_value(col2, 15));
    value_added(insert_value(col2, 19));
    value_added (insert_value(col2, 23));
    value_added (insert_value(col2, 25));
    value_added (insert_value(col2, 29));
    value_added (insert_value(col2, 32));
    value_added (insert_value(col2, 60));
    ajout_col_data( T,col2);

    print_column(T[1]);
    suppr_col_data(T,"colonne2");
    for (int i=0;i<20;i++){

        printf("%d\n",T[i]);
    }
    printf("%d",T[1]);

    recherche_val_data(T,5);
    return_val_data(T,2,0);
    replace_val_data(T,2,0,5);

    return 0;

}
