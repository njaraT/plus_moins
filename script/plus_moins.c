#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void plus_moins() {
    int nombreMystere, nombreUtilisateur;
    int essais = 0;

    // Initialisation de l'aléatoire
    srand(time(NULL));
    nombreMystere = rand() % 100 + 1; // Nombre entre 1 et 100

    printf("=== Jeu du Plus ou Moins ===\n");
    printf("J'ai choisi un nombre entre 1 et 100. À vous de deviner !\n");

    do {
        printf("Votre proposition : ");
        scanf("%d", &nombreUtilisateur);
        essais++;

        if (nombreUtilisateur < nombreMystere) {
            printf("C'est plus !\n");
        } else if (nombreUtilisateur > nombreMystere) {
            printf("C'est moins !\n");
        } else {
            printf("Bravo ! Vous avez trouvé le nombre mystère en %d essai(s) !\n", essais);
        }

    } while (nombreUtilisateur != nombreMystere);
}

int main() {
    plus_moins();
    return 0;
}

