#!/bin/bash
set -e

# Mesure du temps
START=$(date +%s)

# Affichage du temps total
END=$(date +%s)
DURATION=$((END - START))

echo "Durée totale du script : ${DURATION} secondes"

#Verification de la compilation make 
if [ ! -f "./wildwater" ]; then
    RET=$?
    make
    if [ $RET -ne 0 ]; then
        echo "Erreur : le programme C a échoué"
        exit 1
    fi
fi

# Génération des fichiers .dat
echo "Génération des fichiers de données..."
./wildwater "$FICHIER_CSV" histo
if [ $? -ne 0 ]; then
    echo "Erreur lors de l'exécution du programme C"
    exit 1
fi
