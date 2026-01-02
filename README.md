# 🚗 Système de Gestion de Parking en C

Application complète de gestion de parking développée en langage C, avec deux implémentations distinctes : version statique (tableaux) et version dynamique (listes chaînées).

## 📋 Table des matières

- [Aperçu](#aperçu)
- [Fonctionnalités](#fonctionnalités)
- [Structure du projet](#structure-du-projet)
- [Compilation et exécution](#compilation-et-exécution)
- [Utilisation](#utilisation)
- [Caractéristiques techniques](#caractéristiques-techniques)

## 🎯 Aperçu

Ce projet implémente un système complet de gestion de parking permettant de :
- Gérer les entrées et sorties de véhicules
- Calculer automatiquement les montants à payer
- Suivre les statistiques du parking en temps réel
- Administrer jusqu'à 50 places de stationnement

## ✨ Fonctionnalités

### Gestion des véhicules
- ➕ **Ajouter un véhicule** : Enregistrement d'un nouveau véhicule avec ses caractéristiques
- ❌ **Supprimer un véhicule** : Suppression d'un enregistrement
- 🔍 **Rechercher un véhicule** : Recherche par plaque d'immatriculation
- 📋 **Afficher tous les véhicules** : Liste complète des véhicules présents
- 🚪 **Enregistrer une sortie** : Calcul automatique du montant à payer basé sur la durée et le tarif horaire
- ✏️ **Modifier un véhicule** : Mise à jour des informations

### Statistiques
- 📊 Capacité totale du parking
- 🟢 Nombre de places disponibles
- 🔴 Nombre de places occupées
- 📈 Total des véhicules entrés et sortis
- 📉 Taux d'occupation moyen
- 💰 Revenu total collecté

### Informations véhicule
Chaque véhicule est caractérisé par :
- `ID` - Identifiant unique
- `Plaque` - Numéro d'immatriculation
- `Marque` - Marque du véhicule
- `Couleur` - Couleur du véhicule
- `Heure d'arrivée` - Heure d'entrée au parking
- `Tarif horaire` - Tarif de stationnement par heure
- `Statut` - Présent ou sorti

## 📁 Structure du projet

```
parking-solution/
│
├── version_statique/          # Version avec tableaux
│   ├── vehicle.h             # Structure Vehicle
│   ├── parking.h             # Interface module parking
│   ├── parking.c             # Implémentation parking (tableaux)
│   ├── statistics.h          # Interface module statistiques
│   ├── statistics.c          # Implémentation statistiques
│   ├── main.c                # Programme principal
│   └── parking.cbp           # Projet Code::Blocks
│
├── version_dynamique/         # Version avec listes chaînées
│   ├── vehicle.h             # Structure Vehicle avec pointeur next
│   ├── parking.h             # Interface module parking
│   ├── parking.c             # Implémentation parking (listes chaînées)
│   ├── statistics.h          # Interface module statistiques
│   ├── statistics.c          # Implémentation statistiques
│   ├── main.c                # Programme principal
│   └── parking.cbp           # Projet Code::Blocks
│
└── README.md                  # Documentation
```

## 🛠️ Compilation et exécution

### Avec Code::Blocks (Recommandé)

1. Ouvrez Code::Blocks
2. `File` → `Open` → Sélectionnez `parking.cbp` dans le dossier voulu
3. `Build` → `Build` (F9)
4. `Build` → `Run` (Ctrl+F10)

### Compilation manuelle

```bash
cd version_statique
gcc -Wall -Wextra -std=c99 -o parking.exe main.c parking.c statistics.c
./parking.exe
```

ou

```bash
cd version_dynamique
gcc -Wall -Wextra -std=c99 -o parking.exe main.c parking.c statistics.c
./parking.exe
```

## 💻 Utilisation

### Menu principal
```
=================================
   GESTION DE PARKING
=================================
1. Gestion des vehicules
2. Statistiques
3. Quitter
```

### Menu gestion des véhicules
```
=== Gestion des vehicules ===
1. Ajouter un vehicule
2. Supprimer un vehicule
3. Rechercher un vehicule
4. Afficher tous les vehicules
5. Enregistrer une sortie
6. Modifier un vehicule
7. Retour au menu principal
```

### Exemple d'utilisation

1. **Ajouter un véhicule**
   - Saisir l'ID, la plaque, la marque, la couleur
   - Indiquer l'heure d'arrivée et le tarif horaire

2. **Enregistrer une sortie**
   - Saisir l'ID du véhicule
   - Indiquer l'heure de sortie
   - Le système calcule automatiquement le montant à payer

3. **Consulter les statistiques**
   - Voir l'occupation en temps réel
   - Suivre les revenus générés

## 🔧 Caractéristiques techniques

### Version Statique
- **Structure de données** : Tableaux fixes
- **Capacité** : 50 places (MAX_PLACES)
- **Allocation mémoire** : Statique
- **Algorithme de recherche** : Recherche linéaire
- **Complexité recherche** : O(n)

### Version Dynamique
- **Structure de données** : Listes chaînées
- **Capacité** : 50 places (MAX_PLACES)
- **Allocation mémoire** : Dynamique avec `malloc()`
- **Libération mémoire** : Avec `free()`
- **Insertion** : En tête de liste
- **Complexité recherche** : O(n)

### Compilation
- **Standard** : C99
- **Options** : `-Wall -Wextra` (tous les avertissements)
- **Compilateur** : GCC compatible

## 📝 Architecture modulaire

Le code est organisé en modules séparés pour une meilleure maintenabilité :

- **vehicle.h** : Définition de la structure Vehicle
- **parking.h/.c** : Gestion du parking (ajout, suppression, recherche)
- **statistics.h/.c** : Calcul et affichage des statistiques
- **main.c** : Interface utilisateur et menus

## 🎓 Projet académique

Ce projet a été développé dans le cadre d'un exercice de programmation en C, démontrant :
- La maîtrise des structures de données
- L'utilisation des pointeurs
- La gestion de la mémoire dynamique
- La programmation modulaire
- Les bonnes pratiques de développement
