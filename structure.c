#define MAX 100
typedef struct avl{
    int id;
    float vol;
    struct arbre* fg;
    struct arbre* fd;
    int eq;
}AVL;

typedef struct usine{
    char id[MAX];
    int capacite_max;       
    int volume_total; 
    struct Usine *fg;
    struct Usine *fd;
} Usine;
