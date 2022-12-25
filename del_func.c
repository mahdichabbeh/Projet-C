#include<stdio.h>
#include<conio.h>
#include"fonctions.h"
#define PRODUCT_FILE "DATAproducts.txt"
#define INTER_FILE "Interfile.txt"
#define FACTURE_FILE "DATAfactures.txt"
#define CLIENT_FILE "DATAclients.txt"
#define true 1
#define false 0
typedef int bool;

void DelClient()
{
    long long int id;
    printf("Entrer L'ID de client a supprimer: ");
    scanf("%lld", &id);
    FILE *F;
    FILE *G;
    client c;
    F = fopen(CLIENT_FILE, "rt");
    G = fopen(INTER_FILE, "wt");
    bool Found = false;
    while (FillClient(F, &c) != -1)
    {
        if (c.id != id)
        {
            PrintClient(G, c);
        }
        else
        {
            Found = true;
        }
    }
    fclose(F);
    fclose(G);
    if (!Found)
    {
        printf("CLIENT:NOT_FOUND!\n");
    }
    else
    {
        F = fopen(CLIENT_FILE, "wt");
        G = fopen(INTER_FILE, "rt");
        while (FillClient(G, &c) != -1)
        {
            PrintClient(F, c);
        }
        fclose(F);
        fclose(G);
        printf("DONE!\n");
    }
    remove(INTER_FILE);
}



void DelProduct()
{
    long long int id;
    printf("Entrer L'ID de produit: ");
    scanf("%lld", &id);
    FILE *F;
    FILE *G;
    product p;
    F = fopen(PRODUCT_FILE, "rt");
    G = fopen(INTER_FILE, "wt");
    bool Found = false;
    while (FillProduct(F, &p) != -1)
    {
        if (p.code != id)
            PrintProduct(G, p);
        else
            Found = true;
    }
    fclose(F);
    fclose(G);
    if (!Found)
    {
        printf("PRODUCT:NOT_FOUND!\n");
    }
    else
    {
        F = fopen(PRODUCT_FILE, "wt");
        G = fopen(INTER_FILE, "rt");
        while (FillProduct(G, &p) != -1)
        {
            PrintProduct(F, p);
        }
        fclose(F);
        fclose(G);
        remove(INTER_FILE);
        printf("DONE!\n");
    }
}
