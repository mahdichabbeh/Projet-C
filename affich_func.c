#include<stdio.h>
#include<conio.h>
#include"fonctions.h"
#define PRODUCT_FILE "DATAproducts.txt"
#define INTER_FILE "Interfile.txt"
#define FACTURE_FILE "DATAfactures.txt"
#define CLIENT_FILE "DATAclients.txt"

void ShowFacture()
{
    long long int id_client;
    printf("Entrer L'ID de client: ");
    scanf("%lld", &id_client);
    FILE *F;
    int k = 0;
    F = fopen(FACTURE_FILE, "rt");
    facture f;
    printf("\nID de Client: %lld\n", id_client);
    while (FillFacture(F, &f) != -1)
    {
        if (f.id_client == id_client)
        {
            k++;
            printf("\nFacture %d:____________________________________________", k);
            printf("\n\nNumero de Facture: %lld\n Mois: %d\nAnnee: %d\n", f.Nfacture, f.mois, f.annee);
            printf("______________________________________________________\n\n");
        }
    }
    if (!k)
        printf("\nCLIENT:WITHOUT_BILLS!\n");
    fclose(F);
}

void ShowClients()
{
    FILE *F;
    client c;
    int k = 0;
    F = fopen(CLIENT_FILE, "rt");
    while (FillClient(F, &c) != -1)
    {
        k++;
        printf("\nClient %d ____________________________________________", k);
        printf("\n\nID: %lld\nNom: %s\nPrenom: %s\n", c.id, c.nom, c.prenom);
        printf("______________________________________________________\n\n");
    }

    fclose(F);
}

void ShowProducts()
{
    FILE *F;
    F = fopen(PRODUCT_FILE, "rt");
    product p;
    int k = 0;
    while (FillProduct(F, &p) != -1)
    {
        k++;
        printf("\nProduct %d ____________________________________________", k);
        printf("\n\nID: %lld\nDesignation: %s\nLa Quantite: %d\n", p.code, p.designation, p.qte );
        printf("______________________________________________________\n\n");
    }
    fclose(F);
}

void ShowBills()
{
    FILE *F;
    F = fopen(FACTURE_FILE, "rt");
    facture f;
    int k = 0;
    while (FillFacture(F, &f) != -1)
    {
        k++;
        printf("\nFacture %d:____________________________________________", k);
        printf("\n\nNumero de Facture: %lld\nID de client: %lld\nMois: %d\nAnnee: %d\n", f.Nfacture, f.id_client, f.mois, f.annee);
        printf("______________________________________________________\n\n");
    }
    fclose(F);
}

void ShowBillsByDate()
{
    int month, year;
    printf("Entrer l'annee: ");
    scanf("%d", &year);
    printf("Entrer le mois: ");
    scanf("%d", &month);
    FILE *F;
    facture f;
    F = fopen(FACTURE_FILE, "rt");
    int k = 0;
    while (FillFacture(F, &f) != -1)
    {
        if (f.annee == year && f.mois == month)
        {
            k++;
            printf("\nFacture %d:____________________________________________", k);
            printf("\n\nNumero de Facture: %lld\nID de client: %lld\nMois: %d\nAnnee: %d\n", f.Nfacture, f.id_client, f.mois, f.annee);
            printf("______________________________________________________\n\n");
        }
    }
}

