#include "parking.h"
#include "statistic.h"

int main() {
    Parking parking;
    initialiser_parking(&parking);
    
    int choix_principal, choix_vehicules;
    char plaque[MAX_STRING], marque[MAX_STRING], couleur[MAX_STRING];
    float tarif;
    Vehicule *v;
    
    printf("Bienvenue dans le systeme de gestion de parking!\n");
    
    while (1) {
        afficher_menu_principal();
        scanf("%d", &choix_principal);
        getchar();
        
        switch (choix_principal) {
            case 1:
                while (1) {
                    afficher_menu_vehicules();
                    scanf("%d", &choix_vehicules);
                    getchar();
                    
                    switch (choix_vehicules) {
                        case 1:
                            printf("\n--- Ajout d'un vehicule ---\n");
                            printf("Plaque d'immatriculation: ");
                            fgets(plaque, MAX_STRING, stdin);
                            plaque[strcspn(plaque, "\n")] = 0;
                            
                            printf("Marque: ");
                            fgets(marque, MAX_STRING, stdin);
                            marque[strcspn(marque, "\n")] = 0;
                            
                            printf("Couleur: ");
                            fgets(couleur, MAX_STRING, stdin);
                            couleur[strcspn(couleur, "\n")] = 0;
                            
                            printf("Tarif horaire (euros): ");
                            scanf("%f", &tarif);
                            getchar();
                            
                            ajouter_vehicule(&parking, plaque, marque, couleur, tarif);
                            break;
                            
                        case 2:
                            printf("\n--- Enregistrement d'une sortie ---\n");
                            printf("Plaque d'immatriculation: ");
                            fgets(plaque, MAX_STRING, stdin);
                            plaque[strcspn(plaque, "\n")] = 0;
                            
                            enregistrer_sortie(&parking, plaque);
                            break;
                            
                        case 3:
                            printf("\n--- Suppression d'un vehicule ---\n");
                            printf("Plaque d'immatriculation: ");
                            fgets(plaque, MAX_STRING, stdin);
                            plaque[strcspn(plaque, "\n")] = 0;
                            
                            supprimer_vehicule(&parking, plaque);
                            break;
                            
                        case 4:
                            printf("\n--- Recherche d'un vehicule ---\n");
                            printf("Plaque d'immatriculation: ");
                            fgets(plaque, MAX_STRING, stdin);
                            plaque[strcspn(plaque, "\n")] = 0;
                            
                            v = rechercher_vehicule(&parking, plaque);
                            if (v != NULL) {
                                afficher_vehicule(v);
                            } else {
                                printf("Vehicule non trouve!\n");
                            }
                            break;
                            
                        case 5:
                            afficher_vehicules_presents(&parking);
                            break;
                            
                        case 6:
                            afficher_places_disponibles(&parking);
                            break;
                            
                        case 7:
                            goto menu_principal;
                            
                        default:
                            printf("Choix invalide!\n");
                    }
                }
                menu_principal:
                break;
                
            case 2:
                afficher_statistiques(&parking);
                break;
                
            case 3:
                printf("\nMerci d'avoir utilise le systeme de gestion de parking!\n");
                printf("Au revoir!\n");
                return 0;
                
            default:
                printf("Choix invalide! Veuillez reessayer.\n");
        }
    }
    
    return 0;
}
