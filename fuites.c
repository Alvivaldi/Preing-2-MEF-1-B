void fichier_pertes(char* id, float pertes){
    FILE* f=fopen("rendements.dat","a");
    if (f==NULL){
        exit(1);
    }
    fprintf(f,"%s;%lf\n",id,pertes);
    fclose(f);
}
