#include<stdio.h>
#include<conio.h>
#include"fonctions.h"
#define PRODUCT_FILE "DATAproducts.txt"
#define INTER_FILE "Interfile.txt"
#define FACTURE_FILE "DATAfactures.txt"
#define CLIENT_FILE "DATAclients.txt"

int ProductExist(long long int id_product)
{
    FILE *F;
    product p;
    F = fopen(PRODUCT_FILE, "rt");
    while (WriteProduct(F, &p) != -1)
    {
        if (p.code == id_product)
        {
            fclose(F);
            return 1;
        }
    }
    fclose(F);
    return 0;
}

int QteAvailable(long long int id_product, int qte)
{
    FILE *F;
    product p;
    F = fopen(PRODUCT_FILE, "rt");
    if (ProductExist(id_product))
    {
        while (FillProduct(F, &p) != -1)
        {
            if (p.code == id_product)
            {
                if (p.qte >= qte)
                {
                    fclose(F);
                    return 1;
                }
                fclose(F);
                return -1;
            }
        }
    }
    fclose(F);
    return 0;
}