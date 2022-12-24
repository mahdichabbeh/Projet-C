#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct product
{
    long long int code;
    char designation[20];
    int qte;
} product;

typedef struct client
{
    long long int id, num_tel;
    char nom[50], prenom[50];
} client;

typedef struct facture
{
    long long int Nfacture, id_client;
    int mois, annee;
} facture;

int WriteProduct(FILE *F, product *p);
void PrintProduct(FILE *F, product p);
int WriteFacture(FILE *F, facture *f);
void PrintFacture(FILE *F, facture f);
int WriteClient(FILE *F, client *c);
void PrintClient(FILE *F, client c);
int ProductExist(long long int id_product);
int QteAvailable(long long int id_product, int qte);


