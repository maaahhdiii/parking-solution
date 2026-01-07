#include "vehicule.h"

void afficher_vehicule(Vehicule *v) {
    if (v == NULL) return;
    
    struct tm *info = localtime(&v->heure_arrivee);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", info);
    
    printf("\n--- Vehicule ID: %d ---\n", v->id);
    printf("Plaque: %s\n", v->plaque);
    printf("Marque: %s\n", v->marque);
    printf("Couleur: %s\n", v->couleur);
    printf("Heure d'arrivee: %s\n", buffer);
    printf("Tarif horaire: %.2f euros\n", v->tarif_horaire);
    printf("Statut: %s\n", v->statut == 1 ? "Dans le parking" : "Sorti");
}

float calculer_montant(Vehicule *v) {
    if (v == NULL) return 0.0;
    
    time_t maintenant = time(NULL);
    double difference = difftime(maintenant, v->heure_arrivee);
    double heures = difference / 3600.0;
    
    if (heures < 1.0) heures = 1.0;
    else heures = ceil(heures);
    
    return heures * v->tarif_horaire;
}

