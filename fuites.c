void fichier_pertes(char* id, float pertes){
    FILE* f=fopen("rendements.dat","a");
    if (f==NULL){
        exit(1);
    }
    fprintf(f,"%s;%lf\n",id,pertes);
    fclose(f);
}


void generer_fichiers_histogramme(AVL a){
    FILE *Fmax  = fopen("vol_max.dat", "w");
    FILE *Fcapt  = fopen("vol_captation.dat", "w");
    FILE *Freel = fopen("vol_traitement.dat", "w");
    if(Fmax == NULL || Fcapt == NULL || Freel == NULL){
        printf("erreur ouverture fichiers histogramme");
        exit(1);
    }
    fprintf(Fmax,  "id;volume_max\n");
    fprintf(Fcapt,  "id;volume_captation\n");
    fprintf(Freel, "id;volume_traitement\n");
    remplir_fichiers(a, Fmax, Fcapt, Freel);
    fclose(Fmax);
    fclose(Fcapt);
    fclose(Freel);
}