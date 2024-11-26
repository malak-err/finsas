#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TACHES 100

typedef struct {
    char titre[100];
    char description[200];
    char date_echeance[20];
    char priorite[10];
} Tache;

Tache taches[MAX_TACHES];
int nb_taches = 0;

void afficherMenu() {
    printf("\nMenu de Gestion des Tâches:\n");
    printf("1. Ajouter une tâche\n");
    printf("2. Afficher toutes les tâches\n");
    printf("3. Modifier une tâche\n");
    printf("4. Supprimer une tâche\n");
    printf("5. Filtrer les tâches par priorité\n");
    printf("6. Quitter\n");
    printf("Entrez votre choix: ");
}

void ajouterTache() {
    if (nb_taches < MAX_TACHES) {
        printf("Entrez le titre de la tâche: ");
        scanf("%s", taches[nb_taches].titre);

        printf("Entrez la description de la tâche: ");
        scanf("%s", taches[nb_taches].description);

        printf("Entrez la date d'échéance (JJ/MM/AAAA): ");
        scanf("%s", taches[nb_taches].date_echeance);

        printf("Entrez la priorité (High/Low): ");
        scanf("%s", taches[nb_taches].priorite);

        nb_taches++;
        printf("Tâche ajoutée avec succès!\n");
    } else {
        printf("Le nombre maximum de tâches a été atteint.\n");
    }
}

void afficherTaches() {
    if (nb_taches == 0) {
        printf("Aucune tâche à afficher.\n");
    } else {
        printf("Liste des tâches:\n");
        for (int i = 0; i < nb_taches; i++) {
            printf("Tâche %d:\n", i + 1);
            printf("Titre: %s\n", taches[i].titre);
            printf("Description: %s\n", taches[i].description);
            printf("Date d'échéance: %s\n", taches[i].date_echeance);
            printf("Priorité: %s\n", taches[i].priorite);
        }
    }
}

void modifierTache() {
    int index;
    printf("Entrez l'indice de la tâche à modifier (1-%d): ", nb_taches);
    scanf("%d", &index);

    if (index > 0 && index <= nb_taches) {
        index--;
        printf("Modifications de la tâche %d:\n", index + 1);

        printf("Entrez le nouveau titre: ");
        scanf("%99s", taches[index].titre);

        printf("Entrez la nouvelle description: ");
        scanf("%199s", taches[index].description);

        printf("Entrez la nouvelle date d'échéance (JJ/MM/AAAA): ");
        scanf("%19s", taches[index].date_echeance);

        printf("Entrez la nouvelle priorité (High/Low): ");
        scanf("%9s", taches[index].priorite);

        printf("Tâche modifiée avec succès!\n");
    } else {
        printf("Tâche introuvable!\n");
    }
}

void supprimerTache() {
    int index;
    printf("Entrez l'indice de la tâche à supprimer (1-%d): ", nb_taches);
    scanf("%d", &index);

    if (index > 0 && index <= nb_taches) {
        index--;
        for (int i = index; i < nb_taches - 1; i++) {
            taches[i] = taches[i + 1];
        }
        nb_taches--;
        printf("Tâche supprimée avec succès!\n");
    } else {
        printf("Tâche introuvable!\n");
    }
}

void filtrerParPriorite() {
    char priorite[10];
    printf("Entrez la priorité à filtrer (High/Low): ");
    scanf("%9s", priorite);

    printf("Liste des tâches avec priorité %s:\n", priorite);
    int trouve = 0;
    for (int i = 0; i < nb_taches; i++) {
        if (strcmp(taches[i].priorite, priorite) == 0) {
            printf("\nTâche %d:\n", i + 1);
            printf("Titre: %s\n", taches[i].titre);
            printf("Description: %s\n", taches[i].description);
            printf("Date d'échéance: %s\n", taches[i].date_echeance);
            printf("Priorité: %s\n", taches[i].priorite);
            trouve = 1;
        }
    }
    if (!trouve) {
        printf("Aucune tâche avec cette priorité.\n");
    }
}

int main() {
    int choix;
    do {
        afficherMenu();
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouterTache();
                break;
            case 2:
                afficherTaches();
                break;
            case 3:
                modifierTache();
                break;
            case 4:
                supprimerTache();
                break;
            case 5:
                filtrerParPriorite();
                break;
            case 6:
                printf("Merci !\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choix != 6);

    return 0;
}
