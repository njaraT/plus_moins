#include <stdio.h>
#include <stdlib.h>
#modifier
#define MIN_ESSAIS 10

int demander_nombre_secret(int joueur) {
    int nombre;
    printf("\nJoueur %d, entrez un nombre mystère (1 à 100) pour votre adversaire : ", joueur);
    scanf("%d", &nombre);
    while (nombre < 1 || nombre > 100) {
        printf("Nombre invalide. Choisissez un nombre entre 1 et 100 : ");
        scanf("%d", &nombre);
    }
    return nombre;
}

int demander_nombre_essais() {
    int essais;
    printf("Définissez le nombre d'essais (minimum %d) : ", MIN_ESSAIS);
    scanf("%d", &essais);
    while (essais < MIN_ESSAIS) {
        printf("Minimum %d essais. Essayez encore : ", MIN_ESSAIS);
        scanf("%d", &essais);
    }
    return essais;
}

int phase_devineur(int devineur, int nombreMystere, int maxEssais) {
    int proposition;
    int essais = 0;

    printf("\n>>> Joueur %d doit deviner le nombre ! <<<\n", devineur);

    do {
        essais++;
        printf("Essai %d / %d - Entrez votre proposition : ", essais, maxEssais);
        scanf("%d", &proposition);

        if (proposition < nombreMystere) {
            printf("C'est plus !\n");
        } else if (proposition > nombreMystere) {
            printf("C'est moins !\n");
        } else {
            printf("Bravo Joueur %d ! Vous avez trouvé en %d essai(s) !\n", devineur, essais);
            return essais;
        }

    } while (essais < maxEssais);

    printf("Dommage ! Joueur %d n'a pas trouvé. Le nombre était : %d\n", devineur, nombreMystere);
    return 0; // 0 point si pas trouvé
}

void plus_moins_2_joueurs() {
    int scoreJ1 = 0, scoreJ2 = 0;
    int nombre, essaisMax, essaisUtilises;

    printf("=== Mode 2 Joueurs ===\n");

    // Tour du joueur 1
    printf("\n--- Tour 1 ---\n");
    nombre = demander_nombre_secret(1);
    essaisMax = demander_nombre_essais();
    essaisUtilises = phase_devineur(2, nombre, essaisMax);
    if (essaisUtilises > 0) {
        scoreJ2 = essaisMax - essaisUtilises + 1; // Plus il trouve tôt, plus il marque
    }

    // Tour du joueur 2
    printf("\n--- Tour 2 ---\n");
    nombre = demander_nombre_secret(2);
    essaisMax = demander_nombre_essais();
    essaisUtilises = phase_devineur(1, nombre, essaisMax);
    if (essaisUtilises > 0) {
        scoreJ1 = essaisMax - essaisUtilises + 1;
    }

    // Affichage des scores
    printf("\n=== Résultats ===\n");
    printf("Score Joueur 1 : %d\n", scoreJ1);
    printf("Score Joueur 2 : %d\n", scoreJ2);

    if (scoreJ1 > scoreJ2) {
        printf("🏆 Joueur 1 gagne !\n");
    } else if (scoreJ2 > scoreJ1) {
        printf("🏆 Joueur 2 gagne !\n");
    } else {
        printf("🤝 Égalité !\n");
    }
}

int main() {
    plus_moins_2_joueurs();
    return 0;
}

