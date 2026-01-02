#include <stdio.h>
#include <string.h>
#include "parking.h"

void init_parking(Parking* p) {
    p->nb_vehicles = 0;
    p->capacite_max = MAX_PLACES;
    p->montant_total = 0.0;
    p->total_entrees = 0;
    p->total_sorties = 0;
}

int ajouter_vehicle(Parking* p, Vehicle v) {
    if (p->nb_vehicles >= p->capacite_max) {
        return 0;
    }
    v.statut = 1;
    p->vehicles[p->nb_vehicles] = v;
    p->nb_vehicles++;
    p->total_entrees++;
    return 1;
}

int supprimer_vehicle(Parking* p, int id) {
    int i, j;
    for (i = 0; i < p->nb_vehicles; i++) {
        if (p->vehicles[i].id == id) {
            for (j = i; j < p->nb_vehicles - 1; j++) {
                p->vehicles[j] = p->vehicles[j + 1];
            }
            p->nb_vehicles--;
            return 1;
        }
    }
    return 0;
}

int sortie_vehicle(Parking* p, int id, int heure_sortie) {
    int i;
    for (i = 0; i < p->nb_vehicles; i++) {
        if (p->vehicles[i].id == id && p->vehicles[i].statut == 1) {
            int duree = heure_sortie - p->vehicles[i].heure_arrivee;
            if (duree < 0) duree = 0;
            float montant = duree * p->vehicles[i].tarif_horaire;
            p->montant_total += montant;
            p->vehicles[i].statut = 0;
            p->total_sorties++;
            printf("\nMontant a payer: %.2f euros\n", montant);
            printf("Duree de stationnement: %d heures\n", duree);
            return 1;
        }
    }
    return 0;
}

Vehicle* rechercher_vehicle(Parking* p, char* plaque) {
    int i;
    for (i = 0; i < p->nb_vehicles; i++) {
        if (strcmp(p->vehicles[i].plaque, plaque) == 0) {
            return &p->vehicles[i];
        }
    }
    return NULL;
}

void modifier_vehicle(Parking* p, int id, Vehicle v) {
    int i;
    for (i = 0; i < p->nb_vehicles; i++) {
        if (p->vehicles[i].id == id) {
            v.id = id;
            p->vehicles[i] = v;
            break;
        }
    }
}

void afficher_vehicles(Parking* p) {
    int i;
    printf("\n=== Liste des vehicules ===\n");
    printf("%-5s %-15s %-15s %-15s %-10s %-10s %-10s\n", 
           "ID", "Plaque", "Marque", "Couleur", "Arrivee", "Tarif/h", "Statut");
    printf("--------------------------------------------------------------------------------\n");
    for (i = 0; i < p->nb_vehicles; i++) {
        if (p->vehicles[i].statut == 1) {
            printf("%-5d %-15s %-15s %-15s %-10d %-10.2f %-10s\n",
                   p->vehicles[i].id,
                   p->vehicles[i].plaque,
                   p->vehicles[i].marque,
                   p->vehicles[i].couleur,
                   p->vehicles[i].heure_arrivee,
                   p->vehicles[i].tarif_horaire,
                   "Present");
        }
    }
}

int places_disponibles(Parking* p) {
    int occupees = 0;
    int i;
    for (i = 0; i < p->nb_vehicles; i++) {
        if (p->vehicles[i].statut == 1) {
            occupees++;
        }
    }
    return p->capacite_max - occupees;
}

int places_occupees(Parking* p) {
    int occupees = 0;
    int i;
    for (i = 0; i < p->nb_vehicles; i++) {
        if (p->vehicles[i].statut == 1) {
            occupees++;
        }
    }
    return occupees;
}
