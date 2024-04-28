#include <stdio.h>
#include <time.h>

// * Estructuras
struct fecha {
    unsigned int mes, dia, año;
};

struct tiempo {
    unsigned int horas, minutos;
};

struct registro_operacion {
    long numero_cuenta;
    float cantidad;
    int tipo_operacion;
    struct fecha f;
    struct tiempo t;
};

struct registro_operacion entrada() {
    struct registro_operacion una;
    time_t ahora = time(NULL);
    struct tm *tiempo_ahora = localtime(&ahora);

    printf("\nNúmero de cuenta: ");
    scanf("%ld", &una.numero_cuenta);
    
    printf("\nTipo de operación:\n");
    printf("Depósito (0)\n");
    printf("Retirada de fondos (1)\n");
    printf("Puesta al día (2)\n");
    printf("Estado de la cuenta (3)\n");
    scanf("%d", &una.tipo_operacion);

    // Fecha y tiempo del sistema
    una.t.horas = tiempo_ahora->tm_hour;
    una.t.minutos = tiempo_ahora->tm_min;
    una.f.año = tiempo_ahora->tm_year + 1900;  // tm_year es el número de años desde 1900
    una.f.mes = tiempo_ahora->tm_mon + 1;      // tm_mon es el mes del año desde 0 (Enero)
    una.f.dia = tiempo_ahora->tm_mday;         // tm_mday es el día del mes

    return una;
}

int main() {
    struct registro_operacion w = entrada();

    printf("\nOperación realizada\n");
    printf("Número de cuenta: %ld\n", w.numero_cuenta);
    printf("Fecha: %d-%d-%d\n", w.f.dia, w.f.mes, w.f.año);
    printf("Hora: %d:%d\n", w.t.horas, w.t.minutos);

    return 0;
}
