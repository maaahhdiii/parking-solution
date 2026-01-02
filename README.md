# GESTION DE PARKING EN C

## Structure du projet

Le projet contient deux versions distinctes:

### Version Statique (Tableaux)
- `version_statique/vehicle.h` - Definitions de structure Vehicle
- `version_statique/parking.h` - Interface du module parking
- `version_statique/parking.c` - Implementation du module parking
- `version_statique/statistics.h` - Interface du module statistiques
- `version_statique/statistics.c` - Implementation du module statistiques
- `version_statique/main.c` - Programme principal avec menus
- `version_statique/Makefile` - Fichier de compilation
- `version_statique/compile.bat` - Script de compilation Windows

### Version Dynamique (Listes chainees)
- `version_dynamique/vehicle.h` - Definitions de structure Vehicle avec pointeur next
- `version_dynamique/parking.h` - Interface du module parking
- `version_dynamique/parking.c` - Implementation avec listes chainees
- `version_dynamique/statistics.h` - Interface du module statistiques
- `version_dynamique/statistics.c` - Implementation du module statistiques
- `version_dynamique/main.c` - Programme principal avec menus
- `version_dynamique/Makefile` - Fichier de compilation
- `version_dynamique/compile.bat` - Script de compilation Windows

## Compilation

### Avec Make
```
cd version_statique
make
```
ou
```
cd version_dynamique
make
```

### Avec script batch (Windows)
```
cd version_statique
compile.bat
```
ou
```
cd version_dynamique
compile.bat
```

### Compilation manuelle
```
gcc -Wall -Wextra -std=c99 -o parking.exe main.c parking.c statistics.c
```

## Execution

```
./parking.exe
```

## Fonctionnalites

### Menu Principal
1. Gestion des vehicules
2. Statistiques
3. Quitter

### Gestion des vehicules
1. Ajouter un vehicule
2. Supprimer un vehicule
3. Rechercher un vehicule
4. Afficher tous les vehicules
5. Enregistrer une sortie
6. Modifier un vehicule
7. Retour au menu principal

### Statistiques
- Capacite totale
- Places occupees et disponibles
- Total vehicules entres et sortis
- Taux d'occupation moyen
- Revenu total collecte

## Caracteristiques techniques

### Version Statique
- Utilise des tableaux fixes (MAX_PLACES = 50)
- Allocation memoire statique
- Recherche lineaire dans le tableau

### Version Dynamique
- Utilise des listes chainees
- Allocation memoire dynamique avec malloc
- Liberation memoire avec free
- Insertion en tete de liste
