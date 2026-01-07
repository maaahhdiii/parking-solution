#ifndef VEHICULE_H
#define VEHICULE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_STRING 100

typedef struct Vehicule {
    int id;
    char plaque[MAX_STRING];
    char marque[MAX_STRING];
    char couleur[MAX_STRING];
    time_t heure_arrivee;
    float tarif_horaire;
    int statut;
    struct Vehicule *suivant;
} Vehicule;

void afficher_vehicule(Vehicule *v);
float calculer_montant(Vehicule *v);

#endif

