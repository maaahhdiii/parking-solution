#ifndef PARKING_H
#define PARKING_H

#include "vehicle.h"

#define MAX_PLACES 50

typedef struct {
    Vehicle vehicles[MAX_PLACES];
    int nb_vehicles;
    int capacite_max;
    float montant_total;
    int total_entrees;
    int total_sorties;
} Parking;

void init_parking(Parking* p);
int ajouter_vehicle(Parking* p, Vehicle v);
int supprimer_vehicle(Parking* p, int id);
int sortie_vehicle(Parking* p, int id, int heure_sortie);
Vehicle* rechercher_vehicle(Parking* p, char* plaque);
void modifier_vehicle(Parking* p, int id, Vehicle v);
void afficher_vehicles(Parking* p);
int places_disponibles(Parking* p);
int places_occupees(Parking* p);

#endif
