#define MAX 100
typedef struct arbre{
    int id;
    float vol;
    struct arbre* fg;
    struct arbre* fd;
    int eq;
}Arbre;

typedef struct usine{
    char id[MAX];
    int capacite_max;       
    int volume_total; 
    struct Usine *fg;
    struct Usine *fd;
} Usine;
