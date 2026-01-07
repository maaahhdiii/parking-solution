#include "parking.h"
#include "vehicule.h"

void initialiser_parking(Parking *parking) {
    parking->premier = NULL;
    parking->nombre_vehicules = 0;
    parking->places_occupees = 0;
    parking->revenu_total = 0.0;
    parking->total_entrees = 0;
    parking->total_sorties = 0;
    parking->dernier_id = 0;
}

int ajouter_vehicule(Parking *parking, char *plaque, char *marque, char *couleur, float tarif) {
    if (parking->places_occupees >= MAX_PLACES) {
        printf("Erreur: Le parking est complet!\n");
        return 0;
    }
    
    if (rechercher_vehicule(parking, plaque) != NULL) {
        printf("Erreur: Un vehicule avec cette plaque existe deja!\n");
        return 0;
    }
    
    Vehicule *nouveau = (Vehicule*)malloc(sizeof(Vehicule));
    if (nouveau == NULL) {
        printf("Erreur: Allocation memoire echouee!\n");
        return 0;
    }
    
    parking->dernier_id++;
    nouveau->id = parking->dernier_id;
    strcpy(nouveau->plaque, plaque);
    strcpy(nouveau->marque, marque);
    strcpy(nouveau->couleur, couleur);
    nouveau->heure_arrivee = time(NULL);
    nouveau->tarif_horaire = tarif;
    nouveau->statut = 1;
    nouveau->suivant = parking->premier;
    
    parking->premier = nouveau;
    parking->nombre_vehicules++;
    parking->places_occupees++;
    parking->total_entrees++;
    
    printf("Vehicule ajoute avec succes! ID: %d\n", nouveau->id);
    return 1;
}

int supprimer_vehicule(Parking *parking, char *plaque) {
    Vehicule *courant = parking->premier;
    Vehicule *precedent = NULL;
    
    while (courant != NULL) {
        if (strcmp(courant->plaque, plaque) == 0) {
            if (precedent == NULL) {
                parking->premier = courant->suivant;
            } else {
                precedent->suivant = courant->suivant;
            }
            
            if (courant->statut == 1) {
                parking->places_occupees--;
            }
            
            free(courant);
            parking->nombre_vehicules--;
            printf("Vehicule supprime avec succes!\n");
            return 1;
        }
        precedent = courant;
        courant = courant->suivant;
    }
    
    printf("Erreur: Vehicule non trouve!\n");
    return 0;
}

Vehicule* rechercher_vehicule(Parking *parking, char *plaque) {
    Vehicule *courant = parking->premier;
    
    while (courant != NULL) {
        if (strcmp(courant->plaque, plaque) == 0) {
            return courant;
        }
        courant = courant->suivant;
    }
    
    return NULL;
}

void afficher_vehicules_presents(Parking *parking) {
    Vehicule *courant = parking->premier;
    int count = 0;
    
    printf("\n=== Liste des vehicules dans le parking ===\n");
    while (courant != NULL) {
        if (courant->statut == 1) {
            afficher_vehicule(courant);
            count++;
        }
        courant = courant->suivant;
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

void liberer_parking(Parking *parking) {
    Vehicule *courant = parking->premier;
    Vehicule *suivant;
    
    while (courant != NULL) {
        suivant = courant->suivant;
        free(courant);
        courant = suivant;
    }
    
    parking->premier = NULL;
    parking->nombre_vehicules = 0;
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
