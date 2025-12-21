# PROJET C-WildWater
<img src="./wildwater.png" alt="wildwater" width="400"/>


##  Table des matières


- [Introduction](#Introduction)
- [Pré-requis](#Pré-requis)
- [Guide d'utilisation](#Guide-d'utilisation)
- [Structure du Projet](#Structure-du-projet)
- [Auteurs](#Auteurs)

## Introduction 📝
  L'objectif de ce projet est de modéliser un réseau de distribution d'eau en analysant le parcours de l'eau, de sa captation jusqu'à la consommation finale.
  
## Pré-requis
  - Make

## Guide d'utilisation 📔 

Une fois dans le repertoire du projet : 
```bash
### Compilez le projet
make
```
// bon j'attend votre parti sur ce que la prof doit faire 

## Structure du projet 

```bash
AVLA.h / AVLA.c
```: Contient les structures Usine et AVL_fuites ainsi que toutes les fonctions de rotation et d'équilibrage.

fuites.h / fuites.c : Gère le calcul des fuites du réseau. Contient la structure Chainon,la fonction creerChainon, ajouterFils et le calcul récursif calculer_pertes.

fichier.h / fichier.c : Gère les entrées/sorties. Contient decoupe et les deux fonctions de lecture (lireCSV pour les usines et lireCSV_leaks pour le réseau).

histogramme.h / histogramme.c : Gère la génération des fichiers .dat pour les graphiques.

main.c : Lit les arguments (argc, argv) pour savoir quel mode lancer.


AVLA.h / AVLA.c
```: Contient les structures Usine et AVL_fuites ainsi que toutes les fonctions de rotation et d'équilibrage.

fuites.h / fuites.c : Gère le calcul des fuites du réseau. Contient la structure Chainon,la fonction creerChainon, ajouterFils et le calcul récursif calculer_pertes.

fichier.h / fichier.c : Gère les entrées/sorties. Contient decoupe et les deux fonctions de lecture (lireCSV pour les usines et lireCSV_leaks pour le réseau).

histogramme.h / histogramme.c : Gère la génération des fichiers .dat pour les graphiques.

main.c : Lit les arguments (argc, argv) pour savoir quel mode lancer.

pertes.h : contient les prototypes des fonctions de calcul du rendement et de l’historique de ces calculs.

arbre.c : construit l’arbre de fuites à partir du fichier de données.

avl.c : implémente les opérations sur les arbres AVL (insertions, rotations, équilibrage).

lecture_ligne.c : analyse et stocke les lignes du fichier de données et leur type.

histogramme.c : parcourt l’AVL, calcule les volumes par usine et génère les fichiers .dat pour les histogrammes.

pertes.c : calcule les pertes d’eau récursivement dans le réseau et les écrit dans l’historique.

main.c : point d’entrée du programme, gère les arguments et appelle les fonctionnalités principales.

makefile : permet de compiler rapidement le projet.

script.sh : script Bash facilitant l’exécution du programme et la génération des histogrammes.

histo.gp : script gnuplot pour produire les histogrammes à partir des fichiers .dat.




## Auteurs 👤  
👤 LAMBERT Alexis

👤 KALIAMOORTHY Lasugaa

👤 NJANKOU NANA Charmelle
