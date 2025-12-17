
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

typedef struct Node {
    char id[MAX];
    int fuite;
    int volume;
    struct enfant* enfants;
}Node;

typedef struct enfants {
    struct Node* node;
    struct enfant* suivant;
}enfant;

typedef struct AVLNode {
    char id[MAX];
    Node* noeud;
    int hauteur;
    struct AVLNode* fg;
    struct AVLNode* fd;
} AVLNode;