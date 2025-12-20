#!/bin/bash



# Vérification des arguments
if [ $# -ne 3 ]; then
    echo "Usage : <fichier_CSV> histo <max|src|real>"
    echo "Erreur dans le nombre d'arguments"
    exit 1
fi



# Récupération des arguments
FICHIERS_DATA="$1"
COMMAND="$2"
TYPE="$3"



# Compilation du programme C
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



# Création sous-fichiers temporaires pour les 50 plus petites usines 
# enlève l'en-tête
tail -n +2 "$FICHIER_DONNEE" | head -n 50 > petites_usines.dat

# Création sous-fichiers temporaires pour 10 plus grandes usines
tail -n 10 "$FICHIER_DONNEE" > grandes_usines.dat



# Génération des histogrammes
echo "Génération des histogrammes PNG"

gnuplot \
  -e "FICHIER_DATA='petites_usines.dat'" \
  -e "FICHIER_SORTIE='${FICHIER_NOM}_petite.png'" \
  -e "TITRE_GRAPHIQUE='50 plus petites usines - $TITRE'" \
  histo.gp

gnuplot \
  -e "FICHIER_DATA='grandes_usines.dat'" \
  -e "FICHIER_SORTIE='${FICHIER_NOM}_grandes.png'" \
  -e "TITRE_GRAPHIQUE='10 plus grandes usines - $TITRE'" \
  histo.gp



#Suppression fichiers temporaires
rm -f petites_usines.dat grandes_usines.dat