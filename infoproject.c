#include "infoproject.h"

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

// Sous-programme pour afficher la grille avec des couleurs
void afficherGrilleCouleur(char tab[N][P]) {
    printf("\n    ");
    for(int j=0; j<P; j++) printf("%d ", j); // Affiche numéros colonnes
    printf("\n   %s\n", "---------------------");

    for (int i = 0; i < N; i++) {
        printf("%d | ", i); // Affiche numéros lignes
        for (int j = 0; j < P; j++) {
            switch (tab[i][j]) {
                case 'O': printf("\033[1;31mO \033[0m"); break; // Rouge
                case 'X': printf("\033[1;34mX \033[0m"); break; // Bleu
                case '#': printf("\033[1;32m# \033[0m"); break; // Vert
                case '$': printf("\033[1;33m$ \033[0m"); break; // Jaune
                case '*': printf("\033[1;35m* \033[0m"); break; // Magenta
                default:  printf("  "); break;
            }
        }
        printf("\n");
    }
    printf("\n");
}

//Sous programme qui efface les items et compte les points
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

//Fonction qui qui fait tomber et réapparaître les items
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

//Sous progamme qui inverse deux cases
char inverser(char tab[N][P], int i, int j, int k, int l){
    char temp = tab[k][l];
    tab[k][l] = tab[i][j];
    tab[i][j] = temp;
}


//Programme principale qui affiche le menu, les options, déclare les variables, et execute les sous programmes
int main(){
    int choix;
    int nbpoints=0;
    int i, j, k, l;
    int duree = 120;
    time_t debut = time(NULL);
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
        effacer(tab, nbpoints);
        gravite(tab);
        affichergrille(tab);
        printf("Saisir la ligne et la colonne de la premiere case : ");
        scanf("%d %d", &i, &j);
        printf("Saisir la ligne et la colonne de la deuxieme case : ");
        scanf("%d %d", &k, &l);
        while (difftime(time(NULL), debut) < duree){
        if((i==k&&(j==l-1||j==l+1))||(j==l&&(i==k-1||i==k+1))){
            inverser(tab, i, j, k, l);
            printf("\nTableau par inversions\n");
            affichergrille(tab);
            effacer(tab, nbpoints);
            gravite(tab);
            affichergrille(tab);
            return 0;
        }
        else{
            printf("Erreur");
        }
        }
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
