#include "statistic.h"

void afficher_statistiques(Parking *parking) {
    float taux_occupation = 0.0;
    if (parking->total_entrees > 0) {
        taux_occupation = ((float)parking->places_occupees / MAX_PLACES) * 100.0;
    }
    
    printf("\n=== STATISTIQUES DU PARKING ===\n");
    printf("Total vehicules entres: %d\n", parking->total_entrees);
    printf("Total vehicules sortis: %d\n", parking->total_sorties);
    printf("Vehicules actuellement dans le parking: %d\n", parking->places_occupees);
    printf("Taux d'occupation actuel: %.2f%%\n", taux_occupation);
    printf("Revenu total de la journee: %.2f euros\n", parking->revenu_total);
    printf("================================\n\n");
}

