#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED
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

int FillProduct(FILE *F, product *p);
void PrintProduct(FILE *F, product p);
int FillFacture(FILE *F, facture *f);
void PrintFacture(FILE *F, facture f);
int FillClient(FILE *F, client *c);
void PrintClient(FILE *F, client c);
int ProductExist(long long int id_product);
int QteAvailable(long long int id_product, int qte);
void AddClient();
void AddProduct();
void MakeBill();
void ShowFacture();
void ShowClients();
void ShowProducts();
void ShowBills();
void ShowBillsByDate();
void DelClient();
void DelProduct();
int Unstock(long long int id_produit, int qte);

#endif