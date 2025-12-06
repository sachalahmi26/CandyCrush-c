#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Définir la taille du tableau
#define N 25
#define P 45

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

//Sous programme qui efface les items
void effacer(char tab[N][P], int nbpoints){
    int aEffacer[N][P] = {0};
    for(int i=0;i<N;i++){
        for(int j=0;j<P-2;j++){
            char v = tab[i][j];
            if (v != ' ' &&
                tab[i][j+1] == v &&
                tab[i][j+2] == v &&
                tab[i][j+3] == v) {
                aEffacer[i][j] = 1;
                aEffacer[i][j+1] = 1;
                aEffacer[i][j+2] = 1;
                aEffacer[i][j+3] = 1;
                nbpoints = nbpoints + 800;
            }
        }
    }
    for(int j=0;j<P;j++){
        for(int i=0;i<N-2;i++){
            char v = tab[i][j];
            if (v != ' ' &&
                tab[i+1][j] == v &&
                tab[i+2][j] == v &&
                tab[i+3][j] == v) {
                aEffacer[i][j] = 1;
                aEffacer[i+1][j] = 1;
                aEffacer[i+2][j] = 1;
                aEffacer[i+3][j] = 1;
                nbpoints = nbpoints + 800;
            }
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<P;j++){
            if(aEffacer[i][j] == 1){
                tab[i][j] = ' ';
            }
        }
    }
    printf("\n");
    printf("Nombre de points : %d\n", nbpoints);
    printf("\n");
}

void gravite(char tab[N][P]) {
    for (int j = 0; j < P; j++) {
        int bas = N - 1;
        for (int i = N - 1; i >= 0; i--) {
            if (tab[i][j] != ' ') {
                tab[bas][j] = tab[i][j];
                if (bas != i) {
                    tab[i][j] = ' ';
                }
                bas--;
            }
        }
        while (bas >= 0) {
            char items[]={'O','X','#','$','*'};
            int nbItems = 5;
            tab[bas][j] = items[rand()%nbItems];   // Nouvel item aléatoire
            bas--;
        }
    }
}

int main(){
    int choix;
    int nbpoints=0;
    char tab[N][P];
    printf("1. Lire les regles du jeu\n");
    printf("2. Commencer une nouvelle partie (A partir du 1er niveau)\n");
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
        printf("Nombre de vies : %d\n", nb_vies);
        srand(time(NULL));
        remplir(tab);
        affichergrille(tab);
        printf("\n");
        effacer(tab, nbpoints);
        gravite(tab);
        affichergrille(tab);
        return 0;
    }
    else if(choix==4){
        printf("Vous avez quitte\n");
        return 0;
    }
    while(choix<1||choix>4){
        printf("Erreur vous devez saisir un choix\n");
        return main();
    }
}
