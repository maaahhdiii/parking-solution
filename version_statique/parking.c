#include "parking.h"
#include "vehicule.h"

void initialiser_parking(Parking *parking) {
    parking->nombre_vehicules = 0;
    parking->places_occupees = 0;
    parking->revenu_total = 0.0;
    parking->total_entrees = 0;
    parking->total_sorties = 0;
}

int ajouter_vehicule(Parking *parking, char *plaque, char *marque, char *couleur, float tarif) {
    if (parking->places_occupees >= MAX_PLACES) {
        printf("Erreur: Le parking est complet!\n");
        return 0;
    }
    
    if (parking->nombre_vehicules >= MAX_VEHICLES) {
        printf("Erreur: Nombre maximum de vehicules atteint!\n");
        return 0;
    }
    
    if (rechercher_vehicule(parking, plaque) != NULL) {
        printf("Erreur: Un vehicule avec cette plaque existe deja!\n");
        return 0;
    }
    
    Vehicule *v = &parking->vehicules[parking->nombre_vehicules];
    v->id = parking->nombre_vehicules + 1;
    strcpy(v->plaque, plaque);
    strcpy(v->marque, marque);
    strcpy(v->couleur, couleur);
    v->heure_arrivee = time(NULL);
    v->tarif_horaire = tarif;
    v->statut = 1;
    
    parking->nombre_vehicules++;
    parking->places_occupees++;
    parking->total_entrees++;
    
    printf("Vehicule ajoute avec succes! ID: %d\n", v->id);
    return 1;
}

int supprimer_vehicule(Parking *parking, char *plaque) {
    int i;
    for (i = 0; i < parking->nombre_vehicules; i++) {
        if (strcmp(parking->vehicules[i].plaque, plaque) == 0) {
            int j;
            for (j = i; j < parking->nombre_vehicules - 1; j++) {
                parking->vehicules[j] = parking->vehicules[j + 1];
            }
            parking->nombre_vehicules--;
            if (parking->vehicules[i].statut == 1) {
                parking->places_occupees--;
            }
            printf("Vehicule supprime avec succes!\n");
            return 1;
        }
    }
    printf("Erreur: Vehicule non trouve!\n");
    return 0;
}

Vehicule* rechercher_vehicule(Parking *parking, char *plaque) {
    int i;
    for (i = 0; i < parking->nombre_vehicules; i++) {
        if (strcmp(parking->vehicules[i].plaque, plaque) == 0) {
            return &parking->vehicules[i];
        }
    }
    return NULL;
}

void afficher_vehicules_presents(Parking *parking) {
    int i;
    int count = 0;
    
    printf("\n=== Liste des vehicules dans le parking ===\n");
    for (i = 0; i < parking->nombre_vehicules; i++) {
        if (parking->vehicules[i].statut == 1) {
            afficher_vehicule(&parking->vehicules[i]);
            count++;
        }
    }
    
    if (count == 0) {
        printf("Aucun vehicule dans le parking.\n");
    } else {
        printf("Total: %d vehicule(s)\n", count);
    }
}

int enregistrer_sortie(Parking *parking, char *plaque) {
    Vehicule *v = rechercher_vehicule(parking, plaque);
    
    if (v == NULL) {
        printf("Erreur: Vehicule non trouve!\n");
        return 0;
    }
    
    if (v->statut == 0) {
        printf("Erreur: Ce vehicule est deja sorti!\n");
        return 0;
    }
    
    float montant = calculer_montant(v);
    v->statut = 0;
    parking->places_occupees--;
    parking->revenu_total += montant;
    parking->total_sorties++;
    
    printf("\n=== Sortie enregistree ===\n");
    printf("Plaque: %s\n", v->plaque);
    printf("Montant a payer: %.2f euros\n", montant);
    printf("Revenu total: %.2f euros\n", parking->revenu_total);
    
    return 1;
}

void afficher_places_disponibles(Parking *parking) {
    int places_libres = MAX_PLACES - parking->places_occupees;
    printf("\n=== Etat du parking ===\n");
    printf("Places occupees: %d\n", parking->places_occupees);
    printf("Places disponibles: %d\n", places_libres);
    printf("Capacite totale: %d\n", MAX_PLACES);
}

void afficher_revenu_total(Parking *parking) {
    printf("\n=== Revenu total ===\n");
    printf("Montant collecte: %.2f euros\n", parking->revenu_total);
}

void afficher_menu_principal() {
    printf("\n========================================\n");
    printf("    GESTION DE PARKING INTELLIGENT\n");
    printf("========================================\n");
    printf("1. Gestion des vehicules\n");
    printf("2. Statistiques\n");
    printf("3. Quitter\n");
    printf("========================================\n");
    printf("Votre choix: ");
}

void afficher_menu_vehicules() {
    printf("\n========================================\n");
    printf("    GESTION DES VEHICULES\n");
    printf("========================================\n");
    printf("1. Ajouter un vehicule\n");
    printf("2. Enregistrer une sortie\n");
    printf("3. Supprimer un vehicule\n");
    printf("4. Rechercher un vehicule\n");
    printf("5. Afficher tous les vehicules\n");
    printf("6. Afficher places disponibles\n");
    printf("7. Retour au menu principal\n");
    printf("========================================\n");
    printf("Votre choix: ");
}
