typedef struct arbre{
    int id;
    float vol;
    struct arbre* fg;
    struct arbre* fd;
    int eq;
}Arbre;

