#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include"LS.h"
int main ()
{
    srand(time(0));
    FILE *Val,*R1,*R2;
    int choise,n,i,j,comp1,trouve1,comp2,trouve2,fin=0;
    LS *L1,*L2;
    Maillon *T,*LR;
    Val=fopen("Valeurs de LR.txt","a");
    R1=fopen("Result par LS1.txt","a");
    R2=fopen("Result par LS2.txt","a");
    welcome();
    while (fin!=1)
    {
        choix();
        printf("\n\n\n\n");
        printf("\t\t\t\t\tEntrez votre choix : \t");
        scanf("%i",&choise);
        system("cls");
        switch (choise)
        {
            case 1:
            {
                allouer(&T);
                aff_val(T,rand());
                aff_adr(T,NULL);
                printf("Entrez le nombre de maillon : ");
                scanf("%d",&n);
                cr_ord(&T,n);
                printf("\n\n\n\n\t\t\t\t\t|La liste de type LP est cree| \n\n\n\n");
                break;
            }
            case 2:
            {
                printf("\n\n\n\n");
                aff_liste(T);
                printf("\n\n\n\n");
                break;
            }
            case 3 :
            {
                LR=cr_LR(10000,T);
                printf("\n\n\n\n\t\t\t\t\t|La liste de type LR est cree| \n\n\n\n");
                for (i=1;i<=10000;i++)
                {
                    fprintf(Val,"%i\n",valpos(i,LR));
                }
                break;
            }
            case 4:
            {
                printf("\n\n\n\n");
                aff_liste(LR);
                printf("\n\n\n\n");
                break;
            }
            case 5:
            {
                allouer_LS(&L1);
                L1=LS1(1000,T);
                printf("\n\n\n\n\t\t\t\t\t|La liste de type LS1 est cree| \n\n\n\n");
                break;
            }
            case 6:
            {
               printf("\n\n\n\n");
               afficherLS(L1);
               printf("\n\n\n\n");
               break;
            }
            case 7:
            {
               allouer_LS(&L2);
               LS2(T,&L2);
               printf("\n\n\n\n\t\t\t\t\t|La liste de type LS2 est cree| \n\n\n\n");
               break;
            }
            case 8:
            {
                printf("\n\n\n\n");
                afficherLS(L2);
                printf("\n\n\n\n");
                break;
            }
            case 9:
            {
                for (i=1;i<=10000;i++)
                {
                    Rech_LS1(L1,T,valpos(i,LR),&comp1,&trouve1);
                    fprintf(R1,"%d\n",comp1);
                }
                printf("\n\n\n\n\t\t\t\t\t|Le recherche est fini| \n\n\n\n");
                break;
            }
            case 10:
            {
                for(j=1;j<=10000;j++)
                {
                    Rech_LS2(L2,T,valpos(j,LR),&comp2,&trouve2);
                    fprintf(R2,"%d\n",comp2);
                }
                printf("\n\n\n\n\t\t\t\t\t|Le recherche est fini| \n\n\n\n");
                break;
            }
            case 11:
            {
                fin=1;
                break;
            }
        }
    }
}
