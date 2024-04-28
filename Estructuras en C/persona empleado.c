#include <stdio.h>

// Definición de estructura fecha
struct fecha {
    unsigned int dia, mes, anyo;
};

// Definición de estructura persona
struct persona {
    char nombre[20];
    unsigned int edad;
    int altura;
    int peso;
    struct fecha fec;
};

// Definición de estructura persona_empleado
struct persona_empleado {
    struct persona unapersona;
    unsigned int salario;
    unsigned int horas_por_semana;
};

// Prototipos de funciones
void entrada(struct persona_empleado *p);
void muestra(struct persona_empleado p);

int main() {
    struct persona_empleado p;
    entrada(&p);
    muestra(p);
    return 0;
}

void entrada(struct persona_empleado *p) {
    printf("\nIntroduzca su nombre: ");
    fgets(p->unapersona.nombre, 20, stdin); // Seguro contra desbordamientos
    printf("Introduzca su edad: ");
    scanf("%u", &p->unapersona.edad);
    printf("Introduzca su altura: ");
    scanf("%d", &p->unapersona.altura);
    printf("Introduzca su peso: ");
    scanf("%d", &p->unapersona.peso);
    printf("Introduzca su fecha de nacimiento (dd mm aaaa): ");
    scanf("%u %u %u", &p->unapersona.fec.dia, &p->unapersona.fec.mes, &p->unapersona.fec.anyo);
    printf("Introduzca su salario: ");
    scanf("%u", &p->salario);
    printf("Introduzca número de horas por semana: ");
    scanf("%u", &p->horas_por_semana);
    while (getchar() != '\n'); // Limpiar el búfer de entrada
}

void muestra(struct persona_empleado p) {
    printf("\nDatos de un empleado\n");
    printf("Nombre: %s", p.unapersona.nombre);
    printf("Edad: %u\n", p.unapersona.edad);
    printf("Fecha de nacimiento: %u-%u-%u\n", p.unapersona.fec.dia, p.unapersona.fec.mes, p.unapersona.fec.anyo);
    printf("Altura: %d\n", p.unapersona.altura);
    printf("Peso: %d\n", p.unapersona.peso);
    printf("Salario: %u\n", p.salario);
    printf("Número de horas por semana: %u\n", p.horas_por_semana);
}
