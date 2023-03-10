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

void AddClient()
{
    FILE *F;
    client c, temp;
    char *instruction;
    instruction = "Entrer le ID du Client: ";
    do
    {
        printf("%s", instruction);
        scanf("%lld", &(c.id));
        instruction = "Error d'entree\nEntrer une autre ID: ";
    } while (c.id <= 0);
    bool Found = false;
    F = fopen(CLIENT_FILE, "rt");
    if (F != NULL)
    {
        while (FillClient(F, &temp) != -1)
        {
            if (c.id == temp.id)
            {
                printf("CLIENT:ALREADY_EXISTS!\n");
                Found = true;
                break;
            }
        }
    }
    if (!Found)
    {
        getchar();
        fclose(F);
        F = fopen(CLIENT_FILE, "a");
        printf("Entrer le Nom: ");
        gets(c.nom);
        printf("Entrer le Prenom: ");
        gets(c.prenom);
        PrintClient(F, c);
        printf("DONE!\n");
    }
    fclose(F);
}


void AddProduct()
{
    FILE *F;
    FILE *G;
    product p, temp;
    bool found = false;
    printf("Entrer le code de produit: ");
    scanf("%lld", &(temp.code));
    F = fopen(PRODUCT_FILE, "rt");
    G = fopen(INTER_FILE, "wt");
    while (FillProduct(F, &p) != -1)
    {
        if (p.code == temp.code)
        {
            printf("PRODUCT:ALREADY_EXISTS!\nEntrer la quantite additionel: ");
            scanf("%d", &(temp.qte));
            p.qte += temp.qte;
            found = true;
        }
        PrintProduct(G, p);
    }
    if (!found)
    {
        printf("Entrer la designation: ");
        scanf("%s", temp.designation);
        printf("Entrer la quantite: ");
        scanf("%d", &(temp.qte));
        PrintProduct(G, temp);
    }
    fclose(F);
    fclose(G);
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

void MakeBill()
{
    product p;
    facture f, temp;
    long long int id_client;
    printf("Entrer L'ID de client: ");
    scanf("%lld", &id_client);
    long long int id_produit;
    printf("Entrer L'ID de produit: ");
    scanf("%lld", &id_produit);
    int qte;
    printf("Entrer la quantite: ");
    scanf("%d", &qte);
    int r_value = Unstock(id_produit, qte);
    if (r_value == 1)
    {
        int k = 0;
        FILE *P;
        FILE *F;
        F = fopen(FACTURE_FILE, "rt");
        while (FillFacture(F, &temp) != -1)
        {
            k = temp.Nfacture;
        }
        k++;
        fclose(F);
        f.Nfacture = k;
        f.id_client = id_client;
        time_t current_time;
        current_time = time(NULL);
        struct tm tm = *localtime(&current_time);
        f.annee = tm.tm_year + 1900;
        f.mois = tm.tm_mon + 1;
        F = fopen(FACTURE_FILE, "at");
        P = fopen(PRODUCT_FILE, "rt");
        while (FillProduct(P, &p) != -1)
        {
            if (p.code == id_produit)
            {
                PrintFacture(F, f);
                break;
            }
        }
        fclose(F);
        fclose(P);
        printf("DONE!\n");
    }
    else
    {
        if (r_value == -1)
            printf("Quantite indisponible!\n");
        if (r_value == 0)
            printf("Produit indisponible!\n");
    }
}