#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


//Fonctions


//Constante 

#define LIMITE 10000



// Implementaion : 


/* Libérer la mémoire allouée pour la matrice */

void libererMatrice(int **matrice, int n) {
    if (matrice != NULL) {
        for (int i = 0; i < n; i++) {
            free(matrice[i]);
        }
        free(matrice);
    }
}

/* Allouer la taille de la matrice */

int **allouerMatrice(int n) {
    if (n <= 0) {
        fprintf(stderr, "Taille de matrice invalide.\n");
        return NULL;
    }

    int **matrice = (int **)malloc(sizeof(int *) * n);
    if (matrice == NULL) {
        fprintf(stderr, "Erreur d'allocation de mémoire.\n");
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        matrice[i] = (int *)malloc(sizeof(int) * n);
        if (matrice[i] == NULL) {
            fprintf(stderr, "Erreur d'allocation de mémoire.\n");
            libererMatrice(matrice, i); // Libération partielle en cas d'erreur
            return NULL;
        }
    }

    return matrice;
}


/* Ajouter une bordure de 0 à la matrice*/

int **ajouterBordure(int **matrice, int n) {
    int **matriceAvecBordure = allouerMatrice(n + 2);
    if (matriceAvecBordure == NULL) {
        return NULL;
    }

    for (int i = 0; i < n + 2; i++) {
        for (int j = 0; j < n + 2; j++) {
            if (i == 0 || i == n + 1 || j == 0 || j == n + 1) {
                matriceAvecBordure[i][j] = 0;
            } else {
                matriceAvecBordure[i][j] = matrice[i - 1][j - 1];
            }
        }
    }

    return matriceAvecBordure;
}

 /* Remplir la matrice aléatoirement  */

int **get_random_matrice(int n) {
     
    
        int **matrice = allouerMatrice(n);

            for (int i = 0; i < n; i++)
           {
            for (int j = 0; j < n; j++)
           {
            matrice[i][j] = rand() % 10;
           }
           }
           
return matrice ; 

 }

/* Affichage de la matrice */

void afficherMatrice(int **matrice, int n) {
    if (matrice == NULL) {
        fprintf(stderr, "Matrice invalide.\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%5d ", matrice[i][j]); // Format amélioré pour l'affichage
        }
        printf("\n");
    }
}


/* Calcul de la trace de la matrice */

 int trace_matrice(int **matrice, int n){

    int trace = 0;
    for (int i = 0; i < n; i++) {
        trace += matrice[i][i];
    }

    return trace ;
 }



/* Produit convolutionnel */

 int **conv_matrices(int **A, int n, int **B, int p) {
    // Assuming allouerMatrice(n) allocates memory for an (n+2) x (n+2) matrix and returns it
    int **matrice = allouerMatrice(n + 2);

    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            int somme = 0;
            for (int y = 0; y < p; y++) {
                for (int x = 0; x < p; x++) {
                    somme += A[i + y][j + x] * B[y][x];
                }
            }
            matrice[i + 1][j + 1] = somme;
        }
    }

    return matrice;
}

/* Enlever les bordures de la matrice */

int **enleverBordure(int **matrice_avec_bordure, int n) {
    if (matrice_avec_bordure == NULL || n <= 2) {
        return NULL;
    }

    int **matrice_sans_bordure = allouerMatrice(n - 2);
    if (matrice_sans_bordure == NULL) {
        return NULL;
    }

    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < n - 2; j++) {
            matrice_sans_bordure[i][j] = matrice_avec_bordure[i + 1][j + 1];
        }
    }

    return matrice_sans_bordure;
}
