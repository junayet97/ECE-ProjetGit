jeu3_b(int vitesse,int vie, int score)
{
    //declaration des variables

    char mat[TAILLE_LIG][TAILLE_COL];

    int poslig= (rand()%(((TAILLE_LIG-2) - 1 + 1) + 1)); //Position initiale du PM selon les lignes
    int poscol= (rand()%(((TAILLE_COL-2) - 1 + 1) + 1)); //Position initiale du PM selon les colones
    int deplig=0; //pas de déplacement du PM selon les ligne
    int depcol=0; //pas de déplacement du PM selon les colnes
    int random =rand()%(4 - 0 + 1) + 0; // nombre généré aléatoire à l'origine d'un pas
    int depligal; //pas de déplacement du PM selon les ligne généré aléatoirement
    int depcolal;  //pas de déplacement du PM selon les colone généré aléatoirement

        //idem pour les 4 fantomes

    int posligm= (rand()%(((TAILLE_LIG-2) - 1 + 1) + 1));
    int poscolm= (rand()%(((TAILLE_COL-2) - 1 + 1) + 1));
    int posligm2= (rand()%(((TAILLE_LIG-2) - 1 + 1) + 1));
    int poscolm2= (rand()%(((TAILLE_COL-2) - 1 + 1) + 1));
    int posligm3= (rand()%(((TAILLE_LIG-2) - 1 + 1) + 1));
    int poscolm3= (rand()%(((TAILLE_COL-2) - 1 + 1) + 1));
    int posligm4= (rand()%(((TAILLE_LIG-2) - 1 + 1) + 1));
    int poscolm4= (rand()%(((TAILLE_COL-2) - 1 + 1) + 1));

    int depligalm=0;
    int depcolalm=0;
    int depligalm2=0;
    int depcolalm2=0;
    int depligalm3=0;
    int depcolalm3=0;
    int depligalm4=0;
    int depcolalm4=0;

    int random2=rand()%(3 - 0 + 1) + 0;
    int random3=rand()%(3 - 0 + 1) + 0;
    int random4=rand()%(3 - 0 + 1) + 0;
    int random5=rand()%(3 - 0 + 1) + 0;

    char dir; // variable du switch

    int n=0; // permet le passage d'un mode aleatoire des monstres à un mode controlé (n=0 ou 1)

    int quit=0; // condition d'arret du jeu ( vaut 0 (jeu) ou 1 (fin jeu))

    int start=0; // permet le passage d'un mode aleatoire du PM à un mode controlé (n=0 ou 1)

    int pause=0; // condionne la pause (vaut 1 ou 0)






// on commence par tracer la map:

    tab_b3(mat);

// début du jeu, si respect des condition indiqué:

    while(vie>0&&(score!=150)&&quit==0)
    {

        if (mat[poslig+deplig][poscol+depcol]=='D') score=score+10; // toucher un diament donne 10pts
        if (mat[poslig][poscol]=='M'||mat[poslig+deplig][poscol+depcol]=='M')vie=vie-1; //toucher un monstre enleve une vie

        if(n==0) // deplacement aléatoire de départ des fantomes

        {

            if(random2==0)
            {
                depligalm=1;
                depcolalm=0;
            }
            else if(random2==1)
            {
                depligalm=-1;
                depcolalm=0;
            }
            else if(random2==2)
            {
                depligalm=0;
                depcolalm=1;
            }
            else
            {
                depligalm=0;
                depcolalm=-1;
            }
            if(random3==0)
            {
                depligalm2=1;
                depcolalm2=0;
            }
            else if(random3==1)
            {
                depligalm2=-1;
                depcolalm2=0;
            }
            else if(random3==2)
            {
                depligalm2=0;
                depcolalm2=1;
            }
            else
            {
                depligalm2=0;
                depcolalm2=-1;
            }

            if(random4==0)
            {
                depligalm3=1;
                depcolalm3=0;
            }
            else if(random4==1)
            {
                depligalm3=-1;
                depcolalm3=0;
            }
            else if(random4==2)
            {
                depligalm3=0;
                depcolalm3=1;
            }
            else
            {
                depligalm3=0;
                depcolalm3=-1;
            }

            if(random5==0)
            {
                depligalm4=1;
                depcolalm4=0;
            }
            else if(random5==1)
            {
                depligalm4=-1;
                depcolalm4=0;
            }
            else if(random5==2)
            {
                depligalm4=0;
                depcolalm4=1;
            }
            else
            {
                depligalm4=0;
                depcolalm4=-1;
            }
        }

//boucle paramètrant deux fantomes suiveurs:

        if(pause==0)


        {


            if((poscolm>poscol)&&(posligm<poslig))
            {
                if((poscolm-poscol)<=(poslig-posligm))
                {
                    depligalm=1;
                    depcolalm=0;
                }
                else if((poscolm-poscol)>(poslig-posligm))
                {
                    depligalm=0;
                    depcolalm=-1;
                }

            }

            else if((poscolm>poscol)&&(posligm>poslig))
            {
                if((poscolm-poscol)<=(posligm-poslig))
                {
                    depligalm=-1;
                    depcolalm=0;
                }
                else if((poscolm-poscol)>(posligm-poslig))
                {
                    depligalm=0;
                    depcolalm=-1;
                }

            }

            else if((poscolm<poscol)&&(posligm>poslig))
            {
                if((poscol-poscolm)<=(posligm-poslig))
                {
                    depligalm=-1;
                    depcolalm=0;
                }
                else if((poscolm-poscol)>(poslig-posligm))
                {
                    depligalm=0;
                    depcolalm=1;
                }

            }

            else
            {
                if((poscol-poscolm)<=(poslig-posligm))
                {
                    depligalm=1;
                    depcolalm=0;
                }
                else if((poscol-poscolm)>(poslig-posligm))
                {
                    depligalm=0;
                    depcolalm=1;
                }
            }


            if((poscolm2>poscol)&&(posligm2<poslig))
            {
                if((poscolm2-poscol)<=(poslig-posligm2))
                {
                    depligalm2=1;
                    depcolalm2=0;
                }
                else
                {
                    depligalm2=0;
                    depcolalm2=-1;
                }

            }

            else if((poscolm2>poscol)&&(posligm2>poslig))
            {
                if((poscolm2-poscol)<=(posligm2-poslig))
                {
                    depligalm2=-1;
                    depcolalm2=0;
                }
                else if((poscolm2-poscol)>(posligm2-poslig))
                {
                    depligalm2=0;
                    depcolalm2=-1;
                }

            }

            else if((poscolm2<poscol)&&(posligm2>poslig))
            {
                if((poscol-poscolm2)<=(posligm2-poslig))
                {
                    depligalm2=-1;
                    depcolalm2=0;
                }
                else if((poscolm2-poscol)>(poslig-posligm2))
                {
                    depligalm2=0;
                    depcolalm2=1;
                }

            }

            else
            {
                if((poscol-poscolm2)<=(poslig-posligm2))
                {
                    depligalm2=1;
                    depcolalm2=0;
                }
                else if((poscol-poscolm2)>(poslig-posligm2))
                {
                    depligalm2=0;
                    depcolalm2=1;
                }
            }

        }



        if(start==0)  // mouvement aléatoire de départ du pacman avant la prise de controle, start prend la valeur de 1 dès qu'une touche est appuyé
        {
            vie=5;
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
            if(mat[poslig+depligal][poscol+depcolal]=='D')
                score=score+10;
        }

        else  // moment où le joueur prend controle
        {
            depligal=0;
            depcolal=0;

        }
// parametrage de déplacement du pacman
        if ((mat[poslig+deplig][poscol+depcol]=='+')||(mat[poslig+depligal][poscol+depcolal]=='+'))
        { //si PM touche un mur, il s'arrete, il est bloqué et doit changer de trajectoire

            deplig=0;
            depcol=0;
            depcolal=0;
            depligal=0;
        }

        mat[poslig][poscol]=' ';
        affiche(mat,poslig,poscol);
        poslig=poslig+deplig+depligal;
        poscol=poscol+depcol+depcolal;
           // si le PM touche les bords
        if(poscol==0) //
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
        {
            deplig=0;
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



//parametre de bordure du fantome 1

        if(poscolm==1)
        {
            n=1;
            poscolm=1;
            depcolalm=1;
            depligalm=0;
        }

        if(poscolm==TAILLE_COL-2)
        {
            n=1;
            poscolm=TAILLE_COL-2;
            depcolalm=-1;
            depligalm=0;
        }
        if(posligm==1)
        {
            n=1;
            posligm= 1;
            depligalm=1;
            depcolalm=0;
        }

        if(posligm==TAILLE_LIG-2)
        {
            n=1;
            posligm=TAILLE_LIG-2;
            depligalm=-1;
            depcolalm=0;
        }

// parametre d'affichage du fantome 1
        if ((mat[posligm+depligalm][poscolm+depcolalm]=='D')||(mat[posligm+depligalm][poscolm+depcolalm]=='+'))
        {

            mat[posligm][poscolm]=' ';
            affiche(mat,posligm,poscolm);

            if ((mat[posligm+depligalm][poscolm+depcolalm]=='D')||(mat[posligm][poscolm]=='D')) // si il rencontre un diamant
            {
                posligm=posligm+depligalm;
                poscolm=poscolm+depcolalm;
                mat[posligm][poscolm]='D'; // il reaffiche le diament et continue sont chemin
                affiche3(mat,posligm,poscolm);
                posligm=posligm+depligalm;
                poscolm=poscolm+depcolalm;
            }
            else   // si il rencontre un mur
            {
                posligm=posligm+depligalm;
                poscolm=poscolm+depcolalm;
                mat[posligm][poscolm]='+'; // il reaffiche le mur et continue sont chemin
                affiche4(mat,posligm,poscolm);
                posligm=posligm+depligalm;
                poscolm=poscolm+depcolalm;
            }

        }
        else
        {

            mat[posligm][poscolm]=' ';
            affiche(mat,posligm,poscolm);
            posligm=posligm+depligalm;
            poscolm=poscolm+depcolalm;
            mat[posligm][poscolm]='M';
            affiche2(mat,posligm,poscolm);
        }



// même méthode pour le reste des fantomes

//fantome 2:

        if(poscolm2==1)
        {
            n=1;
            poscolm2=1;
            depcolalm2=1;
            depligalm2=0;
        }

        if(poscolm2==TAILLE_COL-2)
        {
            n=1;
            poscolm2=TAILLE_COL-2;
            depcolalm2=-1;
            depligalm2=0;
        }
        if(posligm2==1)
        {
            n=1;
            posligm2= 1;
            depligalm2=1;
            depcolalm2=0;
        }

        if(posligm2==TAILLE_LIG-2)
        {
            n=1;
            posligm2=TAILLE_LIG-2;
            depligalm2=-1;
            depcolalm2=0;
        }

        if ((mat[posligm2+depligalm2][poscolm2+depcolalm2]=='D')||(mat[posligm2+depligalm2][poscolm2+depcolalm2]=='+')||(mat[posligm2][poscolm2]=='D'))

        {
            mat[posligm2][poscolm2]=' ';
            affiche(mat,posligm2,poscolm2);

            if (mat[posligm2+depligalm2][poscolm2+depcolalm2]=='D')
            {
                posligm2=posligm2+depligalm2;
                poscolm2=poscolm2+depcolalm2;
                mat[posligm2][poscolm2]='D';
                affiche3(mat,posligm2,poscolm2);
                posligm2=posligm2+depligalm2;
                poscolm2=poscolm2+depcolalm2;
            }
            else
            {
                posligm2=posligm2+depligalm2;
                poscolm2=poscolm2+depcolalm2;
                mat[posligm2][poscolm2]='+';
                affiche4(mat,posligm2,poscolm2);
                posligm2=posligm2+depligalm2;
                poscolm2=poscolm2+depcolalm2;
            }

        }
        else
        {

            mat[posligm2][poscolm2]=' ';
            affiche(mat,posligm2,poscolm2);
            posligm2=posligm2+depligalm2;
            poscolm2=poscolm2+depcolalm2;

            mat[posligm2][poscolm2]='M';
            affiche2(mat,posligm2,poscolm2);
        }

//fantome 3:

        if(poscolm3==1)
        {
            n=1;
            poscolm3=1;
            depcolalm3=1;
            depligalm3=0;
        }

        if(poscolm3==TAILLE_COL-2)
        {
            n=1;
            poscolm3=TAILLE_COL-2;
            depcolalm3=-1;
            depligalm3=0;
        }
        if(posligm3==1)
        {
            n=1;
            posligm3= 1;
            depligalm3=1;
            depcolalm3=0;
        }

        if(posligm3==TAILLE_LIG-2)
        {

            posligm3=TAILLE_LIG-2;
            depligalm3=-1;
            depcolalm3=0;
        }
        if ((mat[posligm3+depligalm3][poscolm3+depcolalm3]=='D')||(mat[posligm3+depligalm3][poscolm3+depcolalm3]=='+'))
        {

            mat[posligm3][poscolm3]=' ';
            affiche(mat,posligm3,poscolm3);

            if (mat[posligm3+depligalm3][poscolm3+depcolalm3]=='D')
            {
                posligm3=posligm3+depligalm3;
                poscolm3=poscolm3+depcolalm3;
                mat[posligm3][poscolm3]='D';
                affiche3(mat,posligm3,poscolm3);
                posligm3=posligm3+depligalm3;
                poscolm3=poscolm3+depcolalm3;
            }
            else
            {
                posligm3=posligm3+depligalm3;
                poscolm3=poscolm3+depcolalm3;
                mat[posligm3][poscolm3]='+';
                affiche4(mat,posligm3,poscolm3);
                posligm3=posligm3+depligalm3;
                poscolm3=poscolm3+depcolalm3;
            }

        }
        else
        {
            mat[posligm3][poscolm3]=' ';
            affiche(mat,posligm3,poscolm3);
            posligm3=posligm3+depligalm3;
            poscolm3=poscolm3+depcolalm3;
            mat[posligm3][poscolm3]='M';
            affiche2(mat,posligm3,poscolm3);
        }


//fantome 4:

        if(poscolm4==1)
        {
            n=1;
            poscolm4=1;
            depcolalm4=1;
            depligalm4=0;
        }

        if(poscolm4==TAILLE_COL-2)
        {
            n=1;
            poscolm4=TAILLE_COL-2;
            depcolalm4=-1;
            depligalm4=0;
        }
        if(posligm4==1)
        {
            n=1;
            posligm4= 1;
            depligalm4=1;
            depcolalm4=0;
        }

        if(posligm4==TAILLE_LIG-2)
        {
            n=1;
            posligm4=TAILLE_LIG-2;
            depligalm4=-1;
            depcolalm4=0;
        }
mat[posligm4][poscolm4]=' ';
            affiche(mat,posligm4,poscolm4);


        if ((mat[posligm4+depligalm4][poscolm4+depcolalm4]=='D')||(mat[posligm4+depligalm4][poscolm4+depcolalm4]=='+'))
        {


            if (mat[posligm4+depligalm4][poscolm4+depcolalm4]=='D')
            {
                posligm4=posligm4+depligalm4;
                poscolm4=poscolm4+depcolalm4;
                mat[posligm4][poscolm4]='D';
                affiche3(mat,posligm4,poscolm4);
                posligm4=posligm4+depligalm4;
                poscolm4=poscolm4+depcolalm4;
            }
            else
            {
                posligm4=posligm4+depligalm4;
                poscolm4=poscolm4+depcolalm4;
                mat[posligm4][poscolm4]='+';
                affiche4(mat,posligm4,poscolm4);
                posligm4=posligm4+depligalm4;
                poscolm4=poscolm4+depcolalm4;
            }


        }
        else
        {
            mat[posligm4][poscolm4]=' ';
            affiche(mat,posligm4,poscolm4);
            posligm4=posligm4+depligalm4;
            poscolm4=poscolm4+depcolalm4;
            mat[posligm4][poscolm4]='M';
            affiche2(mat,posligm4,poscolm4);
        }

// paremetrage de la vitesse de jeu en fonction du score
        if(score==110)
        {
            Sleep(vitesse-20);
        }

        else if(score==120)
        {
            Sleep(vitesse-40);
        }

        else if(score==130)
        {
            Sleep(vitesse-60);
        }

        else if(score==140)
        {
            Sleep(vitesse-80);
        }

        else if(score==150)
        {
            Sleep(vitesse-100);
        }

        else
        {
            Sleep(vitesse);
        }




//affichage du score et du nombre de vie
        gotoligcol(TAILLE_LIG,0);
        printf("VIE:%d",vie);
        gotoligcol(TAILLE_LIG+1,0);
        printf("SCORE:%d",score);
        gotoligcol(poslig,poscol);


//parametrage des commandes avec clavier
        if(kbhit())
        {
            start=1; // le mouvement du pacman n'est plus aletoire dès lors qu'on appuie sur une touche
            dir=getch();

            switch(dir)
            {
            case'8' :
                    deplig=-1;
                depcol=0;
                pause=0;
                break;

            case'2' : deplig=1;
                    depcol=0;
                pause=0;
                break;

            case'4' :
                    deplig=0;
                depcol=-1;
                pause=0;
                break;

            case'6' :
                    deplig=0;
                depcol=1;
                pause=0;
                break;

            case'p' :
                deplig=0;
                depcol=0;
                pause=1;
                break;

            case'q' :
                quit=1;

            }


        }


    }

// messages de fin de jeu:

    if(score==150)
    {
        system("cls");
        printf("Felicitacition vous pouvez passer au niveau 4!\n\n");
        Sleep(5000);
    }
    if(quit==1)
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







//Procédure à l'origine du deplacement du PM dans un tableau SANS BORDURES:
jeu3_sb(int vitesse,int vie,int score)
{
    //declaration des variables
    int n;
    int depligm=0;

    char mat[TAILLE_LIG][TAILLE_COL];
    int poslig= (rand()%(((TAILLE_LIG-2) - 1 + 1) + 1)); //Position initiale du PM selon les lignes
    int poscol= (rand()%(((TAILLE_COL-2) - 1 + 1) + 1)); //Position initiale du PM selon les colones

    int posligm= (rand()%(((TAILLE_LIG-2) - 1 + 1) + 1));
    int poscolm= (rand()%(((TAILLE_COL-2) - 1 + 1) + 1));

    int posligm2= (rand()%(((TAILLE_LIG-2) - 1 + 1) + 1));
    int poscolm2= (rand()%(((TAILLE_COL-2) - 1 + 1) + 1));

    int posligm3= (rand()%(((TAILLE_LIG-2) - 1 + 1) + 1));
    int poscolm3= (rand()%(((TAILLE_COL-2) - 1 + 1) + 1));

    int posligm4= (rand()%(((TAILLE_LIG-2) - 1 + 1) + 1));
    int poscolm4= (rand()%(((TAILLE_COL-2) - 1 + 1) + 1));

    int deplig=0;
    int depcol=0;

    char dir;

    int depligal;
    int depcolal;

    int depligalm=0;
    int depcolalm=0;

    int depligalm2=0;
    int depcolalm2=0;


    int depligalm3=0;
    int depcolalm3=0;

    int depligalm4=0;
    int depcolalm4=0;

    int quit=0;
    int start=0;


    int random=rand()%(4 - 0 + 1) + 0;

    int pause=0;
    int random2=rand()%(4 - 0 + 1) + 0;
    int random3=rand()%(4 - 0 + 1) + 0;
    int random4=rand()%(4 - 0 + 1) + 0;
    int random5=rand()%(4 - 0 + 1) + 0;

    tab_sb3(mat);
    // deplacement tant que la vie est superieur à 0
    while(score!=150&&quit==0&&vie>0)
    {


        if (mat[poslig+deplig][poscol+depcol]=='D')
            score=score+10;
        if (mat[poslig][poscol]=='M'||mat[poslig+deplig][poscol+depcol]=='M')
            vie=vie-1;


        if(vie>0&&pause==0)
        {
            if(random2==0)
            {
                depligalm=1;
                depcolalm=0;
            }
            else if(random2==1)
            {
                depligalm=-1;
                depcolalm=0;
            }
            else if(random2==2)
            {
                depligalm=0;
                depcolalm=1;
            }
            else
            {
                depligalm=0;
                depcolalm=-1;
            }
            if(random3==0)
            {
                depligalm2=1;
                depcolalm2=0;
            }
            else if(random3==1)
            {
                depligalm2=-1;
                depcolalm2=0;
            }
            else if(random3==2)
            {
                depligalm2=0;
                depcolalm2=1;
            }
            else
            {
                depligalm2=0;
                depcolalm2=-1;
            }

            if(random4==0)
            {
                depligalm3=1;
                depcolalm3=0;
            }
            else if(random4==1)
            {
                depligalm3=-1;
                depcolalm3=0;
            }
            else if(random4==2)
            {
                depligalm3=0;
                depcolalm3=1;
            }
            else
            {
                depligalm3=0;
                depcolalm3=-1;
            }

            if(random5==0)
            {
                depligalm4=1;
                depcolalm4=0;
            }
            else if(random5==1)
            {
                depligalm4=-1;
                depcolalm4=0;
            }
            else if(random5==2)
            {
                depligalm4=0;
                depcolalm4=1;
            }
            else
            {
                depligalm4=0;
                depcolalm4=-1;
            }
        }
        else
        {
            depligalm=0;
            depcolalm=0;
            depligalm2=0;
            depcolalm2=0;
            depligalm3=0;
            depcolalm3=0;
            depligalm4=0;
            depcolalm4=0;

        }
        // paramètrage de deux fantomes suiveurs

        if((poscolm>poscol)&&(posligm<poslig))
        {
            if((poscolm-poscol)<=(poslig-posligm))
            {
                depligalm=1;
                depcolalm=0;
            }
            else if((poscolm-poscol)>(poslig-posligm))
            {
                depligalm=0;
                depcolalm=-1;
            }

        }

        else if((poscolm>poscol)&&(posligm>poslig))
        {
            if((poscolm-poscol)<=(posligm-poslig))
            {
                depligalm=-1;
                depcolalm=0;
            }
            else if((poscolm-poscol)>(posligm-poslig))
            {
                depligalm=0;
                depcolalm=-1;
            }

        }

        else if((poscolm<poscol)&&(posligm>poslig))
        {
            if((poscol-poscolm)<=(posligm-poslig))
            {
                depligalm=-1;
                depcolalm=0;
            }
            else if((poscolm-poscol)>(poslig-posligm))
            {
                depligalm=0;
                depcolalm=1;
            }

        }

        else
        {
            if((poscol-poscolm)<=(poslig-posligm))
            {
                depligalm=1;
                depcolalm=0;
            }
            else if((poscol-poscolm)>(poslig-posligm))
            {
                depligalm=0;
                depcolalm=1;
            }
        }


        if((poscolm2>poscol)&&(posligm2<poslig))
        {
            if((poscolm2-poscol)<=(poslig-posligm2))
            {
                depligalm2=1;
                depcolalm2=0;
            }
            else
            {
                depligalm2=0;
                depcolalm2=-1;
            }

        }

        else if((poscolm2>poscol)&&(posligm2>poslig))
        {
            if((poscolm2-poscol)<=(posligm2-poslig))
            {
                depligalm2=-1;
                depcolalm2=0;
            }
            else if((poscolm2-poscol)>(posligm2-poslig))
            {
                depligalm2=0;
                depcolalm2=-1;
            }

        }

        else if((poscolm2<poscol)&&(posligm2>poslig))
        {
            if((poscol-poscolm2)<=(posligm2-poslig))
            {
                depligalm2=-1;
                depcolalm2=0;
            }
            else if((poscolm2-poscol)>(poslig-posligm2))
            {
                depligalm2=0;
                depcolalm2=1;
            }

        }

        else
        {
            if((poscol-poscolm2)<=(poslig-posligm2))
            {
                depligalm2=1;
                depcolalm2=0;
            }
            else if((poscol-poscolm2)>(poslig-posligm2))
            {
                depligalm2=0;
                depcolalm2=1;
            }
        }




        if(start==0)
        {
            // initialisation du deplacement aleatoir du pacman
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
            if(mat[poslig+depligal][poscol+depcolal]=='D')
                score=score+10;
            if (mat[poslig][poscol]=='M'||mat[poslig+depligal][poscol+depcolal]=='M')
                vie=vie-1;
        }

        else
        {
            depligal=0;
            depcolal=0;
        }
//parametre bordure du pacman
        if ((mat[poslig+deplig][poscol+depcol]=='+')||(mat[poslig+depligal][poscol+depcolal]=='+'))
        {

            deplig=0;
            depcol=0;
            depligal=0;
            depcolal=0;
        }


        mat[poslig][poscol]=' ';
        affiche(mat,poslig,poscol);
        poslig=poslig+deplig+depligal;
        poscol=poscol+depcol+depcolal;
        if(poscol==0)
            poscol=(TAILLE_COL-2);
        if(poscol==TAILLE_COL-1)
            poscol=1;
        if(poslig==0)
            poslig=(TAILLE_LIG-2);
        if(poslig==TAILLE_LIG-1)
            poslig=1;
        mat[poslig][poscol]='X';
        affiche(mat,poslig,poscol);



        //parametre de bordure du fantome 1

        if(poscolm==0)
        {
            n=1;
            poscolm=TAILLE_COL-2;
        }


        if(poscolm==TAILLE_COL-1)
        {
            n=1;
            poscolm=1;

        }
        if(posligm==0)
        {
            n=1;
            posligm= TAILLE_LIG-2;

        }

        if(posligm==TAILLE_LIG-1)
        {
            n=1;
            posligm=1;

        }

// parametre d'affichage du fantome 1
        if ((mat[posligm+depligalm][poscolm+depcolalm]=='D')||(mat[posligm+depligalm][poscolm+depcolalm]=='+'))
        {

            mat[posligm][poscolm]=' ';
            affiche(mat,posligm,poscolm);

            if ((mat[posligm+depligalm][poscolm+depcolalm]=='D')||(mat[posligm][poscolm]=='D')) // si il rencontre un diamant
            {
                posligm=posligm+depligalm;
                poscolm=poscolm+depcolalm;
                mat[posligm][poscolm]='D'; // il reaffiche le diament et continue sont chemin
                affiche3(mat,posligm,poscolm);
                posligm=posligm+depligalm;
                poscolm=poscolm+depcolalm;
            }
            else   // si il rencontre un mur
            {
                posligm=posligm+depligalm;
                poscolm=poscolm+depcolalm;
                mat[posligm][poscolm]='+'; // il reaffiche le mur et continue sont chemin
                affiche4(mat,posligm,poscolm);
                posligm=posligm+depligalm;
                poscolm=poscolm+depcolalm;
            }

        }
        else
        {

            mat[posligm][poscolm]=' ';
            affiche(mat,posligm,poscolm);
            posligm=posligm+depligalm;
            poscolm=poscolm+depcolalm;
            if((poscolm!=0)&&(poscolm!=TAILLE_COL-1)&&(posligm!=0)&&(posligm!=TAILLE_LIG-1)) //condition pour ne pas afficher de 'M' sur la bordure
            {
                mat[posligm][poscolm]='M';
                affiche2(mat,posligm,poscolm);
            }
        }



// même méthode pour le reste des fantomes

//fantome 2:

        if(poscolm2==0)
        {
            n=1;
            poscolm2=TAILLE_COL-2;

        }

        if(poscolm2==TAILLE_COL-1)
        {
            n=1;
            poscolm2=1;

        }
        if(posligm2==0)
        {
            n=1;
            posligm2= TAILLE_LIG-2;

        }

        if(posligm2==TAILLE_LIG-1)
        {
            n=1;
            posligm2=1;

        }

        if ((mat[posligm2+depligalm2][poscolm2+depcolalm2]=='D')||(mat[posligm2+depligalm2][poscolm2+depcolalm2]=='+')||(mat[posligm2][poscolm2]=='D'))

        {
            mat[posligm2][poscolm2]=' ';
            affiche(mat,posligm2,poscolm2);

            if (mat[posligm2+depligalm2][poscolm2+depcolalm2]=='D')
            {
                posligm2=posligm2+depligalm2;
                poscolm2=poscolm2+depcolalm2;
                mat[posligm2][poscolm2]='D';
                affiche3(mat,posligm2,poscolm2);
                posligm2=posligm2+depligalm2;
                poscolm2=poscolm2+depcolalm2;
            }
            else
            {
                posligm2=posligm2+depligalm2;
                poscolm2=poscolm2+depcolalm2;
                mat[posligm2][poscolm2]='+';
                affiche4(mat,posligm2,poscolm2);
                posligm2=posligm2+depligalm2;
                poscolm2=poscolm2+depcolalm2;
            }

        }
        else
        {

            mat[posligm2][poscolm2]=' ';
            affiche(mat,posligm2,poscolm2);
            posligm2=posligm2+depligalm2;
            poscolm2=poscolm2+depcolalm2;
            if((poscolm2!=0)&&(poscolm2!=TAILLE_COL-1)&&(posligm2!=0)&&(posligm2!=TAILLE_LIG-1)) //condition pour ne pas afficher de 'M' sur la bordure
            {
                mat[posligm2][poscolm2]='M';
                affiche2(mat,posligm2,poscolm2);
            }
        }

//fantome 3:

        if(poscolm3==0)
        {
            n=1;
            poscolm3=TAILLE_COL-2;

        }

        if(poscolm3==TAILLE_COL-1)
        {
            n=1;
            poscolm3=1;

        }
        if(posligm3==0)
        {
            n=1;
            posligm3= TAILLE_LIG-2;

        }

        if(posligm3==TAILLE_LIG-1)
        {
            n=1;
            posligm3=1;

        }
        if ((mat[posligm3+depligalm3][poscolm3+depcolalm3]=='D')||(mat[posligm3+depligalm3][poscolm3+depcolalm3]=='+'))
        {

            mat[posligm3][poscolm3]=' ';
            affiche(mat,posligm3,poscolm3);

            if (mat[posligm3+depligalm3][poscolm3+depcolalm3]=='D')
            {
                posligm3=posligm3+depligalm3;
                poscolm3=poscolm3+depcolalm3;
                mat[posligm3][poscolm3]='D';
                affiche3(mat,posligm3,poscolm3);
                posligm3=posligm3+depligalm3;
                poscolm3=poscolm3+depcolalm3;
            }
            else
            {
                posligm3=posligm3+depligalm3;
                poscolm3=poscolm3+depcolalm3;
                mat[posligm3][poscolm3]='+';
                affiche4(mat,posligm3,poscolm3);
                posligm3=posligm3+depligalm3;
                poscolm3=poscolm3+depcolalm3;
            }

        }
        else
        {
            mat[posligm3][poscolm3]=' ';
            affiche(mat,posligm3,poscolm3);
            posligm3=posligm3+depligalm3;
            poscolm3=poscolm3+depcolalm3;
            if((poscolm3!=0)&&(poscolm3!=TAILLE_COL-1)&&(posligm3!=0)&&(posligm3!=TAILLE_LIG-1)) //condition pour ne pas afficher de 'M' sur la bordure
            {
                mat[posligm3][poscolm3]='M';
                affiche2(mat,posligm3,poscolm3);
            }
        }


//fantome 4:

        if(poscolm4==0)
        {
            n=1;
            poscolm4=TAILLE_COL-2;

        }

        if(poscolm4==TAILLE_COL-1)
        {
            n=1;
            poscolm4=1;

        }
        if(posligm4==0)
        {
            n=1;
            posligm4= TAILLE_LIG-2;

        }


        if(posligm4==TAILLE_LIG-1)
        {
            n=1;
            posligm4=1;

        }



        if ((mat[posligm4+depligalm4][poscolm4+depcolalm4]=='D')||(mat[posligm4+depligalm4][poscolm4+depcolalm4]=='+'))
        {
            mat[posligm4][poscolm4]=' ';
            affiche(mat,posligm4,poscolm4);

            if (mat[posligm4+depligalm4][poscolm4+depcolalm4]=='D')
            {
                posligm4=posligm4+depligalm4;
                poscolm4=poscolm4+depcolalm4;
                mat[posligm4][poscolm4]='D';
                affiche3(mat,posligm4,poscolm4);
                posligm4=posligm4+depligalm4;
                poscolm4=poscolm4+depcolalm4;
            }
            else
            {
                posligm4=posligm4+depligalm4;
                poscolm4=poscolm4+depcolalm4;
                mat[posligm4][poscolm4]='+';
                affiche4(mat,posligm4,poscolm4);
                posligm4=posligm4+depligalm4;
                poscolm4=poscolm4+depcolalm4;
            }


        }
        else
        {
            mat[posligm4][poscolm4]=' ';
            affiche(mat,posligm4,poscolm4);
            posligm4=posligm4+depligalm4;
            poscolm4=poscolm4+depcolalm4;
            if((poscolm4!=0)&&(poscolm4!=TAILLE_COL-1)&&(posligm4!=0)&&(posligm4!=TAILLE_LIG-1)) //condition pour ne pas afficher de 'M' sur la bordure
            {
                mat[posligm4][poscolm4]='M';
                affiche2(mat,posligm4,poscolm4);
            }
        }

           if(score==110)
        {
            Sleep(vitesse-20);
        }

        else if(score==120)
        {
            Sleep(vitesse-40);
        }

        else if(score==130)
        {
            Sleep(vitesse-60);
        }

        else if(score==140)
        {
            Sleep(vitesse-80);
        }

        else
        {
            Sleep(vitesse);
        }






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
                pause=0;
                break;

            case'2' : deplig=1;
                    depcol=0;
                pause=0;
                break;

            case'4' : deplig=0;
                    depcol=-1;
                pause=0;
                break;

            case'6' : deplig=0;
                    depcol=1;
                pause=0;
                break;

            case'p' :
                deplig=0;
                depcol=0;
                pause=1;

                break;

            case'q' :
                quit=1;



            }



        }

    }
    gotoligcol(TAILLE_LIG+2,0);
    printf("%d",score);

    if(score==150)
    {
        system("cls");
        printf("Felicitacition vous pouvez passer au niveau 4!");
        Sleep(5000);
    }
    if(quit==1)
    {
        system("cls");
        printf("Vous avez quitte la partie!!! :,(\nVotre score est de %d points.\n\nMerci d'avoir joue et a bientot!\n\n\n\n",score);
        Sleep(5000);
    }
    if(vie==0)
    {
        system("cls");
        printf("Vous avez perdu!!!\nVotres score est de:%d\nMerci d'avoir joue et a bientot!\n\n\n\n",score);
        score=0;
        Sleep(5000);
    }





    system("cls");
    return score;
    return vie;



}

// jouer avec le tableau 1 avec ou sans bordure et à une certaine vitesse:
 jeu3(int mode,int vitesse,int vie,int score)
{
    //déclaration des variable


    int tab_vitesse[3]= {300,200,100}; // Choix parmi trois vitesses de déplacement


    if (mode==0) // sans bordure
    {

        score= jeu3_sb(tab_vitesse[vitesse],vie,score);
    }

    if (mode==1) // avec bordure
    {

        score=jeu3_b(tab_vitesse[vitesse],vie,score);
    }}
