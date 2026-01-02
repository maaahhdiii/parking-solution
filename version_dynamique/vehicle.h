#ifndef VEHICLE_H
#define VEHICLE_H

#define MAX_STRING 50

typedef struct Vehicle {
    int id;
    char plaque[MAX_STRING];
    char marque[MAX_STRING];
    char couleur[MAX_STRING];
    int heure_arrivee;
    float tarif_horaire;
    int statut;
    struct Vehicle* next;
} Vehicle;

#endif
