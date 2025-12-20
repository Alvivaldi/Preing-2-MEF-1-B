set terminal png size 1200,600
set output fichier_sortie
set datafile separator ";"

# Style histogramme
set style data histograms
set style fill solid 1.0 border -1   # Rempli complètement avec bordure automatique
set boxwidth 0.8
set xtics rotate by -45

#légende
set xlabel "Usines"
set ylabel "Volume (k.m3 / an)"

# Titre du graphique
set title titre_graphique

# Tracé de l'histogramme
plot fichier_data using 2:xtic(1) title ""
