#include<stdio.h>
#include<conio.h>
#include"fonctions.h"

int WriteProduct(FILE *F, product *p)
{
    return fscanf(F, "%lld %s %d ", &(p->code), p->designation, &(p->qte));
}

void PrintProduct(FILE *F, product p)
{
    fprintf(F, "%lld %s %d \n", p.code, p.designation, p.qte);
}

int WriteFacture(FILE *F, facture *f)
{
    return fscanf(F, "%lld %lld %d %d", &(f->Nfacture), &(f->id_client), &(f->mois), &(f->annee));
}

void PrintFacture(FILE *F, facture f)
{
    fprintf(F, "%lld %lld %d %d\n", f.Nfacture, f.id_client, f.mois, f.annee);
}

int WriteClient(FILE *F, client *c)
{
    return fscanf(F, "%lld %s %s %s", &(c->id), c->nom, c->prenom);
}

void PrintClient(FILE *F, client c)
{
    fprintf(F, "%lld %s %s %s\n", c.id, c.nom, c.prenom);
}


void Choose()
{
    printf("\nChoose an option from below _____________________\n\n");
    printf("01 - Verify the existence of a product\n");
    printf("02 - Verify the availability of the ordered amount\n");
    printf("03 - Destock a specific amount of a product\n");
    printf("04 - Show the bills of a client\n");
    printf("05 - Add a new client\n");
    printf("06 - Delete a client\n");
    printf("07 - Display the list of clients\n");
    printf("08 - Add a product\n");
    printf("09 - Remove a product\n");
    printf("10 - Display the list of available products\n");
    printf("11 - Make a bill\n");
    printf("12 - Display the list of bills\n");
    printf("13 - Show bills of a given date\n");
    printf("00 - Exit!\n\n");
    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);
    system("cls");
    long long int id;
    int qte, r_value;
    switch (choice)
    {
    case 1:
        printf("Enter Product ID: ");
        scanf("%lld", &id);
        if (ProductExist(id))
            printf("Product exists\n");
        else
            printf("Product doesn't exist\n");
        break;
    case 2:
        printf("Enter Product ID: ");
        scanf("%lld", &id);
        printf("Enter The Order Amount: ");
        scanf("%d", &qte);
        r_value = QteAvailable(id, qte);
        if (r_value == 1)
            printf("The Order Amount Is Available\n");
        else if (r_value == -1)
            printf("The Available Amount Is Insufficient\n");
        else
            printf("Product doesn't exist\n");
        break;
    case 3:
        printf("Enter Product ID: ");
        scanf("%lld", &id);
        printf("Enter The Order Amount: ");
        scanf("%d", &qte);
        r_value = Unstock(id, qte);
        if (r_value == 1)
            printf("Done!\n");
        else if (r_value == -1)
            printf("The Available Amount Is Insufficient\n");
        else
            printf("Product doesn't exist\n");
        break;
    case 4:
        ShowFacture();
        break;
    case 5:
        AddClient();
        break;
    case 6:
        DelClient();
        break;
    case 7:
        ShowClients();
        break;
    case 8:
        AddProduct();
        break;
    case 9:
        DelProduct();
        break;
    case 10:
        ShowProducts();
        break;
    case 11:
        MakeBill();
        break;
    case 12:
        ShowBills();
        break;
    case 13:
        ShowBillsByDate();
        break;
    case 0:
        exit(0);
    default:
        system("cls");
        printf("Wrong Value! Try Again\n");
        Choose();
    }
    system("pause");
    system("cls");
    Choose();
}
