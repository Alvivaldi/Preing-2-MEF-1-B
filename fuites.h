#define MAX 100

typedef struct Chainon {
    char id[MAX];
    double fuites;           
    struct Chainon* fils;    
    struct Chainon* suivant; 
} Chainon;
