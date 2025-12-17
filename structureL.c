
#define MAX 100

typedef struct arbre{
    char id[MAX];
    int capacite_max;       
    int volume_total; 
    int volume_reel;
    int hauteur;
    struct arbre* fg;
    struct arbre* fd;
    int equilibre;
}AVL;

typedef struct Noeud {
    char id[MAX];
    int fuite;
    int volume;
    struct enfant* enfants;
}Noeud;

typedef struct enfants {
    struct Noeud* noeud;
    struct enfant* suivant;
}enfant;

typedef struct AVLNoeud {
    char id[MAX];
    Node* noeud;
    int hauteur;
    struct AVLNoeud* fg;
    struct AVLNoeud* fd;
} AVLNoeud;