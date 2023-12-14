#ifndef MATRICE_H
#define MATRICE_H

void libererMatrice(int **matrice, int n);
int **allouerMatrice(int n);
int **ajouterBordure(int **matrice, int n);
int **get_random_matrice(int n);
void afficherMatrice(int **matrice, int n) ;
int trace_matrice(int **matrice, int n);
int **conv_matrices(int **A, int n, int **B, int p);
int **enleverBordure(int **matrice_avec_bordure, int n);


#endif 