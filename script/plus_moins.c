#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void plus_moins() {
    int nombreMystere, nombreUtilisateur;
    int essais = 0;
    int maxEssais = -1;
    int niveau;

    // Choix du niveau de difficulté
    printf("=== Jeu du Plus ou Moins ===\n");
    printf("Choisissez un niveau de difficulté :\n");
    printf("1 - Facile (illimité)\n");
    printf("2 - Moyen (25 essais)\n");
    printf("3 - Difficile (10 essais)\n");
    printf("Votre choix : ");
    scanf("%d", &niveau);

    switch (niveau) {
        case 1:
            maxEssais = -1; // illimité
            break;
        case 2:
            maxEssais = 25;
            break;
        case 3:
            maxEssais = 10;
            break;
        default:
            printf("Niveau invalide. Le niveau facile sera utilisé par défaut.\n");
            maxEssais = -1;
            break;
    }

    // Initialisation du nombre aléatoire
    srand(time(NULL));
    nombreMystere = rand() % 100 + 1;

    printf("J'ai choisi un nombre entre 1 et 100. Essayez de le deviner !\n");

    do {
        printf("Essai %d", essais + 1);
        if (maxEssais > 0) {
            printf(" / %d", maxEssais);
        }
        printf(" - Votre proposition : ");
        scanf("%d", &nombreUtilisateur);
        essais++;

        if (nombreUtilisateur < nombreMystere) {
            printf("C'est plus !\n");
        } else if (nombreUtilisateur > nombreMystere) {
            printf("C'est moins !\n");
        } else {
            printf("Bravo ! Vous avez trouvé le nombre mystère en %d essai(s) !\n", essais);
            return;
        }

        if (maxEssais > 0 && essais >= maxEssais) {
            printf("Dommage ! Vous avez atteint la limite d'essais. Le nombre mystère était : %d\n", nombreMystere);
            return;
        }

    } while (1);
}

int main() {
    plus_moins();
    return 0;
}

