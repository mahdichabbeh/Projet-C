#include<stdio.h>
#include<conio.h>
#include"fonctions.h"

int FillProduct(FILE *F, product *p)
{
    return fscanf(F, "%lld %s %d ", &(p->code), p->designation, &(p->qte));
}

void PrintProduct(FILE *F, product p)
{
    fprintf(F, "%lld %s %d \n", p.code, p.designation, p.qte);
}

int FillFacture(FILE *F, facture *f)
{
    return fscanf(F, "%lld %lld %d %d", &(f->Nfacture), &(f->id_client), &(f->mois), &(f->annee));
}

void PrintFacture(FILE *F, facture f)
{
    fprintf(F, "%lld %lld %d %d\n", f.Nfacture, f.id_client, f.mois, f.annee);
}

int FillClient(FILE *F, client *c)
{
    return fscanf(F, "%lld %s %s\n", &(c->id), c->nom, c->prenom);
}

void PrintClient(FILE *F, client c)
{
    fprintf(F, "%lld %s %s %s\n", c.id, c.nom, c.prenom);
}


