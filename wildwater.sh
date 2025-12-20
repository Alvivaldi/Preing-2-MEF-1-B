#!/bin/bash
set -e

# Mesure du temps
START=$(date +%s)

# Affichage du temps total
END=$(date +%s)
DURATION=$((END - START))

echo "Durée totale du script : ${DURATION} secondes"
