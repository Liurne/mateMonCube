#include <stdio.h>

// Structure représentant une matrice
typedef struct {
    int width;
    int height;
    int* data;  // Tableau à une dimension représentant les éléments de la matrice
} Matrix;

// Fonction de copie basique
void copyMatrix(const Matrix* src, int srcX, int srcY, Matrix* dest, int destX, int destY, int copyWidth, int copyHeight) {
    for (int y = 0; y < copyHeight; ++y) {
        for (int x = 0; x < copyWidth; ++x) {
            // Calcul des indices dans les matrices source et destination
            int srcIndex = (srcY + y) * src->width + (srcX + x);
            int destIndex = (destY + y) * dest->width + (destX + x);

            // Copie de l'élément de la source vers la destination
            dest->data[destIndex] = src->data[srcIndex];
        }
    }
}

int main() {
    // Exemple d'utilisation
    Matrix source = {3, 3, (int[]){1, 2, 3, 4, 5, 6, 7, 8, 9}};
    Matrix destination = {3, 3, (int[]){0, 0, 0, 0, 0, 0, 0, 0, 0}};

    copyMatrix(&source, 0, 0, &destination, 1, 1, 2, 2);

    // Affichage du résultat
    for (int y = 0; y < destination.height; ++y) {
        for (int x = 0; x < destination.width; ++x) {
            int index = y * destination.width + x;
            printf("%d ", destination.data[index]);
        }
        printf("\n");
    }

    return 0;
}