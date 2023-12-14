#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Matrice.h"  


int main() {
    int n;

    printf("Veuillez saisir la taille de la matrice A : ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Taille de matrice invalide.\n");
        return EXIT_FAILURE;
    }

    int **A = get_random_matrice(n);
    if (A == NULL) {
        fprintf(stderr, "Erreur lors de l'allocation de mémoire pour la matrice A.\n");
        return EXIT_FAILURE;
    }

    printf("La matrice A avant convolution :\n");
    afficherMatrice(A, n);

    int **A_avec_bordures = ajouterBordure(A, n);
    if (A_avec_bordures == NULL) {
        fprintf(stderr, "Erreur lors de l'ajout de bordures à la matrice A.\n");
        libererMatrice(A, n);
        return EXIT_FAILURE;
    }

    int **B = get_random_matrice(3);
    if (B == NULL) {
        fprintf(stderr, "Erreur lors de l'allocation de mémoire pour la matrice B.\n");
        libererMatrice(A, n);
        libererMatrice(A_avec_bordures, n + 2);
        return EXIT_FAILURE;
    }

    printf("La matrice B :\n");
    afficherMatrice(B, 3);

    int **conv = conv_matrices(A_avec_bordures, n, B, 3);
    if (conv == NULL) {
        fprintf(stderr, "Erreur lors du calcul de la convolution.\n");
        libererMatrice(A, n);
        libererMatrice(A_avec_bordures, n + 2);
        libererMatrice(B, 3);
        return EXIT_FAILURE;
    }

    printf("Résultat de la convolution avec bordures :\n");
    afficherMatrice(conv, n + 2);

    int **conv_sans_bordures = enleverBordure(conv, n + 2);
    if (conv_sans_bordures == NULL) {
        fprintf(stderr, "Erreur lors de la suppression des bordures.\n");
        libererMatrice(A, n);
        libererMatrice(A_avec_bordures, n + 2);
        libererMatrice(B, 3);
        libererMatrice(conv, n + 2);
        return EXIT_FAILURE;
    }

    printf("Résultat de la convolution sans bordures :\n");
    afficherMatrice(conv_sans_bordures, n);

    libererMatrice(A, n);
    libererMatrice(A_avec_bordures, n + 2);
    libererMatrice(B, 3);
    libererMatrice(conv, n + 2);
    libererMatrice(conv_sans_bordures, n);

    return EXIT_SUCCESS;
}
