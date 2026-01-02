#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parking.h"

void init_parking(Parking* p) {
    p->head = NULL;
    p->nb_vehicles = 0;
    p->capacite_max = MAX_PLACES;
    p->montant_total = 0.0;
    p->total_entrees = 0;
    p->total_sorties = 0;
}

int ajouter_vehicle(Parking* p, Vehicle* v) {
    if (places_occupees(p) >= p->capacite_max) {
        return 0;
    }
    v->statut = 1;
    v->next = p->head;
    p->head = v;
    p->nb_vehicles++;
    p->total_entrees++;
    return 1;
}

int supprimer_vehicle(Parking* p, int id) {
    Vehicle* current = p->head;
    Vehicle* prev = NULL;
    
    while (current != NULL) {
        if (current->id == id) {
            if (prev == NULL) {
                p->head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            p->nb_vehicles--;
            return 1;
        }
        prev = current;
        current = current->next;
    }
    return 0;
}

int sortie_vehicle(Parking* p, int id, int heure_sortie) {
    Vehicle* current = p->head;
    
    while (current != NULL) {
        if (current->id == id && current->statut == 1) {
            int duree = heure_sortie - current->heure_arrivee;
            if (duree < 0) duree = 0;
            float montant = duree * current->tarif_horaire;
            p->montant_total += montant;
            current->statut = 0;
            p->total_sorties++;
            printf("\nMontant a payer: %.2f euros\n", montant);
            printf("Duree de stationnement: %d heures\n", duree);
            return 1;
        }
        current = current->next;
    }
    return 0;
}

Vehicle* rechercher_vehicle(Parking* p, char* plaque) {
    Vehicle* current = p->head;
    
    while (current != NULL) {
        if (strcmp(current->plaque, plaque) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void modifier_vehicle(Parking* p, int id, Vehicle* v) {
    Vehicle* current = p->head;
    
    while (current != NULL) {
        if (current->id == id) {
            strcpy(current->plaque, v->plaque);
            strcpy(current->marque, v->marque);
            strcpy(current->couleur, v->couleur);
            current->heure_arrivee = v->heure_arrivee;
            current->tarif_horaire = v->tarif_horaire;
            current->statut = v->statut;
            break;
        }
        current = current->next;
    }
}

void afficher_vehicles(Parking* p) {
    Vehicle* current = p->head;
    
    printf("\n=== Liste des vehicules ===\n");
    printf("%-5s %-15s %-15s %-15s %-10s %-10s %-10s\n", 
           "ID", "Plaque", "Marque", "Couleur", "Arrivee", "Tarif/h", "Statut");
    printf("--------------------------------------------------------------------------------\n");
    
    while (current != NULL) {
        if (current->statut == 1) {
            printf("%-5d %-15s %-15s %-15s %-10d %-10.2f %-10s\n",
                   current->id,
                   current->plaque,
                   current->marque,
                   current->couleur,
                   current->heure_arrivee,
                   current->tarif_horaire,
                   "Present");
        }
        current = current->next;
    }
}

int places_disponibles(Parking* p) {
    return p->capacite_max - places_occupees(p);
}

int places_occupees(Parking* p) {
    int count = 0;
    Vehicle* current = p->head;
    
    while (current != NULL) {
        if (current->statut == 1) {
            count++;
        }
        current = current->next;
    }
    return count;
}

void free_parking(Parking* p) {
    Vehicle* current = p->head;
    Vehicle* next;
    
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    p->head = NULL;
    p->nb_vehicles = 0;
}
