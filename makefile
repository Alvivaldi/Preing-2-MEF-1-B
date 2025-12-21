all: exec

# Fichiers objets
main.o: main.c  AVLA.h fichier.h histogramme.h
	gcc -c main.c -o main.o


AVLA.o: AVLA.c AVLA.h 
	gcc -c AVLA.c -o AVLA.o

fichier.o: fichier.c fichier.h 
	gcc -c fichier.c -o fichier.o

histogramme.o: histogramme.c histogramme.h  fichier.h 
	gcc -c histogramme.c -o histogramme.o


# Exécutable
exec: main.o AVLA.o fichier.o histogramme.o 
	gcc main.o AVLA.o fichier.o histogramme.o  -o exec

# Nettoyage
clean:
	rm -f *.o
	rm -f exec
