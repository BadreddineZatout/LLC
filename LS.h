#ifndef LS_H
#define LS_H

#include<stdio.h>
#include<stdlib.h>
/*****************déclaration des Types*****************/

typedef struct Maillon {
int val;
struct Maillon *next;
} Maillon;

typedef struct LS {
int val;
Maillon *LP;
struct LS *next;
} LS;

/*****************déclaration des fonctions*****************/

void allouer(Maillon **nouveau);
void aff_adr(Maillon *p,Maillon *q);
void aff_val(Maillon *p, int valeur);
Maillon *suivant(Maillon *p);
int valeur(Maillon *p);
void liberer(Maillon**ancien);
void allouer_LS(LS **nouveau);
void aff_adrLP(LS *p,Maillon *q);
void aff_adrLS(LS *p,LS *q);
void aff_valLS(LS *p,int v);
void afficher1(LS *p);
LS *suiv_LS(LS *p);
int valeurLS(LS *p);
Maillon *point(LS *p);
void libere_LS(LS**ancien);
int long_liste(Maillon *p);
int valpos(int n, Maillon *P);
void afficherLS(LS *P);
void cr_ord(Maillon **T,int n);
void Ins(int v ,Maillon **T);
void recherche (int v,Maillon *T,Maillon **P,Maillon**Q,int *trouve);
void aff_liste(Maillon *T);
LS *LS1(int n,Maillon *l);
void LS2 (Maillon *T,LS **L2);
Maillon *cr_LR(int n,Maillon *L);
void Rech_LS1(LS *L,Maillon *T,int v,int *comp,int *trouve);
void Rech_LS2(LS *L,Maillon *T,int v,int *comp,int *trouve);
void welcome();
void choix();

/*****************Implementation des fonctions*****************/

void allouer(Maillon **nouveau)
{ *nouveau=(Maillon*)malloc(sizeof(Maillon));}

void aff_adr(Maillon *p,Maillon *q)
{p->next=q;}

void aff_val(Maillon *p, int valeur)
{ p->val=valeur;}

Maillon *suivant(Maillon *p)
{return p->next;}

int valeur(Maillon *p)
{return p->val;}

void liberer(Maillon**ancien)
{free(*ancien); *ancien=NULL;}

void afficher1(LS *p)
{
    Maillon *q;
    while(p!=NULL)
    {
       q=point(p);
        printf("%d\t",valeurLS(p));
        printf("%d\n",valeur(q));
        p=suiv_LS(p);
    }
}

void allouer_LS(LS **nouveau)
{
    *nouveau=(LS*)malloc(sizeof(LS));
}

void aff_adrLP(LS *p,Maillon *q)
  {
      p->LP=q;
  }

void aff_adrLS(LS *p,LS *q)
  {
      p->next=q;
  }

void aff_valLS(LS *p,int v)
  {
      p->val=v;
  }

  LS *suiv_LS(LS *p)
{return p->next;}

int valeurLS(LS *p)
{return p->val;}

Maillon *point(LS *p)
{return p->LP;}

void libere_LS(LS**ancien)
{free(*ancien); *ancien=NULL;}

int long_liste(Maillon *p)
{
    int i=0;
    while (p!=NULL)
    {
        p=suivant(p);
        i++;
    }
    return i;
}

int valpos(int n, Maillon *P)
{
    int i=1;
    while (i<n)
    {
        P=suivant(P);
        i++;
    }
    return valeur(P);
}

void afficherLS(LS *P)
{
   while(P!=NULL)
   {
       printf("%i:%i->",valeurLS(P),valeur(point(P)));
       P=suiv_LS(P);
   }
}

void recherche (int v,Maillon *T,Maillon **P,Maillon**Q,int *trouve)
{
    *trouve=0;
    *P=T;
    *Q=NULL;
    while (!*trouve && *P!=NULL)
    {
        if (valeur(*P)>v) *trouve=1;
        else
        {
               *Q=*P;
               *P=suivant(*P);
            }

        }
}

void Ins(int v ,Maillon **T)
{
    int trouve;
    Maillon *P,*Q,*R;
    allouer(&R);
    aff_val(R,v);
    recherche(v,*T,&P,&Q,&trouve);
    if (!trouve)
    {
        aff_adr(R,NULL);
        aff_adr(Q,R);
    }
    else
    {
        if (P==*T)
        {
            aff_adr(R,*T);
        }
        else
        {
            aff_adr(Q,R);
            aff_adr(R,P);
        }
    }
}

void cr_ord(Maillon **T,int n)
{
    int v,i=1;
    while (i<n)
    {
        srand(time(0)+i);
        v=((rand()*rand())%10000000);
        Ins(v,&*T);
        i++;
    }
}

void aff_liste(Maillon *T)
{
    while (T!=NULL)
    {
        printf("%i->",valeur(T));
        T=suivant(T);
    }
}

LS *LS1(int n,Maillon *l)
{
    LS *p,*q,*tete ;
    int i,s;
    allouer_LS(&p);
    tete=p;
    i=1;
    s=1;
    while ((l!=NULL))
    {
        if (i==n)
      {
        allouer_LS(&q);
        aff_valLS(q,valeur(l));
        if (s==n)
        {
           tete=q;
           p=q;
        }
            aff_adrLS(p,q);
            p=q;
            aff_adrLP(p,l);
            i=0;
        }
        i++;
        s++;
        l=suivant(l);
    }
    aff_adrLS(p,NULL);
    return tete ;
}

void LS2 (Maillon *T,LS **L2)
{
    LS *R,*Q,*F,*S,*O;
    int v=1000;
    R=*L2;
    allouer_LS(&F);
    aff_valLS(F,0);aff_adrLP(F,0);
    Q=F;S=F;O=F;
    while(T!=NULL&&v<10000000)
    {
    if (valeur(T)>v)
       {
             allouer_LS(&F);
             aff_adrLS(R,F);
             aff_valLS(R,v);
             aff_adrLP(R,T);
			 O=S;
             S=Q;
             Q=R;
             R=suiv_LS(R);
        if (point(Q)==point(S))
         {

             if (S==*L2)
             {
			     libere_LS(&S);
                 *L2=Q;
                 S=O;
             }
             else
             {
			    libere_LS(&S);
                S=O;
			    aff_adrLS(O,Q);
             }
         }
         v=v+1000;
       }
       else
       {
           T=suivant(T);
       }
    }
	aff_adrLS(Q,NULL);
}

Maillon *cr_LR(int n,Maillon *L)
{
    srand(time(0));
    Maillon *p,*q,*tete;
    int s,m,i;
    s=long_liste(L);
    allouer(&p);
    aff_val(p,rand());
    tete=p;
    for (i=1;i<=n;i++)
    {
        allouer(&q);
        m=((rand()*rand())%(s+10000));
        if (m<=s)
        {
            aff_val(q,valpos(m,L));
            aff_adr(p,q);
            p=q;
        }
        else
        {
            aff_val(q,rand());
            aff_adr(p,q);
            p=q;
        }
    }
    aff_adr(p,NULL);
    return tete;
}

void Rech_LS1(LS *L,Maillon *T,int v,int *comp,int *trouve)
{
    Maillon *P;
    LS *Q;
    *trouve=0;
    *comp=0;
    P=T;Q=L;
    while (Q!=NULL && P!=point(Q) && !*trouve)
    {
        if(valeurLS(Q)==v) *trouve=1;
        else
        {
            if (valeurLS(Q)>v)
            {
                while(P!=point(Q)&&!*trouve)
                {
                    if (valeur(P)==v) *trouve=1;
                    else P=suivant(P);
                    *comp=*comp+1;
                }
            }
            else
            {
                P=point(Q);
                Q=suiv_LS(Q);
            }
            *comp=*comp+1;
        }
    }
    if (Q==0)
    {
        while (P!=NULL&&!*trouve)
        {
            if (valeur(P)==v) *trouve=1;
            else P=suivant(P);
            *comp=*comp+1;
        }
    }

}

void Rech_LS2(LS *L,Maillon *T,int v,int *comp,int *trouve)
{
    int existe;
    Maillon *P;
    LS *Q;
    *trouve=0;
    *comp=0;
    P=T;Q=L;
    existe=1;
    while (Q!=NULL && existe && !*trouve)
    {
        if(valeur(point(Q))==v)
        {
            *trouve=1;
            break;
        }
        if (valeurLS(Q)>=v)
        {
            while(existe &&!*trouve)
            {
                if (valeur(P)==v) *trouve=1;
                else
                {
                    if (P==point(Q)) existe=0;
                    else P=suivant(P);
                }
                *comp=*comp+1;
            }
        }
        else
        {
            P=point(Q);
            Q=suiv_LS(Q);
        }
        *comp=*comp+1;

    }
    if (Q==NULL)
    {
        while (P!=NULL&&!*trouve)
        {
            if (valeur(P)==v) *trouve=1;
            else P=suivant(P);
            *comp=*comp+1;
        }
    }
}

void welcome()
{
    printf("\n\n\n\n\t\t\t\t    _______________________________________________________ \n");
    printf("\t\t\t\t   |        _______     _______     _                      |\n");
    printf("\t\t\t\t   |       |  _____|   |  _____|   | |  ecole nationale    |\n");
    printf("\t\t\t\t   |       | |_____    | |_____    | |                     |\n");
    printf("\t\t\t\t   |       |  _____|   |_____  |   | |  superieure         |\n");
    printf("\t\t\t\t   |       | |_____     _____| |   | |                     |\n");
    printf("\t\t\t\t   |       |_______|   |_______|   |_|  d'informatique     |\n");
    printf("\t\t\t\t   |_______________________________________________________|\n\n");
    printf("\t\t\t\t\tCPI - 1ere Annee - Annee Universitaire 2017/2018 \n\n\n");
    printf("\t\t\t\t ___________________________________________________________________\n");
    printf("\t\t\t\t|                                                            \t\t|\n");
    printf("\t\t\t\t| REALISE PAR : ZATOUT BADREDDINE et AITSAADI ABDELMADJID     \t\t|\n");
    printf("\t\t\t\t|                                                             \t\t|\n");
    printf("\t\t\t\t|        \t ANNEE SCOLAIRE : 2017/2018                        \t|\n");
    printf("\t\t\t\t|                                                             \t\t|\n");
    printf("\t\t\t\t|         \tSECTION : B           GROUPE: 06                  \t|\n");
    printf("\t\t\t\t|                                                             \t\t|\n");
    printf("\t\t\t\t|         \tTP1 : Les listes lineaires chainees               \t|\n");
    printf("\t\t\t\t|                                                             \t\t|\n");
    printf("\t\t\t\t|           \t        <SKIP LIST>                             \t|\n");
    printf("\t\t\t\t|                                                             \t\t|\n");
    printf("\t\t\t\t| ENCADRE PAR :Dr M BOULAKRADECHE                            \t\t|\n ");
    printf("\t\t\t\t|___________________________________________________________________|\n\n\n");
}
void choix()
{
    system("pause");
    system("cls");
    printf("\n\n\n\n\t---->Vous choisissez l'une des operations suivantes: \n\n\n");
    printf("\t\t\t ---------------------------------------------------------\n");
    printf("\t\t\t| 01---->Creation d'une nouvelle liste principale Lp.     |\n");
    printf("\t\t\t|                                                         |\n");
    printf("\t\t\t| 02---->Afficher la liste de type LP.                    |\n");
    printf("\t\t\t|                                                         |\n");
    printf("\t\t\t| 03---->Creation une liste de recherche Lr.              |\n");
    printf("\t\t\t|                                                         |\n");
    printf("\t\t\t| 04---->Afficher la liste de type LR.                    |\n");
    printf("\t\t\t|                                                         |\n");
    printf("\t\t\t| 05---->Creation d'un liste de type LS1.                 |\n");
    printf("\t\t\t|                                                         |\n");
    printf("\t\t\t| 06---->Afficher la liste de type LS1.                   |\n");
    printf("\t\t\t|                                                         |\n");
    printf("\t\t\t| 07---->Creation d'un liste de type LS2.                 |\n");
    printf("\t\t\t|                                                         |\n");
    printf("\t\t\t| 08---->Afficher la liste de type LS2.                   |\n");
    printf("\t\t\t|                                                         |\n");
    printf("\t\t\t| 09---->Chercher tous les element de Lr dans Lp par LS1. |\n");
    printf("\t\t\t|                                                         |\n");
    printf("\t\t\t| 10---->Chercher tous les element de Lr dans Lp par LS2. |\n");
    printf("\t\t\t|                                                         |\n");
    printf("\t\t\t| 11---->Quitter.                                         |\n");
    printf("\t\t\t|                                                         |\n");
    printf("\t\t\t ---------------------------------------------------------\n");
    system("pause");
    system("cls");
}

#endif
