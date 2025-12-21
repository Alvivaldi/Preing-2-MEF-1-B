#!/bin/bash


# Vérification de l'argument
if [ $# -ne 1 ]; then
    echo "Usage: $0 vol_max | vol_captation | vol_traitement"
    exit 1
fi


CHOIX=$1
DATA_FILE="${CHOIX}.dat"

# dossier images dans le projet (portable)
IMG_DIR="images"
mkdir -p "$IMG_DIR"


# Sélection des données (50 plus petites et 10 plus grandes)
tail -n +2 "$DATA_FILE" | sort -t';' -k2 -n | head -n 50 > small.dat
tail -n +2 "$DATA_FILE" | sort -t';' -k2 -n | tail -n 10 > big.dat


# Histogramme 50 plus petites
gnuplot << EOF
set datafile separator ";"
set terminal png size 1200,600
set output '${IMG_DIR}/${CHOIX}_small.png'
set title '50 plus petites usines - ${CHOIX}'
set ylabel 'Volume (millions de m³)'
set style data histograms
set style fill solid
set boxwidth 0.8
set xtics rotate by -45
plot 'small.dat' using 2:xtic(1) title ''
EOF


# Histogramme 10 plus grandes
gnuplot << EOF
set datafile separator ";"
set terminal png size 1200,600
set output '${IMG_DIR}/${CHOIX}_big.png'
set title '10 plus grandes usines - ${CHOIX}'
set ylabel 'Volume (millions de m³)'
set style data histograms
set style fill solid
set boxwidth 0.8
set xtics rotate by -45
plot 'big.dat' using 2:xtic(1) title ''
EOF


# Nettoyage
rm -f small.dat big.dat


echo "Images générées dans le dossier images/"



