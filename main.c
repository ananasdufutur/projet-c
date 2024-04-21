#include <stdio.h>

#include "fonction.c"
int main() {
    printf("Hello, World!\n");
    COLUMN *mycol = create_column("My column");
    printf("%s",mycol->nom);
    return 0;

}
