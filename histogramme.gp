set terminal png size 1200,600
set datafile separator ";"

set output FICHIER_SORTIE

# Style histogramme
set style data histograms
set style fill solid 1.0 border -1   # Rempli complètement avec bordure automatique
set boxwidth 0.8
set xtics rotate by -45

#légende
set xlabel "Usines"
set ylabel "Volume (k.m3 / an)"

# Titre du graphique
set title TITRE_GRAPHIQUE

# Tracé de l'histogramme
plot FICHIER_DATA using 2:xtic(1) title ""