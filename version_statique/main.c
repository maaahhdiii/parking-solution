#include <stdio.h>
#include <stdlib.h>
#include "parking.h"
#include "statistics.h"

void afficher_menu_principal() {
    printf("\n=================================\n");
    printf("   GESTION DE PARKING\n");
    printf("=================================\n");
    printf("1. Gestion des vehicules\n");
    printf("2. Statistiques\n");
    printf("3. Quitter\n");
    printf("Choix: ");
}

void afficher_menu_vehicules() {
    printf("\n=== Gestion des vehicules ===\n");
    printf("1. Ajouter un vehicule\n");
    printf("2. Supprimer un vehicule\n");
    printf("3. Rechercher un vehicule\n");
    printf("4. Afficher tous les vehicules\n");
    printf("5. Enregistrer une sortie\n");
    printf("6. Modifier un vehicule\n");
    printf("7. Retour au menu principal\n");
    printf("Choix: ");
}

void menu_vehicules(Parking* p) {
    int choix;
    Vehicle v;
    char plaque[MAX_STRING];
    int id, heure;
    Vehicle* found;
    
    do {
        afficher_menu_vehicules();
        scanf("%d", &choix);
        
        switch(choix) {
            case 1:
                printf("\n=== Ajouter un vehicule ===\n");
                printf("ID: ");
                scanf("%d", &v.id);
                printf("Plaque: ");
                scanf("%s", v.plaque);
                printf("Marque: ");
                scanf("%s", v.marque);
                printf("Couleur: ");
                scanf("%s", v.couleur);
                printf("Heure d'arrivee: ");
                scanf("%d", &v.heure_arrivee);
                printf("Tarif horaire: ");
                scanf("%f", &v.tarif_horaire);
                
                if (ajouter_vehicle(p, v)) {
                    printf("Vehicule ajoute avec succes!\n");
                } else {
                    printf("Parking complet!\n");
                }
                break;
                
            case 2:
                printf("\n=== Supprimer un vehicule ===\n");
                printf("ID du vehicule: ");
                scanf("%d", &id);
                if (supprimer_vehicle(p, id)) {
                    printf("Vehicule supprime avec succes!\n");
                } else {
                    printf("Vehicule non trouve!\n");
                }
                break;
                
            case 3:
                printf("\n=== Rechercher un vehicule ===\n");
                printf("Plaque: ");
                scanf("%s", plaque);
                found = rechercher_vehicle(p, plaque);
                if (found != NULL) {
                    printf("\nVehicule trouve:\n");
                    printf("ID: %d\n", found->id);
                    printf("Plaque: %s\n", found->plaque);
                    printf("Marque: %s\n", found->marque);
                    printf("Couleur: %s\n", found->couleur);
                    printf("Heure arrivee: %d\n", found->heure_arrivee);
                    printf("Tarif: %.2f euros/h\n", found->tarif_horaire);
                    printf("Statut: %s\n", found->statut == 1 ? "Present" : "Sorti");
                } else {
                    printf("Vehicule non trouve!\n");
                }
                break;
                
            case 4:
                afficher_vehicles(p);
                break;
                
            case 5:
                printf("\n=== Enregistrer une sortie ===\n");
                printf("ID du vehicule: ");
                scanf("%d", &id);
                printf("Heure de sortie: ");
                scanf("%d", &heure);
                if (!sortie_vehicle(p, id, heure)) {
                    printf("Vehicule non trouve ou deja sorti!\n");
                }
                break;
                
            case 6:
                printf("\n=== Modifier un vehicule ===\n");
                printf("ID du vehicule: ");
                scanf("%d", &id);
                printf("Nouvelle plaque: ");
                scanf("%s", v.plaque);
                printf("Nouvelle marque: ");
                scanf("%s", v.marque);
                printf("Nouvelle couleur: ");
                scanf("%s", v.couleur);
                printf("Nouvelle heure d'arrivee: ");
                scanf("%d", &v.heure_arrivee);
                printf("Nouveau tarif horaire: ");
                scanf("%f", &v.tarif_horaire);
                v.statut = 1;
                modifier_vehicle(p, id, v);
                printf("Vehicule modifie avec succes!\n");
                break;
                
            case 7:
                break;
                
            default:
                printf("Choix invalide!\n");
        }
    } while(choix != 7);
}

int main() {
    Parking parking;
    int choix;
    
    init_parking(&parking);
    
    do {
        afficher_menu_principal();
        scanf("%d", &choix);
        
        switch(choix) {
            case 1:
                menu_vehicules(&parking);
                break;
                
            case 2:
                afficher_statistiques(&parking);
                break;
                
            case 3:
                printf("Au revoir!\n");
                break;
                
            default:
                printf("Choix invalide!\n");
        }
    } while(choix != 3);
    
    return 0;
}
