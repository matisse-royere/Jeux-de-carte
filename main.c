//
//  Nom:        Royere
//  Prénom:     Matisse
//  Objectif:   Construction de je de carte  ♠️ ♥️♣️ ♦️
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printcolor(int color) {
    switch (color) {
        case 0: printf("♠️ "); break;
        case 1: printf("♥️ "); break;
        case 2: printf("♣️ "); break;
        case 3: printf("♦️ "); break;
    }
}

int main(int argc, char **argv){

    int tab[52]= {}, pique[13]= {}, cœur[13]= {}, trefle[13]= {}, carreau[13]= {};
    int size, sizeColor, i, j=0, valRand, temp, z;
    int j1[5]= {},  j2[5]= {};
    int paireJ1 =0,  paireJ2 =0 , brelanJ1 =0, brelanJ2 =0, carreJ1=0, carreJ2=0;
    int color, count= 1;

    size = sizeof(tab)/sizeof(tab[0]);
    sizeColor = sizeof(pique)/sizeof(pique[0]);




    for(i=0 ; i< size ; i++) {
        tab[i] = i+1;
    }

    // afficher tab
    printf("The table consite of: \n");
    for(i=0 ; i< size ; i++) {
        printf("%d ",tab[i]);
    }
    printf("\n");

    for(i=0 ; i < size ; i++) {
        if(i < 13) {
            pique[i] = tab[i];
        }else if( i < 26) {
            cœur[i -13 ] = tab[i];
        }else if( i < 39) {
            trefle[i -26 ] = tab[i];
        }else {
            carreau[i -39 ] = tab[i];
        }
    }


    printf("Pique ♠️: \n");
    for(i=0 ; i< sizeColor ; i++) {
        printf("%d ",pique[i]);
    }
    printf("\n");

    printf("Cœur ♥️: \n");
    for(i=0 ; i<  sizeColor ; i++) {
        printf("%d ",cœur[i]);
    }
    printf("\n");

    printf("Trèfle ♣️: \n");
    for(i=0 ; i< sizeColor ; i++) {
        printf("%d ",trefle[i]);
    }
    printf("\n");

    printf("Carreau ♦️: \n");
    for(i=0 ; i<  sizeColor ; i++) {
        printf("%d ",carreau[i]);
    }
    printf("\n");
    printf("\n");


                                                // Mélanger tableau //

    srand(time(NULL));
    //size-1 CAR la taille du tab fait bien 52, MAIS L'INDICE MAX EST 51
    // Donc le premier indice est or limite sans le -1
    for(i=size-1 ; i >0; i--) {
        valRand = rand() % (i+1);
        temp = tab[valRand];
        tab[valRand] = tab[i];
        tab[i] = temp;
    }

    printf("the new random table:\n");
    for(i=0 ; i<size ; i++) {
        printf("%d ",tab[i]);
    }
    printf("\n");
    printf("\n");


                                            // Distibuer 5 a deux joueurs //
    //distribution 5 part 5
    for(i=0 ; i < 10 ; i++) {
        if(i < 5) {
            j1[i] = tab[i];
        }else {
            j2[i-5] = tab[i];
        }
    }

    // distribution 2 a 2
    /*j=0;
    for(i=0 ; i<10 ; i = i+2) {
        j1[j] = tab[i];
        j2[j] = tab[i+1];
        j+=1;
    }
   */


    /*                                            //Afficher les cartes //
    printf("Joueur 1 🧔🏻‍♂️: \n");
    printf("    ");
    for(i=0 ; i< 5 ; i++) {
        printf("%d ",j1[i]);
    }
    printf("\n");

    printf("Joueur 2 👩🏽‍🦱: \n");
    printf("    ");
    for(i=0 ; i<  5 ; i++) {
        printf("%d ",j2[i]);
    }
    */

                                                //Afficher les cartes V2 //

    printf("Joueur 1 🧔🏻‍♂️: \n");
    printf("    ");
    for(i=0 ; i< 5 ; i++) {
        color = (j1[i]-1)/ 13;
        printcolor(color);
        printf("%d ", (j1[i]-1)% 13 +1);
        j1[i] = (j1[i]-1)% 13 +1;
    }
    printf("\n");

    printf("Joueur 2 👩🏽‍🦱: \n");
    printf("    ");
    for(i=0 ; i<  5 ; i++) {
        color = (j2[i]-1)/ 13;
        printcolor(color);
        printf("%d ",(j2[i]-1)% 13 +1);
        j2[i] = (j2[i]-1)% 13 +1;
    }
    printf("\n");
    printf("\n");

    /*/ pour savoir si la fonction brelan fonctionne
    j1[0] = 5;
    j1[1] = 2;
    j1[2] = 2;
    j1[3] = 2;
    j1[4] = 2;
    */


    // Affichage pour vérifier
    for ( i = 0; i < 5; i++) {
        printf("%d ", j1[i]);
    }
    printf("\n");

                                             // Une paire ?//
    //J1
    for(i=0; i< 4; i++) {
        for(j=i+1; j<5; j++) {
            if(j1[i] == j1[j]) paireJ1+=1;
        }
    }

    //J2
    for(i=0; i< 4; i++) {
        for(j=i+1; j<5; j++) {
            if(j2[i] == j2[j]) paireJ2+=1;
        }
    }

                                            // Un Brelan ?//
    //J1
    for(i=0; i< 3; i++) {
        for(j=i+1; j<4; j++) {
            if(j1[i] == j1[j]) {
                for(z=j+1; z<5; z++) {
                    if(j1[j] == j1[z]){
                        brelanJ1=1;
                        paireJ1 -= 3;
                        break;
                    }
                }
            }
        }
    }
    //J2
    for(i=0; i< 3; i++) {
        for(j=i+1; j<4; j++) {
            if(j2[i] == j2[j]) {
                for(z=j+1; z<5; z++) {
                    if(j2[j] == j2[z]){
                        brelanJ2=1;
                        paireJ2 -= 3;
                        break;
                    }
                }
            }
        }
    }

    //J1
    for(i=0; i< 2; i++) {
        for(j=i+1; j< 5; j++) {
            if (j1[i] == j1[j]) count += 1;
        }
        if (count == 4){
            carreJ1 = 1;
            brelanJ1 = 0;
            paireJ1 = 0;
        }
    }
    count = 1;

    //J2
    for(i=0; i< 2; i++) {
        for(j=i+1; j< 5; j++) {
            if (j2[i] == j2[j]) count += 1;
        }
        if (count == 4){
            carreJ2 = 1;
            brelanJ2 = 0;
            paireJ2 = 0;
        }
    }

    printf("\n");
    printf("The player 1 🧔🏻‍ as %d paire\n", paireJ1);
    printf("The player 1 🧔🏻 as %d brelan\n", brelanJ1);
    printf("The player 1 🧔🏻 as %d Carré\n", carreJ1);
    printf("\n");
    printf("The player 2 👩🏽‍🦱 as %d paire\n", paireJ2);
    printf("The player 1 👩🏽‍🦱 as %d brelan\n", brelanJ2);
    printf("The player 1 🧔🏻 as %d Carré\n", carreJ2);
    return 0;
}
