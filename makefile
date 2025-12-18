all: exec

# Fichiers objets
main.o: main.c AVL.h AVLA.h fichier.h histogramme.h
	gcc -c main.c -o main.o

AVL.o: AVL.c AVL.h
	gcc -c AVL.c -o AVL.o

AVLA.o: AVLA.c AVLA.h AVL.h
	gcc -c AVLA.c -o AVLA.o

fichier.o: fichier.c fichier.h AVL.h
	gcc -c fichier.c -o fichier.o

histogramme.o: histogramme.c histogramme.h AVL.h fichier.h 
	gcc -c histogramme.c -o histogramme.o


# Exécutable
exec: main.o AVL.o AVLA.o fichier.o histogramme.o 
	gcc main.o AVL.o AVLA.o fichier.o histogramme.o  -o exec

# Nettoyage
clean:
	rm -f *.o
	rm -f exec
