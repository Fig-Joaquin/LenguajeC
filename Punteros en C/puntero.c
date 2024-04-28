#include <stdio.h>

void change_value(int *a,int *b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

int main() {
    int a=7, b=8;

    printf("Imprime valor de a: %d y valor de b: %d \n", a,b);
    change_value(&a,&b);
    printf("\nFuncion de intercambio contiene valor de a: %d y valor de b: %d \n", a,b);
    
    return 0;
}


