#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Définir la taille du tableau
#define N 25
#define P 45

//Sous programme qui affiche le menu
int affichermenu(){
    int choix;
    printf("1. Lire les regles du jeu\n");
    printf("2. Commencer une nouvelle partie (à partir du 1er niveau)\n");
    printf("3. Reprendre une partie (au dernier niveau enregistre)\n");
    printf("4. Quitter\n");
    printf("Votre choix : ");
    scanf("%d", &choix);
    if(choix==1){
        printf("Il y a trois niveaux de difficultes croissantes\n");
        printf("Vous avez un nombre de vies attibuee qui est limite\n");
        printf("Quand vous perdez un niveau vous perdez une vie\n");
        printf("Vous devez eliminer un grand nombre d'items en un nombre maximum de coups et en un temps limite\n");
        return 0;
    }
    else if(choix==2){
        printf("Vous avez commence une nouvelle partie\n");
        srand(time(NULL));
        int nb_vies = rand()%21;
        printf("Nombre de vies : %d", nb_vies);
    }
    else if(choix==4){
        printf("Vous avez quitte\n");
        return 0;
    }
    else if(choix<1||choix>4){
        printf("Erreur vous devez saisir un choix\n");
        return 0;
    }
}

//Sous programme qui remplit le tableau par des items
void remplir(char tab[N][P]){
    char items[]={'O','X','#','$','*'};
    int nbItems=5;
    for(int i=0;i<N;i++){
        for(int j=0;j<P;j++){
            tab[i][j]=items[rand()%nbItems];
        }
    }
}

//Sous programme qui affiche les valeurs du tableau
void affichergrille(char tab[N][P]){
    for(int i=0;i<N;i++){
        for(int j=0;j<P;j++){
            printf("%c ", tab[i][j]);
        }
        printf("\n");
    }
}

int main(){
    char tab[N][P];
    srand(time(NULL));
    remplir(tab);
    affichergrille(tab);
    return 0;
}
