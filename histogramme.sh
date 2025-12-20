#!/bin/bash

# Vérification des arguments
if [ $# -ne 3 ]; then
    echo "Erreur : trop d’arguments"
    exit 1
fi

# Récupération des arguments
FICHIERS_DATA="$1"
COMMAND="$2"
TYPE="$3"

# Compilation du programme C si nécessaire
EXEC="./wildwater"

if [ ! -f "$EXEC" ]; then
    echo "Compilation du programme C"
    make
fi

# Choix du type d'histogramme
case "$TYPE" in

    max)
        FICHIER_DONNEE="vol_max.dat"
        FICHIER_NOM="vol_max"
        TITRE_GRAPH="Capacité maximale des usines"
        ;;


    src)
        FICHIER_DONNEE="vol_captation.dat"
        FICHIER_NOM="vol_captation"
        TITRE_GRAPH="Volume total capté par les usines"
        ;;


    reel)
        FICHIER_DONNEE="vol_traitement.dat"
        FICHIER_NOM="vol_traitement"
        TITRE_GRAPH="Volume réellement traité par les usines"
        ;;


    *)
        echo "Type d'histogramme invalide (max/src/reel) : $TYPE"
        exit 1
        ;;
esac