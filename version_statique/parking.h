#ifndef PARKING_H
#define PARKING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "vehicule.h"

#define MAX_PLACES 50
#define MAX_VEHICLES 100

typedef struct {
    Vehicule vehicules[MAX_VEHICLES];
    int nombre_vehicules;
    int places_occupees;
    float revenu_total;
    int total_entrees;
    int total_sorties;
} Parking;

void initialiser_parking(Parking *parking);
int ajouter_vehicule(Parking *parking, char *plaque, char *marque, char *couleur, float tarif);
int supprimer_vehicule(Parking *parking, char *plaque);
Vehicule* rechercher_vehicule(Parking *parking, char *plaque);
void afficher_vehicules_presents(Parking *parking);
int enregistrer_sortie(Parking *parking, char *plaque);
void afficher_places_disponibles(Parking *parking);
void afficher_revenu_total(Parking *parking);
void afficher_menu_principal();
void afficher_menu_vehicules();

#endif
