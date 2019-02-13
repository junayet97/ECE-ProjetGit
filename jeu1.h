#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include "myfunctions.h"
//Dimentions du jeu:
#define TAILLE_LIG 20 //Nombre de lignes
#define TAILLE_COL 50 //Nombre de colones


//Fonction à l'origine du deplacement du PM dans un tableau SANS BORDURES (renvoie vie et score:
jeu1_sb(int vitesse,int vie,int score)
{
    //declaration des variables
    int poslig= (rand()%(((TAILLE_LIG-2) - 1 + 1) - 1)); //Position initiale du PM selon les lignes
    int poscol= (rand()%(((TAILLE_COL-2) - 1 + 1) - 1)); //Position initiale du PM selon les colones
    char mat[TAILLE_LIG][TAILLE_COL];
    int deplig=0;
    int depcol=0;
    char dir;
    int depligal;
    int depcolal;
    int quit=0;
    int start=0;
    int random =rand()%(4 - 0 + 1) + 0;
    //affichage tableau
    tab_sb(mat);
    // deplacement tant que la vie est superieur à 0
    while(score!=50&&quit==0)
    {
        if (mat[poslig+deplig][poscol+depcol]=='D')
            score=score+10;
        if(start==0)
        {
            if(random==0)
            {
                depligal=1;
                depcolal=0;
            }
            else if(random==1)
            {
                depligal=-1;
                depcolal=0;
            }
            else if(random==2)
            {
                depligal=0;
                depcolal=1;
            }
            else
            {
                depligal=0;
                depcolal=-1;
            }
            if (mat[poslig+depligal][poscol+depcolal]=='D') score=score+10;
        }

        else
        {
            depligal=0;
            depcolal=0;
        }

        mat[poslig][poscol]=' ';
        affiche(mat,poslig,poscol);
        poslig=poslig+deplig+depligal;
        poscol=poscol+depcol+depcolal;
        if(poscol==0)
        {
            poscol=(TAILLE_COL-2);

        }
        if(poscol==TAILLE_COL-1)
        {
            poscol=1;


        }

        if(poslig==0)
        {
            poslig=(TAILLE_LIG-2);



        }
        if(poslig==TAILLE_LIG-1)
        {
            poslig=1;



        }
        mat[poslig][poscol]='X';
        affiche(mat,poslig,poscol);
        Sleep(vitesse);
        gotoligcol(TAILLE_LIG,0);
        printf("VIE:%d",vie);
        gotoligcol(TAILLE_LIG+1,0);
        printf("SCORE:%d",score);
        gotoligcol(poslig,poscol);

        if(kbhit())
        {
            start=1;
            dir=getch();
            switch(dir)
            {
            case'8' : deplig=-1;
                    depcol=0;
                break;

            case'2' : deplig=1;
                    depcol=0;
                break;

            case'4' : deplig=0;
                    depcol=-1;
                break;

            case'6' : deplig=0;
                    depcol=1;
                break;

            case'p' :
                deplig=0;
                depcol=0;
                break;

            case'q' :
                quit=1;

            }


        }

    }
    gotoligcol(TAILLE_LIG+2,0);
    printf("%d",score);

    if(score==50)
    {
        system("cls");
        printf("Felicitacition vous avez passe le niveau 1 avec succes!\nVous allez passer au niveau 2 dans 5 secondes\n");
        Sleep(5000);
    }
    if(quit==1)
    {
        system("cls");
        printf("Vous avez quitte la partie!!! :,(\nVotre score est de %d points.\n\nMerci d'avoir joue et a bientot!\n\n\n\n",score);
        Sleep(5000);
    }


system("cls");
    return score;
    return vie;




}

// fonction à l'origine du deplacement du PM dans un tableau AVEC BORDURES:
jeu1_b(int vitesse,int vie,int score)
{
    //declaration des variables
    int poslig= (rand()%(((TAILLE_LIG-2) - 1 + 1) - 1)); //Position initiale du PM selon les lignes
    int poscol= (rand()%(((TAILLE_COL-2) - 1 + 1) - 1)); //Position initiale du PM selon les colones
    int deplig=0;
    int depcol=0;
    char dir;

    int depligal;
    int depcolal;
    int a=1;
    int start=0;
    int random =rand()%(4 - 0 + 1) + 0;
    char mat[TAILLE_LIG][TAILLE_COL];
    //affichage du tableau
    tab_b(mat);
    // deplacement tant que la vie est superieur à 0
    while(vie>0&&(score!=50)&&a==1)
    {
        if (mat[poslig+deplig][poscol+depcol]=='D')
            score=score+10;

        if(start==0)
        {   vie=5;
            if(random==0)
            {
                depligal=1;
                depcolal=0;
            }
            else if(random==1)
            {
                depligal=-1;
                depcolal=0;
            }
            else if(random==2)
            {
                depligal=0;
                depcolal=1;
            }

            else
            {
                depligal=0;
                depcolal=-1;
            }
            if (mat[poslig+depligal][poscol+depcolal]=='D')score=score+10;
        }

        else
        {
            depligal=0;
            depcolal=0;

        }
        mat[poslig][poscol]=' ';
        affiche(mat,poslig,poscol);
        poslig=poslig+deplig+depligal;
        poscol=poscol+depcol+depcolal;
        if(poscol==0)
        {
            deplig=0;
            depcol=0;
            poscol=1;
            vie=vie-1;

        }
        if(poscol==TAILLE_COL-1)
        {
            deplig=0;
            depcol=0;
            poscol=TAILLE_COL-2;
            vie=vie-1;
        }

        if(poslig==0)
        {   deplig=0;
            depcol=0;
            poslig=1;
            vie=vie-1;

        }
        if(poslig==TAILLE_LIG-1)
        {
            deplig=0;
            depcol=0;
            poslig=TAILLE_LIG-2;
            vie=vie-1;

        }
        mat[poslig][poscol]='X';
        affiche(mat,poslig,poscol);
        Sleep(vitesse);
        gotoligcol(TAILLE_LIG,0);
        printf("VIE:%d",vie);
        gotoligcol(TAILLE_LIG+1,0);
        printf("SCORE:%d",score);
        gotoligcol(poslig,poscol);


        if(kbhit())
        {
            start=1;
            dir=getch();
            switch(dir)
            {
            case'8' : deplig=-1;
                    depcol=0;
                break;

            case'2' : deplig=1;
                    depcol=0;
                break;

            case'4' : deplig=0;
                    depcol=-1;
                break;

            case'6' : deplig=0;
                    depcol=1;
                break;

            case'p' :
                deplig=0;
                depcol=0;
                break;

            case'q' :
                a=0;

            }


        }


    }
    gotoligcol(TAILLE_LIG+2,0);
    printf("%d",score);

    if(score==50)
    {
        system("cls");
        printf("Felicitacition vous avez passe le niveau 1 avec succes!\nVous allez passer au niveau 2 dans 5 secondes\n");
        Sleep(5000);

    }
    if(a==0)
    {
        system("cls");
        printf("Vous avez quitte la partie!!! :,(\nVotre score est de %d points.\n\nMerci d'avoir joue et a bientot!\n\n\n\n",score);
        Sleep(5000);
    }
    if(vie==0)
    {
        system("cls");
        printf("Desole, vous avez perdu!\nVous avez %d points.\n\nMerci d'avoir joue et a bientot!\n\n\n\n",score);
        score=0;
        Sleep(5000);
    }



    system("cls");
    return score;
    return vie;




}

// jouer avec le tableau 1 avec ou sans bordure et à une certaine vitesse:
jeu1(int mode,int vitesse,int vie, int score)
{
    int tab_vitesse[3]= {200,100,50}; // Choix parmi trois vitesses de déplacement

    if (mode==0) // sans bordure
    {
        score=jeu1_sb(tab_vitesse[vitesse],vie,score);
    }
    if (mode==1) // avec bordure
    {
        score= jeu1_b(tab_vitesse[vitesse],vie,score);
    }
    return score;
}
