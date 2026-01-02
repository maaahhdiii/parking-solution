#include <stdio.h>
#include "statistics.h"

void afficher_statistiques(Parking* p) {
    printf("\n=== Statistiques du parking ===\n");
    printf("Capacite totale: %d places\n", p->capacite_max);
    printf("Places occupees: %d\n", places_occupees(p));
    printf("Places disponibles: %d\n", places_disponibles(p));
    printf("Total vehicules entres: %d\n", p->total_entrees);
    printf("Total vehicules sortis: %d\n", p->total_sorties);
    printf("Taux d'occupation moyen: %.2f%%\n", calculer_taux_occupation(p));
    printf("Revenu total collecte: %.2f euros\n", p->montant_total);
}

float calculer_taux_occupation(Parking* p) {
    if (p->total_entrees == 0) {
        return 0.0;
    }
    return (float)places_occupees(p) / p->capacite_max * 100.0;
}
