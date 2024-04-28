#include <stdio.h>

/*
    Estructuras
*/

struct collection_CD
{
    char title[45];
    char artist[30];
    int num_tracks;
    float price;
    char date_pucharse[11];
} DSOTM = {  // TIPO DE DECLARACIÓN DE UNA ESTRUCTURA
    "The Dark Side of the Moon",
    "Pink Floyd",
    10,
    19.99,
    "01/01/1973"
}, WYWH = {
    "Wish You Were Here",
    "Pink Floyd",
    5,
    15.99,
    "01/01/1975"
} ;


struct sale
{
    char seller[30];
    unsigned int code;
    float unit_price;
    int units_article;
    struct collection_CD CD;
};

struct info_dir {
    char street[30];
    char city[30];
    char country[30];
    char zip_code[10];
};

struct employee {
    char name[30];
    char last_name[30];
    char position[30];
    float salary;
    struct info_dir address;
};

struct customer {
    char name[30];
    char last_name[30];
    char email[30];
    struct info_dir address;
    struct sale pucharse;
};

/*
    void functions
*/

// Imprimir un CD en especifico
// *cd representa a un cd especifico ingresandole la dirección de memoria

void printCollectionCD(const struct collection_CD *cd) {
    printf("Nombre del álbum: %s\nNombre del artista: %s\nNúmero de canciones: %d\nPrecio: %.2f\nFecha de compra: %s\n",
        cd->title, cd->artist, cd->num_tracks, cd->price, cd->date_pucharse);
}

void printCustomer(const struct customer *customer) {
    printf("Nombre: %s\nApellido: %s\nEmail: %s\nDirección: %s\nCiudad: %s\nPais: %s\nCódigo postal: %s\n",
        customer->name, customer->last_name, customer->email, customer->address.street, customer->address.city, customer->address.country, customer->address.zip_code);
    printf("Vendedor: %s\nCódigo: %d\nPrecio unitario: %.2f\nUnidades: %d\n",
        customer->pucharse.seller, customer->pucharse.code, customer->pucharse.unit_price, customer->pucharse.units_article);
}


int main(){
    
    //printf("Nombre del álbum: %s\nNombre del artista: %s\nNúmero de canciones: %d\nPrecio: %.2f\nFecha de compra: %s\n",
    //DSOTM.title, DSOTM.artist, DSOTM.num_tracks, DSOTM.price, DSOTM.date_pucharse);
    // Segundo tipo de declaración de estructura
    struct info_dir mall_centro_concepcion = {"Barros Arana", "Concepción", "Chile", "4030000"};
    //printf("Dirección: %s\nCiudad: %s\nPais: %s", mall_centro_concepcion.street, mall_centro_concepcion.city, mall_centro_concepcion.country);
    struct sale sale_1 = {"Alan", 1, 19.99, 1, DSOTM};
    struct customer cliente_1 = {"Joaquin", "Sanchez", "joaquinsanchez@gmail.com", mall_centro_concepcion, sale_1};
    //printCollectionCD(&DSOTM);
    //printCollectionCD(&WYWH);
    printCustomer(&cliente_1);

    return 0;
};