#!/bin/bash
set -e

# Mesure du temps
START=$(date +%s)


#Verification de la compilation make 
if [ ! -f "./wildwater" ]; then
    make
    if [ $? -ne 0 ]; then
        echo "Erreur : la compilation a échoué !"
        exit 1
    fi
fi

# Appel programme C
./wildwater "$FILE_CSV" histo
RET=$?
if [ $RET -ne 0 ]; then
    echo "Erreur dans l'exécution du programme C !"
    exit 1
fi


# Affichage du temps total
END=$(date +%s)
DURATION=$((END - START))

echo "Durée totale du script : ${DURATION} secondes"
