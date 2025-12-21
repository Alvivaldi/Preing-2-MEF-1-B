#!/bin/bash

START_TIME=$(date +%s%3N)


if [ $# -lt 2 ] || [ $# -gt 3 ]; then
    echo "Erreur : nombre d'arguments invalide"
    exit 1
fi

DATA_FILE="$1"
MODE="$2"
OPTION="$3"

if [ ! -f "$DATA_FILE" ]; then
    echo "Erreur : fichier de données introuvable"
    exit 1
fi


# Compilation si nécessaire

EXEC="./exec"

if [ ! -x "$EXEC" ]; then
    echo "Compilation du programme C..."
    make
    if [ $? -ne 0 ]; then
        echo "Erreur : compilation échouée"
        exit 1
    fi
fi


case "$MODE" in

    histo)
        if [ $# -ne 3 ]; then
            echo "Erreur : histo nécessite un type (max | src | real)"
            exit 1
        fi

        if [[ "$OPTION" != "max" && "$OPTION" != "src" && "$OPTION" != "real" ]]; then
            echo "Erreur : type histo invalide"
            exit 1
        fi

        "$EXEC" "$DATA_FILE" histo "$OPTION"
        if [ $? -ne 0 ]; then
            echo "Erreur : programme C en échec"
            exit 1
        fi

        case "$OPTION" in
            max)
                FILE="vol_max.dat"
                ;;
            src)
                FILE="vol_captation.dat"
                ;;
            real)
                FILE="vol_traitement.dat"
                ;;
        esac
        ;;

    leaks)
        if [ $# -ne 3 ]; then
            echo "Erreur : leaks nécessite un identifiant d'usine"
            exit 1
        fi

        "$EXEC" "$DATA_FILE" leaks "$OPTION"
        if [ $? -ne 0 ]; then
            echo "Erreur : programme C en échec"
            exit 1
        fi

        FILE="leaks.dat"
        ;;

    *)
        echo "Erreur : mode invalide (histo | leaks)"
        exit 1
        ;;
esac


# Graphiques

if [ "$MODE" = "histo" ]; then
    mkdir -p images

    tail -n +2 "$FILE" | sort -t';' -k2 -n | head -n 50 > small.dat
    tail -n +2 "$FILE" | sort -t';' -k2 -n | tail -n 10 > big.dat

    gnuplot << EOF
set datafile separator ";"
set terminal png size 1200,600
set output "images/${OPTION}_small.png"
set title "50 plus petites usines - ${OPTION}"
set style data histograms
set style fill solid
set boxwidth 0.8
set xtics rotate by -45
plot "small.dat" using 2:xtic(1) notitle
EOF

    gnuplot << EOF
set datafile separator ";"
set terminal png size 1200,600
set output "images/${OPTION}_big.png"
set title "10 plus grandes usines - ${OPTION}"
set style data histograms
set style fill solid
set boxwidth 0.8
set xtics rotate by -45
plot "big.dat" using 2:xtic(1) notitle
EOF

    rm -f small.dat big.dat
fi


# Temps total

END_TIME=$(date +%s%3N)
echo "Durée totale : $((END_TIME - START_TIME)) ms"
